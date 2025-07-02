#include "polygon.h"
#include <algorithm>
#include <sstream>
#include <climits>

Polygon::Polygon(std::vector<Point> pts) : points(std::move(pts)) {}

BoundingBox Polygon::getBoundingBox() const {
    int xMin = INT_MAX, yMin = INT_MAX, xMax = INT_MIN, yMax = INT_MIN;
    for (const auto& p : points) {
        xMin = std::min(xMin, p.x);
        yMin = std::min(yMin, p.y);
        xMax = std::max(xMax, p.x);
        yMax = std::max(yMax, p.y);
    }
    return {xMin + offsetX, yMin + offsetY, xMax + offsetX, yMax + offsetY};
}

void Polygon::rotate90() {
    for (auto& p : points) {
        std::swap(p.x, p.y);
        p.x = -p.x;
    }
    rotated = !rotated;
}

void Polygon::moveTo(int x, int y) {
    offsetX = x;
    offsetY = y;
}

bool Polygon::collidesWith(const Polygon& other) const {
    BoundingBox a = getBoundingBox();
    BoundingBox b = other.getBoundingBox();
    return !(a.xMax < b.xMin || a.xMin > b.xMax || a.yMax < b.yMin || a.yMin > b.yMax);
}

std::string Polygon::toSVG() const {
    std::stringstream ss;
    ss << "<polygon points='";
    for (const auto& p : points) {
        ss << p.x + offsetX << "," << p.y + offsetY << " ";
    }
    ss << "' fill='none' stroke='black'/>";
    return ss.str();
}
