# ft_irc

## Project Overview

Welcome to **ft_irc**! This project is a custom Internet Relay Chat (IRC) server written in C++98. It allows multiple clients to connect to the server, participate in channels, and send messages to each other. It is built using non-blocking I/O and multiplexing via the `poll()` system call, allowing the server to handle multiple connections within a single thread.

This README is designed to help you understand the architecture, program flow, and the purpose of every major component and function so you can comfortably explain the project to others.

---

## 🧠 Core Networking Concepts Explained

To truly understand and explain this server, you need to understand the fundamental network concepts it is built upon:

### 1. Sockets (`socket()`)
A **socket** is an endpoint for communication between two machines over a network. Think of it like a phone. When the server starts, it creates a "listen" socket (buying a phone). When a client connects, the server creates a new, distinct "connection" socket specifically for that client (a dedicated line just for that conversation), so the main "listen" socket is free to wait for more incoming calls. In C++, sockets are represented as regular integers called File Descriptors (FDs).

### 2. Bind and Listen (`bind()`, `listen()`)
- **`bind()`**: Assigns a specific local address and port (like `6667`) to the server's listen socket. It's like giving your phone a specific phone number so clients know where to dial.
- **`listen()`**: Tells the OS that this socket will be used to accept incoming connection requests. It also sets up a queue for incoming connections in case multiple clients connect at the exact same millisecond.

### 3. Multiplexing with `poll()`
Normally, if a server calls `recv()` (to read data) on a client's socket and the client hasn't sent anything, the server will block (freeze) and wait forever until data arrives. This prevents the server from talking to any other clients.
To bypass this, we use **Multiplexing**.
**`poll()`** is a system call that monitors multiple file descriptors (sockets) simultaneously to see if any of them are ready for I/O (ready to be read from, or ready to be written to).
The server gives `poll()` an array of all its sockets (the main listen socket + all client sockets). `poll()` sleeps and only wakes up the program when at least one socket has an event (e.g., a new client is connecting, or an existing client sent a message). This allows a single-threaded server to efficiently handle hundreds of clients without creating a separate thread for each one.

### 4. Non-Blocking I/O (`fcntl(fd, F_SETFL, O_NONBLOCK)`)
Even with `poll()`, we must set our sockets to **non-blocking** mode. If a socket is non-blocking, functions like `recv()` and `send()` will return immediately.
- If there is data to read, `recv()` reads it.
- If there is NO data, instead of freezing the program, `recv()` returns an error code (`EWOULDBLOCK` or `EAGAIN`), signaling "I have nothing right now, check back later."
This ensures the server's main loop never gets stuck waiting on a single slow client.

### 5. Accept, Recv, and Send
- **`accept()`**: When `poll()` says the main listen socket has activity, it means a new client is trying to connect. `accept()` answers the call, handshakes with the client, and returns a *new* socket purely for communicating with that specific client.
- **`recv()`**: Reads incoming bytes (like an IRC command) from a client's socket into our program's memory.
- **`send()`**: Writes outbound bytes (like an IRC reply or channel message) from our program back to the client's socket over the network.

---

## 🔄 Program Flow

Here is the high-level step-by-step flow of the ft_irc project:

1. **Initialization (`main.cpp`)**:
   - The program starts by checking the command-line arguments (Port and Password).
   - A `Server` object is instantiated using the provided arguments.
   - Signal handlers are set up to capture termination signals (like `Ctrl+C`) for graceful shutdown.

2. **Server Startup (`Server::start`)**:
   - Creates a socket for the server.
   - Set the socket options (reusable ports) and configures the socket to be non-blocking.
   - Binds the socket to the provided port and starts listening for incoming client connections.
   - Adds the main server socket to the `poll()` file descriptor array.

3. **The Main Loop (`Server::run`)**:
   - Enters an infinite `poll()` loop, waiting for activity on any monitored sockets (either the server socket or connected client sockets).
   - **Incoming Connections**: If the server socket has activity, it calls `_acceptClient()` to accept the connection, set it to non-blocking, and add it to the `pollfds` list and `_clients` map.
   - **Incoming Data**: If a client socket has activity, `_readClient()` is called. The data is appended to the client's internal read buffer.
   
4. **Message Processing (`Server::_processMessages`)**:
   - Once a network packet is read, the server extracts complete IRC messages ending with `\r\n`.
   - Each complete line is passed to `_handleCommand()`, which identifies the IRC command (e.g., `JOIN`, `PRIVMSG`, `NICK`) and dispatches it to the appropriate internal method (e.g., `_cmdJoin`, `_cmdPrivmsg`).

