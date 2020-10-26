#ifndef PILOTMARKER_MARKER_H
#define PILOTMARKER_MARKER_H

#include <cmath>
#include <iostream>

#include "../interface/AbstractObject.h"

/**
 * Core objects are Marker and it's position Position object.
 */
class AbstractObjectProcessor;

class Position {
public:
    bool operator<(const Position &val);

    bool operator==(const Position &val);

    void set_x(float v);

    float get_x() const;

    void set_y(float);

    float get_y() const;

    void set_z(float);

    float get_z() const;

    friend std::istream &operator>>(std::istream &input, Position &pos);

    friend std::ostream &operator<<(std::ostream &os, const Position &pos);

private:
    float x;
    float y;
    float z;
private:
    static float EPSILION;
};

class Marker : public AbstractObject {
public:
    /**
     * An overridden method, which allows to get marker instance and apply any action in need.
     * @param processor A processor object which should be called in each special processor class.
     */
    void process(std::shared_ptr<AbstractObjectProcessor> processor) override;

    enum Type {
        ARROW,
        DRAWING
    } type;

    bool operator<(const Marker &val);

    bool operator==(const Marker &val);

    void set_position(const Position &pos);

    const Position &get_position() const;

    Position &get_position();

    friend std::ostream &operator<<(std::ostream &os, const Marker &marker);

private:
    Position startPosition;
};

#endif //PILOTMARKER_MARKER_H
