#include "polygon.h"
#include "svg_writer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <nlohmann/json.hpp>
#include "libnest2d_interface.h"

#include <fstream>
using json = nlohmann::json;
std::vector<Polygon> loadPolygonsFromFile(const std::string& filename) {
    std::vector<Polygon> shapes;
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open " << filename << "\n";
        return shapes;
    }

    json j;
    inFile >> j;
    for (const auto& item : j["polygons"]) {
        std::vector<Point> pts;
        for (const auto& pt : item) {
            pts.push_back({pt[0], pt[1]});
        }
        shapes.emplace_back(pts);
    }
    return shapes;
}


int main() {
    bool useLibNest2D = false;
if (useLibNest2D) {
    LibNest2D::runDemoNesting(shapes, sheetWidth, sheetHeight);
} else {
    // existing layout logic here
}

    const int sheetWidth = 500;
    const int sheetHeight = 500;
    int x = 0, y = 0, rowHeight = 0;
    std::vector<Polygon> layout;

    // Create some sample polygons
    std::vector<Polygon> shapes = loadPolygonsFromFile("shapes.json");
    bool useLibNest2D = false; // set to true to simulate libnest2d layout
if (useLibNest2D) {
    LibNest2D::runDemoNesting(shapes, sheetWidth, sheetHeight);
}


    for (auto& shape : shapes) {
        bool placed = false;
        for (int r = 0; r < 2; ++r) { // Try both orientations
            auto box = shape.getBoundingBox();
            int w = box.xMax - box.xMin;
            int h = box.yMax - box.yMin;

            if (x + w > sheetWidth) {
                x = 0;
                y += rowHeight + 10;
                rowHeight = 0;
            }

            shape.moveTo(x, y);

            bool collision = false;
            for (const auto& placedShape : layout) {
                if (shape.collidesWith(placedShape)) {
                    collision = true;
                    break;
                }
            }

            if (!collision) {
                layout.push_back(shape);
                x += w + 10;
                rowHeight = std::max(rowHeight, h);
                placed = true;
                break;
            }

            shape.rotate90();
        }

        if (!placed) std::cerr << "Could not place shape!\n";
    }

    // Output to SVG
    SVGWriter writer("output.svg", sheetWidth, sheetHeight);
    for (const auto& shape : layout) {
        writer.addPolygon(shape);
    }
    writer.save();

    std::cout << "Nesting complete. Output saved to output.svg\n";
    std::ofstream exportFile("nesting_output.txt");
for (const auto& shape : layout) {
    BoundingBox box = shape.getBoundingBox();
    exportFile << "Placed at: (" << shape.offsetX << ", " << shape.offsetY << "), ";
    exportFile << "Bounding Box: [" << box.xMin << "," << box.yMin << "] - ["
               << box.xMax << "," << box.yMax << "]\n";
}
exportFile.close();
std::cout << "Placement info written to nesting_output.txt\n";

    return 0;
}
