#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"

class Figure {
private:
    Point m_centre;
    std::string m_name;

public:
    // parametrized constructor
    Figure( const Point &p, std::string name) :
            m_centre( p ), m_name( name) {};
    
    // methods:
    virtual double area() const = 0;
    virtual void description() const = 0;

    void printCentre() const {
        std::cout << "My centre is (" << m_centre.getX() << 
                     ", " << m_centre.getY() << ")" << std::endl; //getters are neccessary due to private fields of Point class
    }

    void introduce() const {
        std::cout << "I'm a " << m_name << std::endl;
    }

    //getter
    Point getCentre() const {
        return Point( m_centre.getX(), m_centre.getY()); //has to return a Point object
    }
    //setter
    void setCentre( const Point &p ){
        m_centre = p;   //no validation needed
    }
};