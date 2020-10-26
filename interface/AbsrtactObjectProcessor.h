#ifndef PILOTMARKER_ABSRTACTOBJECTPROCESSOR_H
#define PILOTMARKER_ABSRTACTOBJECTPROCESSOR_H

class Marker;

/**
 * An interface for Marker processor which should be called for Marker instances via Marker::process() method.
 */
class AbstractObjectProcessor {
public:
    /**
    * An abstract method, which should be called for each Marker instance.
    * @param callback A user given callback.
    */
    virtual void process(Marker &marker) = 0;
};

#endif //PILOTMARKER_ABSRTACTOBJECTPROCESSOR_H
