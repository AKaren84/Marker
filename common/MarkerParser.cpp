#include "MarkerParser.h"

#include <string>
#include <sstream>
#include <iostream>

#define NUM_SAVED_MARKERS 9

const char *SAVED_MARKERS[] = {
// markerType	positionX	positionY	positionZ
        "0			 10.5		    7		  0.005	\0",
        "0			 10.5		    7		  0.005	\0",
        "1			  0.02          0.1       2.4	\0",
        "1			  2.02          2         3.05	\0",
        "0			  0.02         12         0.0	\0",
        "0			  0.5		   17		  0.005	\0",
        "1			  0.02          4         1.8	\0",
        "0			  0.75         25         1.2	\0",
        "1			  0.02          2         7.231	\0",
};

std::vector<Marker> MarkerParser::parse() {
    std::vector<Marker> parsedMarkers;

    std::string str;
    for (int i = 0; i < NUM_SAVED_MARKERS; ++i) {
        const char *markerBuffer = SAVED_MARKERS[i];
        std::stringstream stream;
        stream << markerBuffer;

        Marker marker;

        int markerType;
        stream >> markerType;
        marker.type = (Marker::Type) markerType;
        stream >> marker.get_position();
        parsedMarkers.push_back(marker);
    }

    return parsedMarkers;
}

void MarkerParser::parse(std::function<void(const Marker &)> callback) {
    for (int i = 0; i < NUM_SAVED_MARKERS; ++i) {
        const char *markerBuffer = SAVED_MARKERS[i];
        std::stringstream stream;
        stream << markerBuffer;

        Marker marker;

        int markerType;
        stream >> markerType;
        marker.type = (Marker::Type) markerType;
        stream >> marker.get_position();
        callback(marker);
    }
}

