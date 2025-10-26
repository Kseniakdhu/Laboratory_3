#include <iostream>
#include "Point.hpp"
#include "Figure.hpp"
#include "Rectangle.hpp"
#include "Rhomb.hpp"
#include "Trapezoid.hpp"

using namespace std;

int main() {
    cout << "=== Testing Point class ===" << endl;
    Point p1(0, 0), p2(3, 0), p3(3, 4), p4(0, 4);
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "Distance between p1 and p2: " << distance(p1, p2) << endl;
    cout << endl;

    cout << "=== Testing Rectangle ===" << endl;
    Rectangle rect(p1, p2, p3, p4);
    cout << "Rectangle points: " << rect << endl;
    cout << "Area: " << rect.area() << endl;
    cout << "Geometric center: " << rect.geometric_center() << endl;
    cout << "Double conversion: " << static_cast<double>(rect) << endl;
    cout << endl;

    cout << "=== Testing Rhomb ===" << endl;
    Point r1(0, 0), r2(2, 2), r3(4, 0), r4(2, -2);
    Rhomb rhomb(r1, r2, r3, r4);
    cout << "Rhomb points: " << rhomb << endl;
    cout << "Area: " << rhomb.area() << endl;
    cout << "Geometric center: " << rhomb.geometric_center() << endl;
    cout << "Double conversion: " << static_cast<double>(rhomb) << endl;
    cout << endl;

    cout << "=== Testing Trapezoid ===" << endl;
    Point t1(0, 0), t2(4, 0), t3(3, 2), t4(1, 2);
    Trapezoid trap(t1, t2, t3, t4);
    cout << "Trapezoid points: " << trap << endl;
    cout << "Area: " << trap.area() << endl;
    cout << "Geometric center: " << trap.geometric_center() << endl;
    cout << "Double conversion: " << static_cast<double>(trap) << endl;
    cout << endl;

    cout << "=== Testing comparison operators ===" << endl;
    Rectangle rect1(p1, p2, p3, p4);
    Rectangle rect2(p1, p2, p3, p4);
    
    if (rect1 == rect2) {
        cout << "Rectangles are equal by area" << endl;
    } else {
        cout << "Rectangles are not equal by area" << endl;
    }
    cout << endl;

    cout << "=== Testing copy constructors ===" << endl;
    Rectangle rect_copy(rect);
    cout << "Original rectangle area: " << rect.area() << endl;
    cout << "Copied rectangle area: " << rect_copy.area() << endl;
    cout << endl;

    cout << "=== Testing assignment operators ===" << endl;
    Rectangle rect_assign = rect;
    cout << "Original rectangle area: " << rect.area() << endl;
    cout << "Assigned rectangle area: " << rect_assign.area() << endl;
    cout << endl;

    cout << "=== Testing input (commented out for demo) ===" << endl;
    /*
    Rectangle user_rect;
    cout << "Enter 4 points for rectangle:" << endl;
    cin >> user_rect;
    cout << "User rectangle: " << user_rect << endl;
    cout << "User rectangle area: " << user_rect.area() << endl;
    */

    return 0;
}

