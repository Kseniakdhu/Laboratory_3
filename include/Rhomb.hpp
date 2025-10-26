#pragma once
#include <compare>
#include <string>
#include "Point.hpp"
#include "Figure.hpp"

class Rhomp : public Figure{
    public:
        Rhomp();

        Rhomp(const Point& A, const Point& B, const Point& C, const Point& D);

        Rhomp(&Rhomp other) noexcept;
        Rhomp operator=(const &Rhomp other) noexcept;

        Rhomp(&&Rhomp other) noexcept;
        Rhomp operator=(const &&Rhomp other) noexcept;

        bool operator==(const &Rhomp other) const;

        Point geometric_center() const override;
        double area() const override;
        operator double() const override;

}