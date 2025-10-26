#pragma once
#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include "Point.hpp"

class Figure {
    friend ostream& operator<<(ostream& os, const Figure& figure);
    friend istream& operator>>(istream& is, Figure& figure);

protected:
    int size;
    Point points[size];

public:
    Figure();
    Figure(const Point& A, const Point& B, const Point& C, const Point& D);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    void Push(const Point& point);

virtual Point geometric_center() const = 0;
    virtual double area() const = 0;
    virtual operator double() const = 0;

    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;
    
 
    virtual ~Figure() = default();
};

#endif