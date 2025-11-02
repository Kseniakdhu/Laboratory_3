#include <iostream>
#include <utility>
#include "../include/Trapezoid.hpp"
#include "../include/Point.hpp"

using namespace std;

Trapezoid::Trapezoid() : Figure() {}

Trapezoid::Trapezoid(const Point& A, const Point& B, const Point& C, const Point& D) : Figure(A, B, C, D) {}

Trapezoid::Trapezoid(const Trapezoid& other) : Figure(other) {}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept : Figure(move(other)) {}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points[i] = move(other.points[i]);
        }
    }
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    return this->area() == other.area();
}


Point Trapezoid:: geometric_center() const{
     double center_x = (points[0].getX() + points[1].getX()+ points[2].getX() + points[3].getX()) / 4.0;
     double center_y = (points[0].getY() + points[1].getY() + points[2].getY() + points[3].getY()) / 4.0;
     return Point(center_x, center_y);
 }

double Trapezoid:: area() const{ 
    double areas = 0.5 * abs((points[0].getX()*points[1].getY()) + 
    (points[2].getY()*points[1].getX()) + (points[2].getX()*points[3].getY()) +
    (points[3].getX()*points[0].getY()) - ((points[0].getY()*points[1].getX()) + 
    (points[1].getY()*points[2].getX()) + (points[2].getY()*points[3].getX())) +
    (points[3].getY()*points[0].getX()));
    return areas;
};

Trapezoid::operator double() const{
    return this->area();
}


Trapezoid* Trapezoid::clone() const {
    return new Trapezoid(*this);
} 