5. **Disconnection and Cleanup (`Server::cleaning`)**:
   - If a client drops the connection or sends a `QUIT` command, the server closes their socket, removes them from all channels, and removes them from the client list (`_disconnectClient()`).
   - When the server shuts down, it cleans up all dynamically allocated memory for Channels and Clients, and closes all open file descriptors.

---

## 🧩 Class Breakdown and Function Explanations

### 1. `Server` Class
The core engine of the IRC server. It handles the networking, multiplexing, and command execution.

* **Network & Flow Methods:**
  * `start()`: Initializes the server socket, binds it, and starts listening.
  * `run()`: The main `poll()` loop that multiplexes events across the server and all connected clients.
  * `cleaning()`: Gracefully closes sockets and frees allocated `Channel` and `Client` memory upon shutdown.
  * `_acceptClient()`: Accepts a new incoming TCP connection, creates a new `Client` object, and adds its socket to the `poll` event queue.
  * `_readClient()`: Reads data from a client's socket into their personal buffer. Handles client disconnections if `recv` returns 0.
  * `_disconnectClient()`: Cleans up a client's data when they disconnect and removes them from any channels they were in.

* **Message Parsing & Execution:**
  * `_processMessages()`: Extracts full messages (delimited by `\r\n`) from the client's buffer and sends them to be handled.
  * `_handleCommand()`: Parses the first word of the message to identify the command, then routes the arguments to the specific command handlers (`_cmdNick`, `_cmdJoin`, etc.).
  * `_sendReply()`: Helper to format and send numeric IRC replies (like `403 ERR_NOSUCHCHANNEL`) to the client.

* **Command Handlers:** (e.g., `_cmdPass`, `_cmdNick`, `_cmdUser`, `_cmdJoin`, `_cmdPart`, `_cmdPrivmsg`, `_cmdKick`, `_cmdInvite`, `_cmdTopic`, `_cmdMode`)
  * These execute the actual IRC specs. They validate the client's state (checking if they are authenticated with a password, have set a NICK, and USER) before letting them interact with channels.

### 2. `Client` Class
Represents a single user connected to the server.

* **Responsibilities:**
  * Holds the client's socket (`_fd`), identifying info (`_nickname`, `_username`, `_hostname`).
  * Manages the connection state (`_password` correct, `_registered` to use the server).
  * Holds a read buffer (`_readBuf`) to handle partial TCP packets so commands aren't executed until a full `\r\n` is received.
  
* **Key Methods:**
  * `appendToReadBuf()`, `clearReadBuf()`: Manages incomplete lines sent over the network.
  * `sendMessage()`: Wraps the `send()` system call to deliver strings directly to the client's socket.
  * `getPrefix()`: Returns the standard IRC user prefix layout (`nick!user@host`).

### 3. `Channel` Class
Represents a chat room that contains multiple connected clients.

* **Responsibilities:**
  * Keeps lists of normal users (`_clients`) and channel operators (`_operators`).
  * Manages channel modes (e.g., invite-only `+i`, topic restricted `+t`, key protected `+k`, user limit `+l`).
  
* **Key Methods:**
  * `addClient()`, `removeClient()`: Join/Leave logic for standard users.
  * `addOperator()`, `removeOperator()`: Grants or revokes OP privileges inside the channel.
  * `broadcast()`: Sends a text message to every single client currently in the channel. (Usually takes an `exclude` parameter so the sender doesn't receive their own message back).
  * `setMode()`, `unsetMode()`, `hasMode()`: Modifies and checks the properties of the channel.
  * `addInvite()`, `isInvited()`: Tracks users who are allowed to bypass the invite-only mode restrictions.

---

## 🚀 How to Build and Run

1. **Compile the program:**
   ```bash
   make
   ```
2. **Run the server:**
   ```bash
   ./ircserv <port> <password>
   ```
   *Example: `./ircserv 6667 mypassword`*

3. **Connect a Client:**
   You can connect to this server using an IRC client like **nc (Netcat)**, **Irssi**, or **HexChat**.
   ```bash
   nc 127.0.0.1 6667
   ```
   *(For raw netcat, you'll need to manually type `PASS mypassword`, `NICK mynick`, and `USER user 0 * :Real Name` to register).*