## 🌐 What is FastCGI? (Before anything else)

Back in the early web, when a browser requested a PHP page, the server had to:

```
Request comes in
      ↓
Spawn a NEW PHP process
      ↓
PHP process handles request
      ↓
PHP process DIES
      ↓
Next request → spawn AGAIN
```

This was called **CGI (Common Gateway Interface)** — and it was **extremely slow** because spawning a new process for every request is expensive.

**FastCGI** solved this by keeping PHP processes **alive and waiting**:

```
Request comes in
      ↓
Send to ALREADY RUNNING php-fpm process
      ↓
php-fpm handles request
      ↓
php-fpm STAYS ALIVE, waiting for next request
      ↓
Next request → same process handles it instantly
```

---

### So what is php-fpm exactly?

**php-fpm = PHP FastCGI Process Manager**

It's a program that:
- Keeps a **pool of PHP worker processes** running in the background
- Receives requests from NGINX via the **FastCGI protocol**
- Hands the request to an available worker
- Returns the result back to NGINX

```
NGINX                    php-fpm
  │                         │
  │  ──── FastCGI ────>     │
  │   "run this .php file"  │
  │                    [worker 1] executes PHP
  │                    [worker 2] waiting
  │                    [worker 3] waiting
  │  <──── response ───     │
  │   "here's the HTML"     │
```

> 💡 **Evaluator question:** *"Why doesn't NGINX run PHP itself?"*
> **Answer:** NGINX is a **web server**, not a PHP interpreter. It's designed to be fast at serving static files and routing requests. PHP execution is a completely separate job — that's why we separate them into two containers. NGINX handles HTTP/TLS, php-fpm handles PHP execution.

---

## 📄 WordPress Dockerfile — Line by Line

```dockerfile
FROM debian:bullseye
```
Same as MariaDB — Debian Bullseye as our base OS.

> ❌ **Without it:** Invalid Dockerfile, nothing builds.

---

```dockerfile
RUN apt-get update && apt-get install -y \
    php php-fpm php-mysql php-cli curl \
    && rm -rf /var/lib/apt/lists/*
```
- `php` — the core PHP interpreter
- `php-fpm` — the FastCGI Process Manager we just explained
- `php-mysql` — the PHP extension that lets PHP **talk to MySQL/MariaDB**. Without this, WordPress can't query the database at all
- `php-cli` — PHP command line interface, needed to run `wp-cli` commands in the entrypoint script
- `curl` — needed to download wp-cli from the internet during build

> ❌ **Without `php-mysql`:** WordPress connects to php-fpm fine, but the moment it tries to query MariaDB it crashes with `Call to undefined function mysqli_connect()`.

> ❌ **Without `php-fpm`:** There's no FastCGI process manager — NGINX has nothing to send PHP requests to. Every PHP page returns an error.

---

```dockerfile
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp
```
- `curl -O` — downloads the file keeping its original filename
- `wp-cli.phar` — a **PHP Archive** file, a self-contained PHP application
- `chmod +x` — makes it executable
- `mv ... /usr/local/bin/wp` — moves it to a system PATH location so we can call it simply as `wp`

**What is wp-cli?** It's a command line tool to manage WordPress without a browser — install, configure, create users, all from a script. Perfect for automated container setup.

> ❌ **Without wp-cli:** You'd have to manually configure WordPress through the browser on first run, which is impossible in an automated container setup. Your entrypoint script can't set up WordPress automatically.

---

```dockerfile
COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
```
- `www.conf` — our custom php-fpm pool configuration (explained in detail below)
- Copied to `/etc/php/7.4/fpm/pool.d/` — the directory where php-fpm looks for pool config files
- `chmod +x /entrypoint.sh` — makes our startup script executable

> ❌ **Without copying www.conf:** php-fpm uses its default config which listens on a **Unix socket** (`/run/php/php7.4-fpm.sock`) instead of a TCP port. NGINX can't reach it across containers using a socket file.

---

```dockerfile
EXPOSE 9000
ENTRYPOINT ["/entrypoint.sh"]
```
- `EXPOSE 9000` — documents that php-fpm listens on port 9000 (FastCGI default)
- `ENTRYPOINT` — runs our setup script when container starts

> ❌ **Without ENTRYPOINT:** Container starts but does nothing — WordPress never gets configured, php-fpm never starts.

---

## 📄 www.conf — Line by Line

This is the **php-fpm pool configuration**. A "pool" is a group of PHP worker processes.

```ini
[www]
```
- The name of this pool. `www` is the default name. php-fpm can have multiple pools for different sites, but we only need one.

---

```ini
user = www-data
group = www-data
```
- Defines which **system user and group** the PHP worker processes run as
- `www-data` is the standard web server user on Debian — it has limited permissions for security

> ❌ **Without it (running as root):** A security risk — if PHP code gets exploited, the attacker has root access to the container. Evaluators will ask about this.

---

```ini
listen = 0.0.0.0:9000
```
This is the **most critical line in www.conf**. Let's break it fully:

- `listen` — tells php-fpm **where to accept incoming FastCGI connections**
- `0.0.0.0` — listen on **all network interfaces**, not just localhost
- `:9000` — on port 9000

**Why `0.0.0.0` and not `127.0.0.1`?**

