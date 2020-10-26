#include "MarkerFactory.h"
#include "MarkerManager.h"
#include "MarkerParser.h"

#include <sstream>

MarkerManager::MarkerManager(std::shared_ptr<AbstractMarkerParser> p) {
    p->parse(std::bind(&MarkerManager::markerParserCallback, this, std::placeholders::_1));
}

std::string MarkerManager::getMarker(int i) const {
    std::stringstream stream;
    Marker marker = markers.at(i);

    stream << marker.type << " - ";
    stream << "(" << marker.get_position().get_x();
    stream << ", " << marker.get_position().get_y();
    stream << ", " << marker.get_position().get_z() << ")";

    return stream.str();
}

int MarkerManager::numMarkers() const {
    return markers.size();
}

bool MarkerManager::addMarker(const Marker &marker) {
    std::vector<Marker>::const_iterator it = std::find(markers.begin(), markers.end(), marker);
    //if there is no such marker then add it
    if (it == markers.end()) {
        markers.push_back(marker);
        return true;
    }
    return false;
}

bool MarkerManager::removeMarker(const Marker &marker) {
    //if found given marker then remove it
    return std::remove(markers.begin(), markers.end(), marker) != markers.end();
}

void MarkerManager::forEachMarker(std::function<void(Marker &)> func) {
    std::for_each(markers.begin(), markers.end(), func);
}

void MarkerManager::markerParserCallback(const Marker &marker) {
    bool is_added = addMarker(marker);
    if (!is_added) {
        std::cout << "WARNING: " << marker << " is already contained" << std::endl;
    }
}
