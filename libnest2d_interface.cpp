#include "libnest2d_interface.h"
#include <iostream>

namespace LibNest2D {
    void runDemoNesting(std::vector<Polygon>& shapes, int sheetWidth, int sheetHeight) {
        std::cout << "[Demo] LibNest2D would process " << shapes.size() << " polygons here.\n";

        // In real implementation: convert to libnest2d::PlacementNFP format
        // Call the nesting engine
        // Update shapes with transformed positions

        // For now: just layout in a diagonal
        int offset = 0;
        for (auto& shape : shapes) {
            shape.moveTo(offset, offset);
            offset += 50;
        }
    }
}
