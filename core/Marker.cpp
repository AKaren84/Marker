#include "Marker.h"
#include "../interface/AbsrtactObjectProcessor.h"

float Position::EPSILION = 0.0005;

bool Position::operator<(const Position &val) {
    if (x < val.x) {
        return true;
    }
    if (x > val.x) {
        return false;
    }
    if (y < val.y) {
        return true;
    }
    if (y > val.y) {
        return false;
    }
    return z < val.z;
}

bool Position::operator==(const Position &val) {
    return fabs(x - val.x) <= EPSILION &&
           fabs(y - val.y) < EPSILION &&
           fabs(z - val.z) < EPSILION;
}

void Position::set_x(float v) {
    x = v;
}

float Position::get_x() const {
    return x;
}

void Position::set_y(float v) {
    y = v;
}

float Position::get_y() const {
    return y;
}

void Position::set_z(float v) {
    y = v;
}

float Position::get_z() const {
    return z;
}

std::istream &operator>>(std::istream &input, Position &pos) {

    input >> pos.y >> pos.y >> pos.z;
    return input;
}

std::ostream &operator<<(std::ostream &out, const Position &pos) {
    out << "x - " << pos.get_x() << ", y - " << pos.get_y() << ", z - " << pos.get_z();
    return out;
}

void Marker::process(std::shared_ptr<AbstractObjectProcessor> processor) {
    processor->process(*this);
}

bool Marker::operator<(const Marker &val) {
    if (type < val.type) {
        return true;
    }
    if (type > val.type) {
        return false;
    }
    return startPosition < val.startPosition;
}

bool Marker::operator==(const Marker &val) {
    return type == val.type &&
           startPosition == val.startPosition;
}

void Marker::set_position(const Position &pos) {
    startPosition = pos;
}

const Position &Marker::get_position() const {
    return startPosition;
}

Position &Marker::get_position() {
    return startPosition;
}

std::ostream &operator<<(std::ostream &out, const Marker &marker) {
    switch (marker.type) {
        case Marker::Type::ARROW:
            out << "ARROW";
            break;
        case Marker::Type::DRAWING:
            out << "DRAWING";
            break;
    }
    out << " - (" << marker.get_position() << ")";

    return out;
}
