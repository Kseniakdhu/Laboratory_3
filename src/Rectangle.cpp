#include <iostream>
#include <utility>
#include "../include/Rectangle.hpp"
#include "../include/Point.hpp"

using namespace std;

Rectangle::Rectangle() : Figure() {}

Rectangle::Rectangle(const Point& A, const Point& B, const Point& C, const Point& D) : Figure(A, B, C, D) {}

Rectangle::Rectangle(const Rectangle& other) : Figure(other) {}

Rectangle::Rectangle(Rectangle&& other) noexcept : Figure(move(other)) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points[i] = move(other.points[i]);
        }
    }
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const {
    return this->area() == other.area();
}

Point Rectangle::geometric_center() const {
    double center_x = (points[0].getX() + points[2].getX()) / 2.0;
    double center_y = (points[0].getY() + points[2].getY()) / 2.0;
    return Point(center_x, center_y);
}

double Rectangle::area() const {
    double length = distance(points[0], points[1]);
    double width = distance(points[0], points[3]);
    return length * width;
}

Rectangle::operator double() const {
    return this->area();
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
} 
