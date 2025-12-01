#include <iostream>
#include "Point.hpp"

int main(){
    Point p1(1.3,-1.6);
    std::cout << "Coordinates of point1: ";
    p1.display();
    std::cout << std::endl;
    p1.x = 1.5;
    p1.y = 2.0;
    std::cout << "New coordinates of point1: ";
    p1.display();
    std::cout << std::endl;
}