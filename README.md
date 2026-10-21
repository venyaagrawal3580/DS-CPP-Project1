# 🎮 PLAYABLE — Interactive Game Platform

**A C++ game platform built using Data Structures and Algorithms (DSA) and Object-Oriented Programming (OOP).**

PLAYABLE is a console-based gaming platform that brings classic games together in one application. It uses a menu-driven interface that allows users to select and play games.

The project demonstrates the practical application of linked lists, classes, objects, pointers, and modular programming in C++.

## 📌 Project Objectives

- Develop an interactive menu-driven gaming platform.
- Apply fundamental Data Structures and Algorithms concepts.
- Implement Object-Oriented Programming principles.
- Improve problem-solving and logical thinking through game development.
- Design a modular structure that supports adding more games in the future.

## ✨ Features

### 🐍 Snake Game — Implemented

- Control the snake using **W, A, S, D**.
- Collect food to increase the score.
- Grow the snake when food is collected.
- Detect wall collisions and collisions with the snake's body.
- Return to the main menu using **X**.

### 🧩 Planned Games

The following games are listed in the main menu and are planned for future development:

- **Sudoku** — A number-placement puzzle.
- **Minesweeper** — A logic-based mine-detection game.
- **Tic-Tac-Toe** — A two-player strategy game.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Concepts:** Data Structures and Algorithms, Object-Oriented Programming
- **Data Structure:** Singly linked list for the Snake body
- **Libraries:** iostream, cstdlib, ctime, conio.h, windows.h
- **Development Environment:** A Windows-compatible C++ compiler

## 🧠 DSA and OOP Concepts

| Concept | Application |
|---|---|
| Singly Linked List | Stores the snake's body segments |
| Dynamic Memory Allocation | Creates and removes snake nodes |
| Classes and Objects | Organizes game functionality |
| Encapsulation | Groups game state and related operations |
| Inheritance | Uses the common `Game` interface for game modules |
| Pointers | Connects linked-list nodes and accesses game objects |
| Conditional Statements | Handles movement, collisions, and menu choices |
| Loops | Runs the game and updates the board |

## 📂 Project Structure

```text
DS-CPP-Project1/
│
├── Snake/
│   ├── Snake.h
│   └── Snake.cpp
│
├── Game.h
├── Game.cpp
├── main.cpp
└── README.md
```

*The structure above represents the intended organization; additional files may exist in the repository.*

## ▶️ How to Run

1. Clone or download this repository.
2. Open the project in a C++ IDE that supports Windows console applications.
3. Ensure all source and header files are included in the build.
4. Compile the project using a compatible C++ compiler.
5. Run the executable and select a game from the menu.

### Compile using g++ (Windows)

If the source files are organized as shown above, a sample compilation command is:

```bash
g++ main.cpp Game.cpp Snake/Snake.cpp -o PLAYABLE.exe
```

Run the executable:

```bash
PLAYABLE.exe
```

Adjust the command if `Game.cpp` or other source files are located elsewhere. The program uses Windows-specific console functions, so a standard Linux or macOS environment may require modifications.

## 🎮 Controls

| Key | Action |
|---|---|
| W | Move up |
| A | Move left |
| S | Move down |
| D | Move right |
| X | Return to the main menu |

## 🚀 Future Enhancements

- Implement Sudoku, Minesweeper, and Tic-Tac-Toe.
- Improve the console interface and game-over screens.
- Add difficulty levels and high-score tracking.
- Improve input validation and memory management.
- Add automated tests and detailed game instructions.

## 🎓 Academic Project

This project is developed as a practical demonstration of C++, Data Structures and Algorithms, and Object-Oriented Programming.

**Project Name:** PLAYABLE — Interactive Game Platform

**Repository:** [DS-CPP-Project1](https://github.com/venyaagrawal3580/DS-CPP-Project1)

---

*Built with C++ and a passion for classic games.*
