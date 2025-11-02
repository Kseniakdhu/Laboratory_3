#pragma once
#include <compare>
#include <string>
#include "Point.hpp"
#include "Figure.hpp"

class Trapezoid : public Figure{
    public:
        Trapezoid();
        Trapezoid(const Point& A, const Point& B, const Point& C, const Point& D);
        
        Trapezoid(const Trapezoid& other);
        Trapezoid(Trapezoid&& other) noexcept;
        
        Trapezoid& operator=(const Trapezoid& other);
        Trapezoid& operator=(Trapezoid&& other) noexcept;
        
        bool operator==(const Trapezoid& other) const;

        Point geometric_center() const override;
        double area() const override;
        operator double() const override;
        Trapezoid* clone() const override;       
};