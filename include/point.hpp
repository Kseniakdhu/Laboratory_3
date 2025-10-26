#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <math.h>
using namespace std;
class Point{
    friend ostream& operator<<(std::ostream& os, const Point& point);
    friend istream& operator>>(std::istream& is, Point& point);
public:
    Point() = default;
    Point(double x_1, double y_1) : x(x_1), y(y_1){}
    ~Point() = default;
    double getX() const;
    double getY() const;
private:

    double x;
    double y;


};

inline ostream& operator<<(ostream& os, const Point& point)
{
    os << "Point ( x : " << point.x << ", y : " << point.y << ")";
    return os;
}

inline istream& operator>>(istream& is, Point& point) {
    double x_coordinate;
    double y_coordinate;
    cout << "Please type in the coordinates for the point" << endl;
    is >> x_coordinate >> y_coordinate;
    point.x = x_coordinate;
    point.y = y_coordinate;
    return is;

}

inline double Point::getX() const {
    return x;
}

inline double Point::getY() const {
    return y;
}

inline double distance(const Point& A, const Point& B) {
    double dx = B.getX() - A.getX();
    double dy = B.getY() - A.getY();
    return sqrt(dx * dx + dy * dy);
}

#endif

