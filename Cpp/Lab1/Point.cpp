#include "Point.h"

// Default constructor: initializes the point to (0, 0, 0).
Point::Point() {
    x_coord = 0;
    y_coord = 0;
    z_coord = 0;
}

// Initializes the point to (x, y, z).
Point::Point(double x, double y, double z) {
    x_coord = x;
    y_coord = y;
    z_coord = z;
}

// Destructor - Point allocates no dynamic resources.
Point::~Point() {
    // no-op
}

// Mutators

void Point::setX(double val) {
    x_coord = val;
}

void Point::setY(double val) {
    y_coord = val;
}

void Point::setZ(double val) {
    z_coord = val;
}

// Accessors

double Point::getX() {
    return x_coord;
}

double Point::getY() {
    return y_coord;
}

double Point::getZ() {
    return z_coord;
}

// Other member functions

double Point::distanceTo(Point &p) {
    double delta_x_sq = pow(x_coord - p.getX(), 2);
    double delta_y_sq = pow(y_coord - p.getY(), 2);
    double delta_z_sq = pow(z_coord - p.getZ(), 2);

    return sqrt(delta_x_sq + delta_y_sq + delta_z_sq);
}
