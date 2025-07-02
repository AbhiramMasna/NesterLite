#include "svg_writer.h"

SVGWriter::SVGWriter(const std::string& filename, int w, int h)
    : width(w), height(h) {
    file.open(filename);
    file << "<svg xmlns='http://www.w3.org/2000/svg' width='" << width
         << "' height='" << height << "'>\n";
}

void SVGWriter::addPolygon(const Polygon& poly) {
    file << "  " << poly.toSVG() << "\n";
}

void SVGWriter::save() {
    file << "</svg>\n";
    file.close();
}
