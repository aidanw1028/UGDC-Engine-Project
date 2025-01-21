#pragma once

#include <iostream>

class Vector2d {
    private:
        double x;
        double y;

    public:
        Vector2d()
        : x{0.0}, y{0.0}
        {} // default constructor for no input

        // overloaded constructor for when user input is defined

        Vector2d(double xIn, double yIn)
        : x{xIn}, y{yIn}
        {}

        // basic setters with inlines
        inline void SetX(double xIn) {this->x = xIn;}
        inline void SetY(double yIn) {this->y = yIn;}

        //vector operators

        Vector2d operator+(const Vector2d& vector) {
        Vector2d result;
        result.x = x + vector.x;
        result.y = y + vector.y;
        return result;
        }

        Vector2d operator-(const Vector2d& vector) {
            Vector2d result;
            result.x = x - vector.x;
            result.y = y - vector.y;
            return result;
        }

        // minus 1d

        Vector2d operator-() {
            Vector2d result;
            result.x = -x;
            result.y = -y;
            return result;
        }
        Vector2d operator+(const double& a) {
            Vector2d result;
            result.x = x + a;
            result.y = y + a;
            return result;
        }

        friend std::ostream& operator<< (std::ostream& os, const Vector2d& v);
};
inline
std::ostream& operator<< (std::ostream& os, const Vector2d& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}
 //TODO: Implement cross and dot product basic multiplication and division

