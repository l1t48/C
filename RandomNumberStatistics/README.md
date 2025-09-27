# Random Number Statistics Lab

This project implements a command-line interactive tool in C that generates a sequence of random numbers and allows the user to sort them, calculate statistics, and search for specific numbers using a menu system.

---

## 📌 Features

- Generate a sequence of random numbers.
- Sort numbers in ascending order using Bubble Sort.
- Calculate minimum, maximum, average, and median values.
- Search for specific numbers with position output.
- Interactive menu-driven interface.
- ❗ No safe input validation — incorrect input may cause unexpected behavior or program crash.

---

## 📂 Project Structure
| File         | Description                                               |
| ------------ | --------------------------------------------------------- |
| `Dockerfile` | Docker configuration for building and running the system. |
| `lab.c`     | Core program logic.                                       |
| `run.sh`     | Script to build and run the project inside Docker.        |
| `clean.sh`   | Script to clean Docker build artifacts.                   |

---

## 🛠 Requirements

- **GCC version:** `10.5.0`  
  ⚠️ *Higher versions (e.g., GCC 11+) may cause unexpected behavior.*  
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

1- Ensure GCC version 10.5.0 is installed:

```gcc --version```

2- Compile the program:

```gcc lab.c -o lab```

3- Run the program:

```./lab```

4- Clean compiled files:

```rm lab```

---

## 📜 License

This project is licensed under the MIT License. See the LICENSE file for details.

---


