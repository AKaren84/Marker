#include "common/MarkerManager.h"
#include "common/MarkerFactory.h"
#include "common/MarkerParser.h"

namespace {
    void display_markers(Marker &marker, std::shared_ptr<AbstractObjectProcessor> marker_processor) {
        marker.process(marker_processor);
    }
}//unnamed namespace

int main() {
    MarkerFactory &marker_factory = MarkerFactory::getInstance();
    MarkerManager marker_manager(marker_factory.createMarkerParser());
    marker_manager.forEachMarker(
            std::bind(display_markers, std::placeholders::_1, marker_factory.createObjectProcessor()));

    return 0;
}

