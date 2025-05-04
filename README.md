Qt Widgets Project - Scalable UI Framework
Overview
This project is a modular Qt Widgets application designed with scalability and efficiency in mind. It utilizes a QStackedWidget-based navigation system, a centralized cache for UI elements, and a custom animation framework to deliver a smooth and expandable interface.

Features
✅ Modular Navigation System – Easily switch between frames using a structured caching system. ✅ Centralized Resource Management – Handles QSS styles, UI components, and animations efficiently. ✅ Smooth UI Effects – Hover and click animations using QPropertyAnimation. ✅ Expandable Framework – Designed to scale by adding new frames without modifying core architecture.

Installation & Setup
Prerequisites
C++ (at least C++20 recommended)

Qt 6.x (or latest stable Qt version)

CMake

Building the Project
bash
git clone <your-repo-url>
cd <your-project-directory>
mkdir build && cd build
cmake ..
make
./your-executable-name
Project Structure
/src
 ├── main.cpp        # Main application entry point
 ├── window.h/.cpp   # MainWindow managing navigation and cache injection
 ├── cache.h/.cpp    # Centralized cache system for UI resources
 ├── animations.h/.cpp  # Encapsulated QPropertyAnimation framework
 ├── styles/         # QSS stylesheets (cached at runtime)
 ├── widgets/        # Custom Qt widget classes (buttons, entries, etc.)
 ├── frames/         # Individual application frames (modular for easy expansion)
/CMakeLists.txt      # Build configuration for CMake
/README.md           # Documentation (this file)
Future Enhancements
📌 Persistent caching implementation (maintain states across sessions). 📌 Lazy-loading UI frames for better performance on complex applications. 📌 Adding a settings menu for dynamic QSS style changes. 📌 Exploring dependency injection for better maintainability.

Contributions & Licensing
Feel free to fork this repository or submit pull requests if you'd like to contribute. Licensed under MIT License (or any license you prefer).
