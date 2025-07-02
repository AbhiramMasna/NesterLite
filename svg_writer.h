#pragma once
#include "polygon.h"
#include <fstream>
#include <string>

class SVGWriter {
    std::ofstream file;
    int width, height;
public:
    SVGWriter(const std::string& filename, int w, int h);
    void addPolygon(const Polygon& poly);
    void save();
};
