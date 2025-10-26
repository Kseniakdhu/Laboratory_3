#include <iostream>
#include "../include/Rectangle.hpp"
#include "../include/Point.hpp"

using namespace std;

Rectangle() : Figure(){}

Rectangle(const Point& A, const Point& B, const Point& C, const Point& D) : Figure(A, B, C, D){}

Rectangle(const Rectangle& other) : Figure(other){}

Rectangle(Rectangle&& other) noexcept : Figure(move(other)){}

Rectangle& Rectangle:: operator=(const Rectangle& other) {
    if (&other != this) {
        points = new Point[size];
        for (int i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Rectangle& Rectangle:: operator=(Rectangle&& other) noexcept {
    if (&other != this) {
        points = other.points;
        other.points = nullptr;
        }
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const {
    if (this->area() != other.area()) {
        return false;
    }
    return true;
}

Point Rectangle:: geometric_center() const{
    double center_x = (points[0].getX() + points[2].getX()) / 2.0;
    double center_y = (points[0].getY() + points[2].getY()) / 2.0;
    return Point(center_x, center_y);
}

double Rectangle::R area() const{
    double length = distance(points[0], points[1]);
    double width = distance(points[0], points[3]);
    return length * width;
}

Rectangle::operator double() const{
    return this->area();
}