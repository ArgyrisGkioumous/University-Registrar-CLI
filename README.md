# University Registrar - CLI Version

![C++ Version](https://img.shields.io/badge/C%2B%2B-20-blue.svg)
![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

A robust, object-oriented University Registrar and Student Management application written in C++20. This project features data persistence via CSV logging, dynamic memory management, and clean object-oriented architecture.

---

## 🚀 Features

- **Full CRUD Operations:** Manage University Members (Students & Professors) and Courses.
- **Advanced OOP Design:** Utilization of Polymorphism, Abstract classes, dynamic casting (RTTI), and strict memory management (Rule of Three for pointer handling).
- **Persistent Storage:** Automated data serialization and deserialization using CSV files.
- **Robust Exception Handling:** Full validation and graceful error recovery using custom runtime exceptions.

---

## 📊 Class Architecture

Below is the conceptual object-oriented architecture of the system:

[ Member (Abstract) ]
         /            \
        /              \
 [ Student ]       [ Professor ] <------> [ Course ]
        \              /
         \            /
        [ Registrar ] (Collection & File I/O)

---

## 🛠️ Installation & Compilation

### Prerequisites
- **Compiler:** `g++` supporting C++20.
- **Build System:** CMake (Version 3.20 or higher).

### Build via Terminal
To build and run the application manually, clone the repository and execute:

```bash
# Create a build directory
mkdir build && cd build

# Configure and build using CMake
cmake ..
make

# Run the executable
./untitled1

g++ -std=c++20 main.cpp Member.cpp Professor.cpp Student.cpp Course.cpp Registrar.cpp -o university_app

├── CMakeLists.txt        # CMake build configuration
├── main.cpp              # Application entry point & Main Menu
├── Member.h / .cpp       # Base Abstract class for university members
├── Student.h / .cpp      # Student class definition (Derived)
├── Professor.h / .cpp    # Professor class definition (Derived with Rule of Three)
├── Course.h / .cpp       # Course class representing academic modules
├── Registrar.h / .cpp    # Core controller handling data, files, and logic
└── README.md             # Project documentation

👤 Author
Argyris Gkioumous - Student at University of West Attica (UNIWA)
GitHub: @ArgyrisGkioumous
