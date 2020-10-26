#ifndef PILOTMARKER_MARKERFACTORY_H
#define PILOTMARKER_MARKERFACTORY_H

#include <memory>

class AbstractObjectProcessor;

class AbstractMarkerParser;

/**
 * Marker factory is a singleton class which provides functionality to create marker and
 * abstract object related instances
 */
class MarkerFactory {
private:
    MarkerFactory() = default;

    MarkerFactory(const MarkerFactory &obj) = delete;

    MarkerFactory(MarkerFactory &&obj) = delete;

    MarkerFactory &operator=(const MarkerFactory &obj) = delete;

    MarkerFactory &operator=(MarkerFactory &&obj) = delete;
public:
    static MarkerFactory &getInstance();

    std::shared_ptr<AbstractObjectProcessor> createObjectProcessor();

    std::shared_ptr<AbstractMarkerParser> createMarkerParser();

    ~MarkerFactory() = default;
};


#endif //PILOTMARKER_MARKERFACTORY_H
