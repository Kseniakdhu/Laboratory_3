#include <gtest/gtest.h>
#include "../include/Point.hpp"
#include "../include/Rectangle.hpp"
#include "../include/Rhomb.hpp"
#include "../include/Trapezoid.hpp"
#include "../include/FigureArray.hpp"

// ==================== RECTANGLE TESTS ====================
TEST(RectangleTest, Constructors) {
    Point p1(0, 0), p2(0, 3), p3(4, 3), p4(4, 0);
    Rectangle rect(p1, p2, p3, p4);
    
    // Test copy constructor
    Rectangle rect_copy(rect);
    EXPECT_DOUBLE_EQ(rect_copy.area(), rect.area());
    
    // Test assignment operator
    Rectangle rect_assign = rect;
    EXPECT_DOUBLE_EQ(rect_assign.area(), rect.area());
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle rect1(Point(0,0), Point(0,3), Point(4,3), Point(4,0));
    EXPECT_DOUBLE_EQ(rect1.area(), 12.0);
    
    Rectangle rect2(Point(0,0), Point(0,5), Point(2,5), Point(2,0));
    EXPECT_DOUBLE_EQ(rect2.area(), 10.0);
}

TEST(RectangleTest, GeometricCenter) {
    Rectangle rect(Point(0,0), Point(0,4), Point(6,4), Point(6,0));
    Point center = rect.geometric_center();
    EXPECT_DOUBLE_EQ(center.getX(), 3.0);
    EXPECT_DOUBLE_EQ(center.getY(), 2.0);
}

TEST(RectangleTest, DoubleConversion) {
    Rectangle rect(Point(0,0), Point(0,3), Point(4,3), Point(4,0));
    double area = static_cast<double>(rect);
    EXPECT_DOUBLE_EQ(area, 12.0);
}

TEST(RectangleTest, ComparisonOperators) {
    Rectangle rect1(Point(0,0), Point(0,3), Point(4,3), Point(4,0));
    Rectangle rect2(Point(0,0), Point(0,3), Point(4,3), Point(4,0));
    Rectangle rect3(Point(0,0), Point(0,2), Point(3,2), Point(3,0));
    
    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
}

// ==================== RHOMB TESTS ====================
TEST(RhombTest, Constructors) {
    Point r1(0, 0), r2(2, 2), r3(4, 0), r4(2, -2);
    Rhomb rhomb(r1, r2, r3, r4);
    
    // Test copy constructor
    Rhomb rhomb_copy(rhomb);
    EXPECT_DOUBLE_EQ(rhomb_copy.area(), rhomb.area());
    
    // Test assignment operator
    Rhomb rhomb_assign = rhomb;
    EXPECT_DOUBLE_EQ(rhomb_assign.area(), rhomb.area());
}

TEST(RhombTest, AreaCalculation) {
    Rhomb rhomb1(Point(0,0), Point(2,2), Point(4,0), Point(2,-2));
    EXPECT_DOUBLE_EQ(rhomb1.area(), 8.0);
    
    Rhomb rhomb2(Point(0,0), Point(3,3), Point(6,0), Point(3,-3));
    EXPECT_DOUBLE_EQ(rhomb2.area(), 18.0);
}

TEST(RhombTest, GeometricCenter) {
    Rhomb rhomb(Point(0,0), Point(3,3), Point(6,0), Point(3,-3));
    Point center = rhomb.geometric_center();
    EXPECT_DOUBLE_EQ(center.getX(), 3.0);
    EXPECT_DOUBLE_EQ(center.getY(), 0.0);
}

TEST(RhombTest, DoubleConversion) {
    Rhomb rhomb(Point(0,0), Point(2,2), Point(4,0), Point(2,-2));
    double area = static_cast<double>(rhomb);
    EXPECT_DOUBLE_EQ(area, 8.0);
}

TEST(RhombTest, ComparisonOperators) {
    Rhomb rhomb1(Point(0,0), Point(2,2), Point(4,0), Point(2,-2));
    Rhomb rhomb2(Point(0,0), Point(2,2), Point(4,0), Point(2,-2));
    Rhomb rhomb3(Point(0,0), Point(3,3), Point(6,0), Point(3,-3));
    
    EXPECT_TRUE(rhomb1 == rhomb2);
    EXPECT_FALSE(rhomb1 == rhomb3);
}

