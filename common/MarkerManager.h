#ifndef PILOTMARKER_MARKERMANAGER_H
#define PILOTMARKER_MARKERMANAGER_H

#include <memory>
#include <string>
#include <vector>

#include "../core/Marker.h"

class AbstractMarkerParser;

class MarkerFactory;

/**
 * A manager of Marker objects.
 * Taking an instance of parser it adds all parsed markes into its internal container and
 * provides an interface to iterate over theme.
 *
 */
class MarkerManager {
public:
    /**
     * Constructor which takes a marker parser instance.
     * Fills up an internal collection of Markers during call of parse() method of parser class.
     * @param parser A parser instance which provides an AbstractMarkerParser interface.
     */
    MarkerManager(std::shared_ptr<AbstractMarkerParser> parser);

    /**
     * Provides an interface to iterate over collected Markers' instances.
     * @param func A callback method which called for each Marker instance.
     */
    void forEachMarker(std::function<void(Marker &)> func);

    std::string getMarker(int i) const;

    int numMarkers() const;

    /**
     * Provides an interface to add a Marker instance. It is intended that all markers should be unique.
     * If given marker already exists then the marker doesn't added. No duplicated markers is allowed.
     *
     * @param func A marker instance which should be added.
     * @return returns true if instance was added, otherwise returns false.
     */
    bool addMarker(const Marker &marker);

    /**
     * Provides an interface to remove a Marker instance.
     * If given marker doesn't exist then the function nothing is doing.
     *
     * @param func A marker instance which should be removed.
     * @return returns true if instance was removed, otherwise returns false.
     */
    bool removeMarker(const Marker &marker);

private:
    MarkerManager() = delete;

    MarkerManager(const MarkerManager &obj) = delete;

    MarkerManager(MarkerManager &&obj) = delete;

    MarkerManager &operator=(const MarkerManager &obj) = delete;

    MarkerManager &operator=(MarkerManager &&obj) = delete;

    void markerParserCallback(const Marker &marker);

private:
    std::vector<Marker> markers;
};


#endif //PILOTMARKER_MARKERMANAGER_H
