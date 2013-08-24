/*
 * A 3-dimensional point class
 * Coordinates are double-precision floating point.
 *
 * Author: Ashwin Ramachandran
 */

#ifndef __POINT_H__
#define __POINT_H__

#include <cmath>

class Point {
 public:
    // Constructors
    Point();                                    // Default constructor
    Point(double x, double y, double z);        // Three-argument constructor

    // Destructor
    ~Point();

    // Accessor methods
    double getX();
    double getY();
    double getZ();

    // Mutator methods
    void setX(double val);
    void setY(double val);
    void setZ(double val);

    // Other member functions
    double distanceTo(Point &p);

 private:
    // Coordinates of the point
    double x_coord;
    double y_coord;
    double z_coord;
};
#endif