// ==================== TRAPEZOID TESTS ====================
TEST(TrapezoidTest, Constructors) {
    Point t1(0,0), t2(4,0), t3(3,2), t4(1,2);
    Trapezoid trap(t1, t2, t3, t4);
    
    // Test copy constructor
    Trapezoid trap_copy(trap);
    EXPECT_DOUBLE_EQ(trap_copy.area(), trap.area());
    
    // Test assignment operator
    Trapezoid trap_assign = trap;
    EXPECT_DOUBLE_EQ(trap_assign.area(), trap.area());
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trap1(Point(0,0), Point(4,0), Point(3,2), Point(1,2));
    EXPECT_DOUBLE_EQ(trap1.area(), 6.0);
    
    Trapezoid trap2(Point(0,0), Point(6,0), Point(4,3), Point(2,3));
    EXPECT_DOUBLE_EQ(trap2.area(), 12.0);
}

TEST(TrapezoidTest, GeometricCenter) {
    Trapezoid trap(Point(0,0), Point(4,0), Point(3,2), Point(1,2));
    Point center = trap.geometric_center();
    EXPECT_DOUBLE_EQ(center.getX(), 2.0);
    EXPECT_DOUBLE_EQ(center.getY(), 1.0);
}

TEST(TrapezoidTest, DoubleConversion) {
    Trapezoid trap(Point(0,0), Point(4,0), Point(3,2), Point(1,2));
    double area = static_cast<double>(trap);
    EXPECT_DOUBLE_EQ(area, 6.0);
}

TEST(TrapezoidTest, ComparisonOperators) {
    Trapezoid trap1(Point(0,0), Point(4,0), Point(3,2), Point(1,2));
    Trapezoid trap2(Point(0,0), Point(4,0), Point(3,2), Point(1,2));
    Trapezoid trap3(Point(0,0), Point(6,0), Point(4,3), Point(2,3));
    
    EXPECT_TRUE(trap1 == trap2);
    EXPECT_FALSE(trap1 == trap3);
}

// ==================== FIGURE ARRAY TESTS ====================
TEST(FigureArrayTest, AddAndSize) {
    FigureArray array;
    array.add_figure(new Rectangle(Point(0,0), Point(0,2), Point(3,2), Point(3,0)));
    ASSERT_EQ(array.size2(), 1);
}

TEST(FigureArrayTest, TotalArea) {
    FigureArray array;
    array.add_figure(new Rectangle(Point(0,0), Point(0,2), Point(3,2), Point(3,0))); // Площадь 6
    array.add_figure(new Rhomb(Point(0,0), Point(2,2), Point(4,0), Point(2,-2)));     // Площадь 8
    ASSERT_DOUBLE_EQ(array.total_area(), 14.0);
}

TEST(FigureArrayTest, RemoveFigure) {
    FigureArray array;
    array.add_figure(new Rectangle());
    array.add_figure(new Rhomb());
    array.remove_figure(0);
    ASSERT_EQ(array.size2(), 1);
}

TEST(FigureArrayTest, CopyArray) {
    FigureArray array;
    array.add_figure(new Rectangle(Point(0,0), Point(0,1), Point(2,1), Point(2,0)));
    
    FigureArray copied(array);
    ASSERT_EQ(array.size2(), copied.size2());
    ASSERT_DOUBLE_EQ(array.total_area(), copied.total_area());
}

TEST(ComparisonTest, EqualAreas) {
    Rectangle rect1(Point(0,0), Point(0,3), Point(4,3), Point(4,0));
    Rectangle rect2(Point(0,0), Point(0,6), Point(2,6), Point(2,0));
    ASSERT_TRUE(rect1 == rect2); // Обе площади = 12
}

TEST(ComparisonTest, NotEqualAreas) {
    Rectangle rect1(Point(0,0), Point(0,3), Point(4,3), Point(4,0));
    Rhomb rhomb(Point(0,0), Point(2,2), Point(4,0), Point(2,-2));
    ASSERT_TRUE(rect1 != rhomb); // 12 vs 8
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}