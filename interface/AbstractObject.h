#ifndef PILOTMARKER_ABSTRACTOBJECT_H
#define PILOTMARKER_ABSTRACTOBJECT_H

#include <memory>

class AbstractObjectProcessor;

/**
 * An interface for Abstract object which provides an interface to visit AbstractObjectProcessor.
 */
class AbstractObject {
public:
    /**
     * An abstract method, which allows to visit an instance of a special visitor object.
     * @param processor A processor object derived from AbstractObjectProcessor.
     */
    virtual void process(std::shared_ptr<AbstractObjectProcessor> processor) = 0;
};

#endif //PILOTMARKER_ABSTRACTOBJECT_H
