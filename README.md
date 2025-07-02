# NesterLite
A simple 2D nesting visualizer using C++ and SVG output
# 🧩 NesterLite: A 2D Shape Nesting Visualizer in C++

NesterLite is a lightweight C++ tool that demonstrates simple 2D nesting of rectangular shapes inside a defined sheet. It's designed to show how polygon-based nesting and layout optimization works, relevant to CNC, laser cutting, and CAD applications like FreeCAD.

##Features

- Nesting of rectangles (polygons to be supported later)
- Collision-free layout using a simple greedy strip-packing algorithm
- SVG output viewable in any browser
- Easy to extend (e.g. with `libnest2d` or actual FreeCAD modules)



## Build Instructions

### Prerequisites

Make sure you have these installed:

- C++17 compiler (GCC, Clang, or MSVC)
- CMake (>=3.10)
- Git

### Build & Run

```bash
git clone https://github.com/AbhiramMasna/NesterLite.git
cd NesterLite
mkdir build
cd build
cmake ..
make
./NesterLite
