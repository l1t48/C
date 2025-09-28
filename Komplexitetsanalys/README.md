# Complexity Analysis Lab

## Introduction
This project is a program designed to generate a simplified complexity analysis for five algorithms:  
Bubble Sort, Insertion Sort, Quick Sort, Linear Search, and Binary Search.  

Each algorithm is analyzed in three scenarios: Best Case, Worst Case, and Average Case.  
The program serves as a practical tool for understanding algorithm time complexity and is used as the basis for the lab report.

---

## Features
- User-friendly menu for selecting algorithms.  
- Displays best, worst, and average cases.  
- Input validation and error handling.  
- Docker support for easy execution.
- Clean build and execution scripts.

---

## 🛠 Requirements

- **GCC version:** `10.5.0`  
  ⚠️ *Higher versions (e.g., GCC 11+) may cause unexpected behavior.*  
- **Docker** (optional, for containerized execution).  
- Unix-like environment (Linux, macOS, or WSL for Windows).

---

## Project Structure

.
├── .dockerignore # Docker ignore file
├── algorithm.c # Implementation of sorting and searching algorithms
├── algorithm.h # Header file for algorithm definitions
├── analyze.c # Complexity analysis functions
├── analyze.h # Header file for analysis definitions
├── clean.sh # Script to clean build artifacts
├── Dockerfile # Docker configuration for containerized build
├── io.c # Input/output helper functions
├── io.h # IO header definitions
├── LICENSE # Project license
├── main.c # Program entry point
├── Makefile # Build configuration
├── README.md # Project documentation
├── run.sh # Script to build and run Docker container
├── ui.c # User interface implementation
└── ui.h # UI header definitions


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

```./main```

4- Clean compiled files:

```make clean```

---

## 📜 License

This project is licensed under the MIT License. See the LICENSE file for details.

---


