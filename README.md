# NesterLite
A small C++ project for basic 2D nesting of polygons inside a rectangular sheet.

## Features

- Loads polygons from a `.json` file
- Places them on a fixed-size sheet without overlap
- Attempts 90° rotation to improve fit
- Outputs SVG visualization (`output.svg`)
- Logs shape placement info to a text file

## File Structure
main.cpp
polygon.h / polygon.cpp
svg_writer.h / svg_writer.cpp
libnest2d_interface.h / .cpp # stub for future integration
shapes.json
output.svg
nesting_output.txt
CMakeLists.txt
third_party/json.hpp

 C++17 compiler
- CMake >= 3.10

### Steps
```bash
mkdir build
cd build
cmake ..
make
./NesterLite

