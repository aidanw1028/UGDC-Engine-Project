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

        inline double DotProduct(const Vector2d& v1, const Vector2d& v2) const;

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

        inline double DotProduct(const Vector2d& v1, const Vector2d& v2) const {
            return v1.x * v2.x + v1.y * v2.y;
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



