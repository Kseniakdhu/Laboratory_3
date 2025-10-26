#pragma once
#include <compare>
#include <string>
#include "Point.h"
#include "Figure.h"

class Rectangle : public Figure{
    public:
        Rectangle();

        Rectangle(const Point& A, const Point& B, const Point& C, const Point D);

        Rectangle(&Rectangle other) noexcept;
        Rectangle& operator=(const &Rectangle other) noexcept;

        Rectangle(&&Rectangle other) noexcept;
        Rectangle& operator=(const &&Rectangle other) noexcept;

        bool operator==(const &Rectangle other) const;

        Point geometric_center() const override;
        double area() const override;
        operator double() const override;        

}