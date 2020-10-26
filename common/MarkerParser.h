//
// Created by Karen Avagyan on 10/24/20.
//

#ifndef PILOTMARKER_MARKERPARSER_H
#define PILOTMARKER_MARKERPARSER_H

#include <vector>

#include "../core/Marker.h"
#include "../interface/AbstractMarkerParser.h"

/**
 * The class is a simple version of parser overridden from AbstractMarkerParser base class.
 * It parses internal markers and call a given callback each time it found a Marker instance
 */
class MarkerParser : public AbstractMarkerParser {
public:
    std::vector<Marker> parse();

    /**
     * overridden virtual method which called every time Marker instance is created during parse.
     * @param callback A callback called with every Marker instance.
     */
    void parse(std::function<void(const Marker &)> callback) override;
};

#endif //PILOTMARKER_MARKERPARSER_H
