#pragma once
#include <compare>
#include <string>
#include "Point.hpp"
#include "Figure.hpp"

class Rhomb : public Figure{
    public:
        Rhomb();
        Rhomb(const Point& A, const Point& B, const Point& C, const Point& D);
        
        Rhomb(const Rhomb& other);
        Rhomb(Rhomb&& other) noexcept;
        
        Rhomb& operator=(const Rhomb& other);
        Rhomb& operator=(Rhomb&& other) noexcept;
        
        bool operator==(const Rhomb& other) const;

        Point geometric_center() const override;
        double area() const override;
        operator double() const override;
        Rhomb* clone() const override;           
};