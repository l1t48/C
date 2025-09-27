# 🚗 Vehicle Registry System

A modular **C-based vehicle registry management system** designed for robust storage, retrieval, sorting, and management of vehicle data via a clean command-line interface.  
The system supports file persistence to store registered vehicles between sessions.

---

## 📌 Features

- Add, remove, and manage vehicle entries.
- Sort vehicles by brand using **Bubble Sort**.
- Display specific vehicle information or the full registry.
- Persistent file storage for vehicle data.
- Modular project structure for scalability and maintainability.

---

## 📂 Project Structure

| File              | Description                                                   |
|-------------------|---------------------------------------------------------------|
| `clean.sh`       | Script to clean build artifacts.                             |
| `Dockerfile`     | Docker configuration for building and running the system.   |
| `FileHandling.c` | Handles file reading and writing operations.                |
| `lab.c`          | Core program logic and menu system.                          |
| `lab.h`          | Header file for project function declarations.               |
| `main.c`         | Entry point for the program.                                 |
| `Makefile`       | Build instructions for the project.                          |
| `run.sh`         | Script to build and run the project.                         |

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

2- Build the project:

```make```

3- Run the program:

```./lab```

4- Clean compiled files:

```make clean```

---

## 💾 File Persistence

All vehicle records are stored automatically in a file upon program termination and reloaded at startup, ensuring data is preserved between sessions.

---

## 📜 License

This project is licensed under the MIT License. See the LICENSE file for details.

---


