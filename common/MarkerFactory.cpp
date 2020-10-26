#include "MarkerFactory.h"
#include "MarkerParser.h"
#include "PrintViewer.h"

MarkerFactory &
MarkerFactory::getInstance() {
    static MarkerFactory markerFactory;
    return markerFactory;
}

std::shared_ptr<AbstractObjectProcessor>
MarkerFactory::createObjectProcessor() {
    return std::make_shared<PrintViewer>(std::cout);
}

std::shared_ptr<AbstractMarkerParser>
MarkerFactory::createMarkerParser() {
    return std::make_shared<MarkerParser>();
}
