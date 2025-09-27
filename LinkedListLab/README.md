# Linked List Lab

This project implements an interactive linked list manager in C.
The user can add, remove, sort, reverse, and shift elements in a singly linked list through a text-based menu system.
---

## 📌 Features

- Add integers to the list (at the end or at a chosen position).
- Remove integers (by value or by position).
- Reverse or shift the list (left/right).
- Sort integers in ascending order using Bubble Sort.
- Display the current list, its size, and the starting memory address.
- Clear the entire list with one command.
- Secure input validation is implemented — menu choices outside the range 0–12 show an error message, and entering letters or symbols will automatically terminate the program.

---

## 📂 Project Structure

| File         | Description                                                       |
| ------------ | ----------------------------------------------------------------- |
| `clean.sh`   | Script to remove Docker containers/images related to the project. |
| `Dockerfile` | Docker configuration for building and running the program.        |
| `driv.c`     | Implements linked list manipulation functions.                    |
| `driv.h`     | Header file for `driv.c`.                                         |
| `huvud.c`    | Main program logic and menu system (entry point).                 |
| `list.c`     | Utility functions (size, sort, add/remove at position).           |
| `list.h`     | Header file for `list.c`.                                         |
| `node.h`     | Defines the linked list node structure.                           |
| `Makefile`   | Build instructions for compiling the project.                     |
| `run.sh`     | Script to build and run the project inside Docker.                |
| `README.md`  | Project documentation.                                            |

---

## 🛠 Requirements

- **GCC version:** `13.3.0`  
  ⚠️ *Higher versions (e.g., GCC 13.5.0+) may cause unexpected behavior.*  
- **Docker** (optional, for containerized execution).  
- Unix-like environment (Linux, macOS, or WSL for Windows).

---

## 🚀 Running the Project

This project is designed to be built, run, and cleaned using the provided scripts for convenience and consistency.

### 📦 Using Docker

Clean Docker build:

```bash clean.sh```

Execute the run script:

```bash run.sh```

To clean Docker build artifacts and remove containers:

```bash clean.sh```

### 💻 Running Locally (Without Docker)

1- Ensure GCC version 13.3.0 is installed:

```gcc --version```

2- Build the project:

```make```

3- Run the program:

```./lab```

4- Clean compiled files:

```make clean```

---

## 📜 License

This project is licensed under the MIT License. See the LICENSE file for details.

---


