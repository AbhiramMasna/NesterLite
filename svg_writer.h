#pragma once
#include <fstream>
#include <string>
#include <vector>

class SVGWriter {
    std::ofstream file;
    int width, height;
public:
    SVGWriter(const std::string& filename, int w, int h);
    void addRect(int x, int y, int w, int h);
    void save();
};
