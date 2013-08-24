// Main
#include <iostream>
#include <cmath>

#include "Point.h"

using namespace std;

/*
 * Computes the area of the triangle bound by the three specified vertices
 */
double computeArea(Point &a, Point &b, Point &c) {
    double da = a.distanceTo(b);
    double db = a.distanceTo(c);
    double dc = b.distanceTo(c);

    double s = 0.5 * (da + db + dc);

    return sqrt(s * (s - da) * (s - db) * (s - dc));
}

int main() {
    Point a, b, c;

    for (int i = 0; i < 3; i++) {
        double x, y, z;

        cout << "Enter X coordinate of Point " << (i + 1) << ": ";
        cin >> dec >> x;

        cout << "Enter Y coordinate of Point " << (i + 1) << ": ";
        cin >> dec >> y;
        
        cout << "Enter Z coordinate of Point " << (i + 1) << ": ";
        cin >> dec >> z;

        if (i == 0) {
            a.setX(x);
            a.setY(y);
            a.setZ(z);
        } else if (i == 1) {
            b.setX(x);
            b.setY(y);
            b.setZ(z);
        } else if (i == 2) {
            c.setX(x);
            c.setY(y);
            c.setZ(z);
        }

        cout << endl;
    }

    cout << "The area of the triangle is: " << computeArea(a, b, c) << endl;

    return 0;
}
