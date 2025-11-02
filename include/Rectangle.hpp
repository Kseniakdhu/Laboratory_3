#pragma once
#include <compare>
#include <string>
#include "Point.hpp"
#include "Figure.hpp"

class Rectangle : public Figure{
    public:
        Rectangle();
        Rectangle(const Point& A, const Point& B, const Point& C, const Point& D);
        
        Rectangle(const Rectangle& other);
        Rectangle(Rectangle&& other) noexcept;
        
        Rectangle& operator=(const Rectangle& other);
        Rectangle& operator=(Rectangle&& other) noexcept;
        
        bool operator==(const Rectangle& other) const;

        Point geometric_center() const override;
        double area() const override;
        operator double() const override;
        Rectangle* clone() const override;       
};