```
127.0.0.1 = only accept connections from THIS container
0.0.0.0   = accept connections from ANY IP, including NGINX container
```

Since NGINX is in a **separate container**, it has a different IP. If php-fpm only listens on `127.0.0.1`, NGINX's requests never reach it.

> ❌ **Without `0.0.0.0` (using 127.0.0.1):** NGINX gets `Connection refused` every time it tries to forward a PHP request. WordPress is completely unreachable. This is one of the most common bugs in Inception.

---

```ini
pm = dynamic
```
- `pm` = **Process Manager** — controls how php-fpm manages its worker processes
- `dynamic` means the number of workers **scales up and down** based on traffic

There are 3 modes:
| Mode | Behavior |
|---|---|
| `static` | Always keeps a fixed number of workers running |
| `dynamic` | Starts with a few workers, creates more under load |
| `ondemand` | Only creates workers when a request comes in |

`dynamic` is the best balance for a project like this.

> ❌ **Without `pm`:** php-fpm refuses to start — this is a required directive.

---

```ini
pm.max_children = 5
```
- The **maximum number of PHP worker processes** that can exist at the same time
- Prevents php-fpm from consuming unlimited memory under heavy traffic

> ❌ **Without it:** php-fpm refuses to start in dynamic mode — required directive.

---

```ini
pm.start_servers = 2
```
- How many worker processes to **create when php-fpm first starts**
- We start with 2 ready workers so the first requests don't have to wait

> ❌ **Without it:** php-fpm uses a default value, which may be 0 — meaning the first requests are slow while workers spin up.

---

```ini
pm.min_spare_servers = 1
pm.max_spare_servers = 3
```
- `min_spare_servers` — always keep at least **1 idle worker** ready for incoming requests
- `max_spare_servers` — never keep more than **3 idle workers** (kills extras to save memory)

> ❌ **Without these:** php-fpm refuses to start in dynamic mode — both are required.

---

## 📄 entrypoint.sh — Line by Line

```bash
#!/bin/bash
cd /var/www/html
```
- Changes directory to `/var/www/html` — the web root where WordPress files live
- This is where our `wp_data` volume is mounted

> ❌ **Without it:** All `wp` commands run in the wrong directory and fail to find or create WordPress files.

---

```bash
if [ ! -f wp-config.php ]; then
```
- Checks if `wp-config.php` **does NOT exist yet**
- `wp-config.php` is the main WordPress configuration file — if it exists, WordPress is already set up
- This prevents re-running the entire setup every time the container restarts

> ❌ **Without this check:** Every restart tries to reinstall WordPress from scratch, overwriting your data and potentially failing on an already-initialized database.

---

```bash
    wp core download --allow-root
```
- Downloads the latest WordPress core files into `/var/www/html`
- `--allow-root` — allows wp-cli to run as root user (required inside containers)

> ❌ **Without it:** No WordPress files exist — there's nothing to serve. NGINX gets only empty responses.

---

```bash
    wp config create \
        --dbname=${DB_NAME} \
        --dbuser=${DB_USER} \
        --dbpass=${DB_PASSWORD} \
        --dbhost=mariadb:3306 \
        --allow-root
```
- Creates `wp-config.php` with database connection settings
- `--dbhost=mariadb:3306` — **this is where the magic happens**: `mariadb` is the container name, which Docker resolves to the MariaDB container's IP automatically via internal DNS
- Port `3306` is MariaDB's default port

> ❌ **Without `--dbhost=mariadb`:** WordPress tries to connect to `localhost`, which is itself — no database there. Connection fails immediately.

> 💡 **Evaluator question:** *"How does `mariadb` resolve to the right IP?"*
> **Answer:** Docker has a built-in DNS server for custom networks. When containers are on the same network, Docker automatically resolves container names to their internal IPs. So `mariadb` always points to the MariaDB container, even if its IP changes.

---

```bash
    wp core install \
        --url=${DOMAIN_NAME} \
        --title="My Site" \
        --admin_user=${WP_ADMIN} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --allow-root
```
- Actually **installs WordPress** — creates all database tables and sets up the admin account
- `--url` — the domain WordPress thinks it lives at (must match your NGINX server_name)

> ❌ **Without `--url` matching NGINX's domain:** WordPress generates wrong URLs for assets and redirects — the site loads broken or redirects in an infinite loop.

---

```bash
exec php-fpm7.4 -F
```
- `exec` — replaces the shell with php-fpm, making it **PID 1**
- `php-fpm7.4` — starts the FastCGI process manager
- `-F` — runs in **foreground** mode (no daemonizing)

> ❌ **Without `-F`:** php-fpm daemonizes (goes to background) and the container thinks the main process finished — it **immediately exits**.

> ❌ **Without `exec`:** php-fpm is a child of bash. Docker signals go to bash, not php-fpm — ungraceful shutdown, possible file corruption.

---

## 🧠 Full WordPress Mental Model

```
Build time:
  Install PHP + php-fpm + extensions → Download wp-cli → Copy configs

Runtime:
  Is WordPress already installed?
  NO  → Download WP → Create config → Install DB tables → Start php-fpm
  YES → Start php-fpm directly

php-fpm sits waiting on port 9000
NGINX sends PHP requests → php-fpm executes them → returns HTML to NGINX
```