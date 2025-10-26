#include <iostream>
#include "../include/Rhomb.hpp"
#include "../include/Point.hpp"

using namespace std;

Rhomb() : Figure(){}

Rhomb(const Point& A, const Point& B, const Point& C, const Point& D) : Figure(A, B, C, D)

Rhomb(const Rhomb& other) : Figure(other){}

Rhomb(Rhomb&& other) noexcept : Figure(move(other)){}

Rhomb& Rhomb:: operator=(const Rhomb& other) {
    if (&other != this) {
        points = new Point[size];
        for (int i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Rhomb& Rhomb:: operator=(Rhomb&& other) noexcept {
    if (&other != this) {
        points = other.points;
        other.points = nullptr;
        }
    return *this;
}

bool Rhomb::operator==(const Rhomb& other) const {
    if (this->area() != other.area()) {
        return false;
    }
    return true;
}

Point Rhomb:: geometric_center() const{
     double center_x = (points[0].getX() + points[1].getX()+ points[2].getX() + points[3].getX()) / 4.0;
     double center_y = (points[0].getY() + points[1].getY() + points[2].getY() + points[3].getY()) / 4.0;
     return Point(center_x, center_y);
 }

double Rhomb:: area() const{
     double diag1 = distance(points[0], points[2]);
     double diag2 = distance(points[1], points[3]);
     return (diag1 * diag2) / 2.0;
 }

Rhomb::operator double() const{
    return this->area();
}