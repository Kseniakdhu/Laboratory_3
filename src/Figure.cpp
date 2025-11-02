#include "../include/Figure.hpp"
#include <utility>

using namespace std;

Figure::Figure() : size(4) {
    for (int i = 0; i < size; ++i) {
        points[i] = Point(0, 0);
    }
}

Figure::Figure(const Point& A, const Point& B, const Point& C, const Point& D) : size(4) {
    points[0] = A;
    points[1] = B;
    points[2] = C;
    points[3] = D;
}

Figure::Figure(const Figure& other) : size(other.size) {
    for (int i = 0; i < 4; ++i) {
        points[i] = other.points[i];
    }
}

Figure::Figure(Figure&& other) noexcept : size(other.size) {
    for (int i = 0; i < 4; ++i) {
        points[i] = move(other.points[i]);
    }
}


ostream& operator<<(std::ostream& os, const Figure& figure) {
    for (int i = 0; i < 4; ++i) {
        os << "Point " << i + 1 << ": " << figure.points[i];
        if (i < 3) os << ", ";
    }
    return os;
}

istream& operator>>(std::istream& is, Figure& figure) {
    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter point " << i + 1 << " (x y): ";
        is >> figure.points[i];
    }
    return is;
}