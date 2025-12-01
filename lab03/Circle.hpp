#pragma once
#include <iostream>
#include "Point.hpp"

class Circle {
    private:
    double *radius;

    public:
    Point centerCoordinates;

    //parametric constructor:
    Circle(double r) : centerCoordinates(0.0, 0.0) {    //default center coordinates -> centerCoordiantes are public
        std::cout<< "Executing constructor" << std::endl;
        radius = new double; // memory allocation -> result = address 
        if (r > 0){
            *radius = r; // value under 'radius'; det to 'r'
        } else {
            std::cout << "Negative radius!" << std::endl; 
        }
    }
     
    //getter:
    double getRadius() const {
        return *radius; //return value 'hidden' unter pointer
    }
    //setter:
    void setRadius(double r ){
        if (r > 0) {
            *radius = r; //value 'hidden' unter pointer should be r 
        } else {
            std::cout << "Negative radius!" << std::endl;
        }
    }

    //methods:
    //due to pointer on radius method can accept no inputs to give result (it has direct access to private fields)
    double area() {
        return  3.14 * (*radius) * (*radius); //calculation of circle's area
    }
    
    //destructor:
    ~Circle() {
        std::cout << "Executing destructor" << std::endl; 
        delete radius; //making reserved memory free
    }

};