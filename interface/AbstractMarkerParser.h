//
// Created by Karen Avagyan on 10/25/20.
//

#ifndef PILOTMARKER_ABSTRACTMARKERPARSER_H
#define PILOTMARKER_ABSTRACTMARKERPARSER_H

#include <functional>

class Marker;

/**
 * An interface for Marker parser.
 */
class AbstractMarkerParser {
public:
    /**
     * An abstract method, which should be called during each
     * Marker instance was parsed calling user given callback method.
     * @param callback A user given callback.
     */
    virtual void parse(std::function<void(const Marker &)> callback) = 0;
};


#endif //PILOTMARKER_ABSTRACTMARKERPARSER_H
