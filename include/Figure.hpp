#pragma once
#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include "Point.hpp"

class Figure {
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);

protected:
    int size;
    Point points[4];

public:
    Figure();
    Figure(const Point& A, const Point& B, const Point& C, const Point& D);
    
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;
    
    void Push(const Point& point);

    virtual Point geometric_center() const = 0;
    virtual double area() const = 0;
    virtual operator double() const = 0;
    
    virtual ~Figure() = default;
    virtual Figure* clone() const = 0;
};

#endif