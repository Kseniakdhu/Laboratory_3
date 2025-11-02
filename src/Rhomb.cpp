#include <iostream>
#include <utility>
#include "../include/Rhomb.hpp"
#include "../include/Point.hpp"

using namespace std;

Rhomb::Rhomb() : Figure() {}

Rhomb::Rhomb(const Point& A, const Point& B, const Point& C, const Point& D) : Figure(A, B, C, D) {}

Rhomb::Rhomb(const Rhomb& other) : Figure(other) {}

Rhomb::Rhomb(Rhomb&& other) noexcept : Figure(move(other)) {}

Rhomb& Rhomb::operator=(const Rhomb& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Rhomb& Rhomb::operator=(Rhomb&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points[i] = move(other.points[i]);
        }
    }
    return *this;
}

bool Rhomb::operator==(const Rhomb& other) const {
    return this->area() == other.area();
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

Rhomb* Rhomb::clone() const {
    return new Rhomb(*this);
} 