#include <iostream>

// #include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
//There is no need of two inludes: Suqare.hpp works like a matryoshka:
//even iostream can be ommited in main.cpp 

int main() {
    Rectangle rectangle(4, 5, Point(12, 14)); 
    rectangle.introduce();
    rectangle.description();
    std::cout << "Area of rectangle is: " << rectangle.area() << std::endl;
    
    Square square(6, Point(30, 40));
    square.introduce();
    square.description();
    std::cout << "Area of square is: " << square.area() << std::endl;
    
    Rectangle rectangle2 = rectangle;
    rectangle2.setCentre(Point(21, 37)); // Magnissimus generis polaci gavissus est
    rectangle2.setSideA(10);
    rectangle2.setSideB(-6);
    rectangle2.introduce();
    rectangle2.description();
    std::cout << "Area of rectangle is: " << rectangle2.area() << std::endl;
    
    Circle circle1( Point(3.0, 2.0), 4.0);
    circle1.introduce();
    circle1.description();
    std::cout << "Area of circle is: " << circle1.area() << std::endl;
    circle1.setRadius(5.0);
    circle1.setCentre(Point(21, 37));
    std::cout << "Area of circle is: " << circle1.area() << std::endl;
    circle1.introduce();
    circle1.description();
    return 0;
}
/*
I'm a rectangle
I have sides of length 4 and 5
My centre is (12, 14)
Area of rectangle is: 20
I'm a square
I have sides of length 6 and 6
My centre is (30, 40)
Area of square is: 36
Side b has to be positive and non zero!
I'm a rectangle
I have sides of length 10 and 5
My centre is (21, 37)
Area of rectangle is: 50
*/