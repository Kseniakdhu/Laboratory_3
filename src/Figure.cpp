#include "Figure.hpp"
#include <cmath>
using namespace std;

Figure::Figure() : size(4){
    points = new Point[size];
}


Figure::Figure(const Point& A, const Point& B, const Point& C, const Point& D) {
    size = 4;
    points = new Point[size];
    points[0] = A;
    points[1] = B;
    points[2] = C;
    points[3] = D;
}

Figure& Figure:: operator=(const Figure& other) {
    if (&other != this) {
        points = new Point[size];
        for (int i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Figure& Figure:: operator=(Figure&& other) noexcept {
    if (&other != this) {
        points = other.points;
        other.points = nullptr;
        }
    return *this;
}

Figure::~Figure() {
    delete[] points;
}

ostream& operator<<(std::ostream& os, const Figure& figure) {
    int size = 4;
    for (int i = 0; i < size; ++i) {
        os << "Point " << i + 1 << ": " << figure.points[i];
        if (i < 3) os << ", ";
    }
    return os;
}

istream& operator>>(std::istream& is, Figure& figure) {
    int size = 4;
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter point " << i + 1 << " (x y): ";
        is >> figure.points[i];
    }
    return is;
}
