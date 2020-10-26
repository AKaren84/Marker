#include "PrintViewer.h"
#include "../core/Marker.h"

PrintViewer::PrintViewer(std::ostream &ostream)
        : outstream(ostream) {
}

void PrintViewer::process(Marker &marker) {
    switch (marker.type) {
        case Marker::Type::ARROW:
            outstream << "ARROW - ";
            break;
        case Marker::Type::DRAWING:
            outstream << "DRAWING - ";
            break;
        default:
            outstream << "UNKNOWN enum type - ";
    }
    outstream << "(" << marker.get_position().get_x();
    outstream << ", " << marker.get_position().get_y();
    outstream << ", " << marker.get_position().get_z() << ")";
    outstream << std::endl;
}
