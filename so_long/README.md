# 🕹️ so_long

## 📌 Project Overview

`so_long` is a beginner-level graphical project from the 42 school curriculum.  
The objective is to create a simple 2D game using the **MiniLibX** graphical library.

The game features a character that can move across a map, collect items, and exit the level when all collectibles have been gathered.

---

## 🎯 Objectives

- Learn how to use **MiniLibX**, a lightweight graphics library based on X11.
- Handle user input from the keyboard.
- Render images on a window in real time.
- Work with a game loop.
- Read and parse map files.
- Apply basic game logic and movement mechanics.
- Structure and organize code using clean logic and modular functions.

---

## 🧠 Game Logic

1. The game map is read from a `.ber` file and validated.
2. The map must contain:
   - 1 player
   - At least 1 exit
   - At least 1 collectible
   - Only valid characters (`0`, `1`, `C`, `E`, `P`)
   - Surrounded by walls (`1`)
3. The player can move using the keyboard (`W`, `A`, `S`, `D` or arrow keys).
4. The goal is to collect all `C` items and reach the exit `E`.
5. When all collectibles are gathered and the player reaches the exit, the game ends.
6. The window closes when pressing **ESC** or clicking the close button (`X`).

---

## 🧩 How I Built It

### 🔨 Technologies:
- C language  
- MiniLibX  
- X11 (Linux)  
- Makefile

### 🧱 Steps I Followed:

1. **Map Reading**:  
   - Loaded `.ber` file into memory.  
   - Checked for newlines and valid characters.

2. **Map Validation**:  
   - Verified rectangular shape.  
   - Checked wall boundaries.  
   - Counted essential elements (Player, Exit, Collectibles).

3. **Graphics Initialization**:  
   - Used `mlx_init()`, `mlx_new_window()` to set up the window.  
   - Loaded `.xpm` images for walls, floor, player, collectibles, and exit.

4. **Player Movement**:  
   - Hooked keyboard events with `mlx_hook()` and `mlx_key_hook()`.  
   - Updated the map and image positions on every movement.

5. **Game State Tracking**:  
   - Tracked number of moves.  
   - Displayed win message when all collectibles were collected.

6. **Memory Management**:  
   - Freed all allocated memory.  
   - Destroyed images and window on exit.

---

## 🎮 Controls

| Key         | Action        |
|-------------|---------------|
| `W` / `↑`    | Move up       |
| `A` / `←`    | Move left     |
| `S` / `↓`    | Move down     |
| `D` / `→`    | Move right    |
| `ESC`/ `X`   | Exit the game |

---

## ✅ Features

- Real-time 2D rendering.
- Responsive movement and controls.
- Clean game exit logic.
- Full error management and input validation.

---

## 📌 Notes

- This game was built on **Linux**, as MiniLibX requires X11.
- All images were in `.xpm` format and loaded using `mlx_xpm_file_to_image()`.

---

## 🧠 What I Learned

- Understanding of low-level graphical libraries.
- Parsing file input.
- Structuring a real-time interactive loop.
- Managing memory and user inputs.
- Writing clean and modular C code.