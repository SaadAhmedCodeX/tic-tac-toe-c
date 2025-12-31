# Tic Tac Toe in C

A **console-based Tic Tac Toe game written in C**, designed as a personal project to practice structured programming, clean logic, and basic game AI. The focus of this project is simplicity, clarity, and a smooth terminal-based user experience.

---

## Overview

This project implements a classic Tic Tac Toe game that can be played directly in the terminal. It supports both **Player vs Player** and **Player vs Computer** modes, with multiple difficulty levels for the computer.
---

## Features

* Two game modes:

  * **Player vs Player (PvP)**
  * **Player vs Computer (PvC)**

* Multiple AI difficulty levels (PvC only):

  * **Easy** – Computer plays random valid moves
  * **Medium** – Computer attempts to win or block
  * **Hard** – Computer plays strategically (win, block, center, corners)

* Random selection of the starting player (`X` or `O`)

* Live scoreboard that updates immediately after each game

* Clear and user-friendly board display

* Input validation for moves and menu choices

---

## Gameplay

* The game runs entirely in the terminal
* Players enter a **cell number (1–9)** to make a move
* Empty cells are shown using numbered brackets, making available moves easy to identify
* A game ends when a player wins or the board is full
* Scores persist across multiple rounds until the program exits

Example board layout:

```
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

---

## How to Play

1. Start the program
2. Select a game mode (PvP or PvC)
3. If PvC is selected, choose a difficulty level
4. The starting player is chosen randomly
5. Enter a cell number (1–9) when prompted
6. After each game, choose whether to play again

---

## Compilation and Execution

The program works with any standard C compiler.

Using GCC:

```bash
gcc tic_tac_toe.c -o tic_tac_toe
./tic_tac_toe
```

On Windows (MinGW):

```bash
gcc tic_tac_toe.c -o tic_tac_toe.exe
tic_tac_toe.exe
```

---

## Possible Improvements

Some ideas that could be explored later:

* Saving scores to a file
* Allowing symbol selection (`X` or `O`)
* Adding a hint system
* Implementing a Minimax-based AI
* Expanding to larger board sizes

---

This project is intended for learning, experimentation, and gradual improvement.
