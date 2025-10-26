#include <iostream>
#include <math.h>
#include "../include/Trapezoid.hpp"
#include "../include/Point.h"

using namespace std;

Trapezoid() : Figure(){}

Trapezoid(const Point& A, const Point& B, const Point& C, const Point& D) : Figure(A, B, C, D)

Trapezoid(const Trapezoid& other) : Figure(other){}

Trapezoid(Trapezoid&& other) noexcept : Figure(move(other)){}

Trapezoid& Trazoid:: operator=(const Trazoid& other) {
    if (&other != this) {
        points = new Point[size];
        for (int i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Trazoid& Trazoid:: operator=(Trazoid&& other) noexcept {
    if (&other != this) {
        points = other.points;
        other.points = nullptr;
        }
    return *this;
}

bool Trazoid::operator==(const Trazoid& other) const {
    if (this->area() != other.area()) {
        return false;
    }
    return true;
}


Point Trapezoid:: geometric_center() const{
     double center_x = (points[0].getX() + points[1].getX()+ points[2].getX() + points[3].getX()) / 4.0;
     double center_y = (points[0].getY() + points[1].getY() + points[2].getY() + points[3].getY()) / 4.0;
     return Point(center_x, center_y);
 }

double Trapezoid:: area() const{ // формула Гаусса (формула шнурования)
    double areas = 0.5 * abs((points[0].getX()*points[1].getY()) + 
    (points[2].getY()*points[1].getX()) + (points[2].getX()*points[3].getY()) +
    (points[3].getX()*points[0].getY()) - ((points[0].getY()*points[1].getX()) + 
    (points[1].getY()*points[2].getX()) + (points[2].getY()*points[3].getX())) +
    (points[3].getY()*points[0].getX()))
    return area;
};

Trapezoid::operator double() const{
    return this->area();
}