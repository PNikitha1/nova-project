# Mobile App Management System (C++ Project)

A C++-based simulation of a mobile app management system that allows users to:
- Install and uninstall apps
- Assign and revoke permissions (like Camera, Microphone)
- View list of installed apps and their permissions

> Designed using Object-Oriented Programming  
> Fully tested using Google Test (24 test cases, all passed)  
> Built using CMake and MinGW-w64 (GCC 15+)

---

## 📂 Project Structure
nova-project/
├── App.h / App.cpp # App class: name + permissions
├── MobileAppManager.h / .cpp # Manager class: handles multiple apps
├── Tests.cpp # 24 unit tests using Google Test
├── CMakeLists.txt # Build configuration
├── google_test/ # Cloned Google Test framework
├── build/ # Auto-generated build files
└── class-diagram.jpg # Class diagram (UML)

---

## Features

- ✅ Install & uninstall apps
- ✅ Assign/revoke permissions
- ✅ Validate inputs (e.g. empty app name not allowed)
- ✅ Handles non-existent apps gracefully
- ✅ List all installed apps & permissions
- ✅ Modular, testable OOP design

---

##Technologies Used

| Tool             | Purpose                        |
|------------------|---------------------------------|
| C++17            | Core programming language       |
| CMake            | Build system generator          |
| MinGW-w64 (GCC 15+)| Compiler for Windows (C++17 support) |
| Google Test      | Unit testing framework          |

---

## Testing (Google Test)

✔️ **24 test cases**  
✔️ Covers all edge cases:  
- Duplicate app names  
- Invalid/unregistered permissions  
- Empty input handling  
- Permission logic by app

## 🧪 Testing (Google Test)

✅ **24 test cases**  
✅ Covers all edge cases:
- Duplicate app names
- Invalid/unregistered permissions
- Empty input handling
- Permission logic by app

Run tests commands:
---
** bash
cmake -Bbuild
cmake --build build
./build/runTests        # Linux/macOS
.\build\runTests.exe    # Windows







