# Console Tetris (C++)

A classic Tetris engine developed entirely in **C++** for the command-line interface. This project was originally created using the **ZinJai** IDE during my early steps in software and game development, showcasing matrix manipulation logic and Object-Oriented Programming (OOP) principles.

## Features

* **Strict OOP Architecture:** Clear separation of concerns between the game loop and grid management (`Tablero`) and tetromino shapes and behaviors (`Ficha`).
* **Matrix Management:** Dynamic collision handling and block persistence utilizing 2D arrays.
* **Real-Time Keyboard Input:** Asynchronous input processing that prevents blocking the main game loop.
* **Classic Mechanics:** Tetromino rotation, scoring system, and automatic line clearance (Tetris).

## Controls

The game uses the keyboard's arrow keys and the `R` key for actions:

| Key | Action |
| :--- | :--- |
| **Left Arrow** (`←`) | Move piece left |
| **Right Arrow** (`→`) | Move piece right |
| **Down Arrow** (`↓`) | Accelerate piece drop |
| **R** | Rotate piece |

## Technical Details & Architecture

The game design is divided into two primary components:

1. **`Tablero` (Board)**: Controls the core game loop (`bucle()`), processes user input, and handles rendering. It manages screen updates, collision detection between locked blocks (`value 2`) and falling pieces (`value 1`), and line clearing.
2. **`Ficha` (Tetromino)**: Defines the initial geometry of the 5 implemented classic pieces (I-Palo, O-Cubo, L, Z, T) within $4 \times 4$ sub-matrices and tracks their current rotation states.

### Dependencies
The project relies on libraries frequently used in academic C++ environments:
* `<conio2.h>` (For handling asynchronous input via `kbhit()` / `getch()` and cursor positioning via `gotoxy`).
* `<ctime>` (For managing the internal frame timing and tick rates using `clock_t`).

## Compilation and Execution

### In ZinJai (Recommended)
1. Open ZinJai.
2. Create a new project and import `main.cpp`, `Tablero.cpp`, `Tablero.h`, `Ficha.cpp`, and `Ficha.h`.
3. Ensure the `conio2` library is correctly configured in your environment's compilation build options.
4. Press **F9** to compile and run.

### Standalone Windows (MinGW / GCC)
If compiling directly from the terminal, make sure to link the conio library:
```bash
g++ main.cpp Tablero.cpp Ficha.cpp -o Tetris -lconio
