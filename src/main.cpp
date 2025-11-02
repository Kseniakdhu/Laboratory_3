#include <iostream>
#include "../include/Point.hpp"
#include "../include/Figure.hpp"
#include "../include/Rectangle.hpp"
#include "../include/Rhomb.hpp"
#include "../include/Trapezoid.hpp"
#include "../include/FigureArray.hpp"
using namespace std;

int main() {
    cout << "=== Testing Rectangle ===" << endl;
    Point p1(0, 0), p2(0, 3), p3(4, 3), p4(4, 0);
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

    cout << "=== Testing aFigureArray" << endl;
    cout << "\n1. Creating array and adding figures..." << endl;
    FigureArray array;
    
    array.add_figure(new Trapezoid(Point(0,0), Point(4,0), Point(3,3), Point(1,3)));
    array.add_figure(new Rhomb(Point(0,0), Point(3,3), Point(6,0), Point(3,-3)));
    array.add_figure(new Rectangle(Point(0,0), Point(5,0), Point(5,3), Point(0,3)));
    
    cout << "=== Testing function FigureArray ===" << endl;
    cout << "Size: " << array.size2() << endl;
    cout << "Total area: " << array.total_area() << endl;

    cout << "=== Testing element acess ===" << endl;
    cout << "First figure area: " << array[0]->area() << endl;
    cout << "First figure area: " << array[1]->area() << endl;
    cout << "First figure area: " << array[2]->area() << endl;
    cout << "Geometric centers:" << endl;
    array.total_center();

    cout << "=== Testing copy ===" << endl;
    FigureArray copied_array(array);
    cout << "Copied array size: " << copied_array.size2() << endl;
    cout << "Arrays equal: " << (array == copied_array ? "Yes" : "No") << endl;
    cout << "Arrays equal: " << array.get_figure(0) << endl;
    cout << "Arrays equal: " << array.get_figure(1) << endl;
    cout << "Arrays equal: " << array.get_figure(2) << endl;

    cout << "=== Testing removal function ===" << endl;
    array.remove_figure(1);
    cout << "Size after removal: " << array.size2() << endl;

    cout << "=== Testing get function pointer ===" << endl;
    cout <<"1: " << array.get_figure(0) << endl;
    cout <<"2: " <<  array.get_figure(1) << endl;
    cout <<"3: " << array.get_figure(2) << endl;

    return 0;
}

