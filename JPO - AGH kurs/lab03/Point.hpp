#pragma once
#include <iostream>

class Point{
    public:
    double x, y;
    //constructor
    Point(double _x, double _y) : x(_x), y(_y){}
    //methods
    void display(){
        std::cout << "(" << x << "," << y <<")";
    }
};