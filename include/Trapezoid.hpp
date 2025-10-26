#pragma once
#include <compare>
#include <string>
#include "Point.h"
#include "Figure.h"

class Trapezoid : public Figure{
    public:
        Trapezoid();

        Trapezoid(const Point& A, const Point& B, const Point& C, const Point& D);

        Trapezoid(&Trapezoid other) noexcept;
        Trapezoid operator=(const &Trapezoid other) noexcept;

        Trapezoid(&&Trapezoid other) noexcept;
        Trapezoid operator=(const &&Trapezoid other) noexcept;

        bool operator==(const &Trapezoid other) const;

        Point geometric_center() const override;
        double area() const override;
        operator double() const override;

} 