#ifndef PILOTMARKER_PRINTVIEWER_H
#define PILOTMARKER_PRINTVIEWER_H

#include <iostream>
#include <fstream>
#include <string>

#include "../interface/AbsrtactObjectProcessor.h"

/**
 * A console viewer of AbstractObjects
 */
class PrintViewer : public AbstractObjectProcessor {
public:
    PrintViewer(std::ostream &out_str);

    void process(Marker &marker) override;

private:
    std::ostream &outstream;
};

#endif //PILOTMARKER_PRINTVIEWER_H
