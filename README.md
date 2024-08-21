# Game of Life

The Game of Life is a cellular automaton devised by mathematician John Conway. It is a zero-player game that evolves based on an initial state without further input. The game consists of a grid of cells that can be either alive or dead. The state of the cells evolves in discrete time steps according to a set of rules.

## Project Overview

This project is an implementation of Conway's Game of Life in C. The program simulates the game by updating the state of a grid of cells based on simple rules:

1. **Any live cell with fewer than two live neighbors dies as if caused by under-population.**
2. **Any live cell with two or three live neighbors lives on to the next generation.**
3. **Any live cell with more than three live neighbors dies, as if by over-population.**
4. **Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.**

## Project Structure

- **`src/`**: Contains the source code files.
  - `main.c`: Entry point of the program. Initializes the grid and runs the simulation loop.
  - `game_of_life.c`: Contains the implementation of the game logic.
- **`include/`**: Contains header files.
  - `game_of_life.h`: Declarations for functions and structures used in the game.
- **`Makefile`**: A build script for compiling the project.
- **`README.md`**: This file, providing an overview of the project.

## Compilation

To compile the project, use the `Makefile` provided. Run the following command in the terminal:

```bash
make
