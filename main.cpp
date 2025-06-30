#include "polygon.h"
#include "svg_writer.h"
#include <vector>

int main() {
    // Define a sheet size
    const int sheetWidth = 500;
    const int sheetHeight = 500;

    // Create some example polygons (just rectangles for now)
    std::vector<Polygon> shapes = {
        Polygon(0, 0, 100, 50),
        Polygon(0, 0, 80, 40),
        Polygon(0, 0, 60, 30),
        Polygon(0, 0, 120, 60),
    };

    // Arrange shapes in a simple grid layout
    int x = 0, y = 0, rowHeight = 0;
    for (auto& shape : shapes) {
        if (x + shape.width > sheetWidth) {
            x = 0;
            y += rowHeight + 10;
            rowHeight = 0;
        }
        shape.x = x;
        shape.y = y;
        x += shape.width + 10;
        rowHeight = std::max(rowHeight, shape.height);
    }

    // Write output to SVG
    SVGWriter writer("output.svg", sheetWidth, sheetHeight);
    for (const auto& shape : shapes) {
        writer.addRect(shape.x, shape.y, shape.width, shape.height);
    }
    writer.save();

    return 0;
}
