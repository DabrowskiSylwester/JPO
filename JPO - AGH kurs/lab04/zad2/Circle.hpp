#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"

class Circle : public Figure {
private:
    double m_r;
public:
    //constructor
    Circle( const Point & p, double r) : Figure(p, "Circle"){
        if (r <= 0) {
            m_r=0.0;
            std::cout << "Invalid radius!" << std::endl;
        } else {
            m_r = r;
        }
    };
    //methods
    double area() const override {
        return 3.14*m_r*m_r;
    }
    //getter
    double getRadius() const {
        return m_r;
    }
    //setter
    void setRadius( double r) {
        if (r <= 0) {
            std::cout << "Invalid radius!" << std::endl;
        } else {
            m_r = r;
        }
    }

    void description() const override {
        std::cout << "I have radius " << m_r << std::endl;
        printCentre();
    }
};