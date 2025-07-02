#pragma once
#include <vector>
#include <string>

struct Point {
    int x, y;
};

struct BoundingBox {
    int xMin, yMin, xMax, yMax;
};

class Polygon {
public:
    std::vector<Point> points;
    int offsetX = 0, offsetY = 0;
    bool rotated = false;

    Polygon(std::vector<Point> pts);
    BoundingBox getBoundingBox() const;
    void rotate90();
    void moveTo(int x, int y);
    bool collidesWith(const Polygon& other) const;
    std::string toSVG() const;
};
