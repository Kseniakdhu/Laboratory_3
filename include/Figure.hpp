#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include "point.hpp"

class Figure {
    friend ostream& operator<<(ostream& os, const Figure& figure);
    friend istream& operator>>(istream& is, Figure& figure);

protected:

    int size;
    Point * points;

public:
    Figure();
    Figure(const Point& A, const Point& B, const Point& C, const Point& D);


    void Push(const Point& point);

    //virtual Point Geometric_Center() const = 0;
    //virtual operator double() const = 0;

    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;
    

    ~Figure();
};

#endif