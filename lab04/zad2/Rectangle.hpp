#pragma once

#include "Figure.hpp" //will include iostream and string as well

class Rectangle : public Figure {
private:
    double m_a;
    double m_b;

protected:
    //parametrized constructor 
    //protected due to use by Square Class' constructor, which inherent from Rectangle class
    //we want to provide changing of m_name field 
    Rectangle( double a, double b, const Point &p, std::string name) :
        Figure( p, name ) { //have to use Figure constructor <- no setter for name
            if ( a > 0 ){       //validation
                m_a = a;
            } else {
                std::cout << "Side a has to be positive and non zero!" << std::endl;
            }
            if ( b > 0 ){       
                m_b = b;
            } else {
                std::cout << "Side b has to be positive and non zero!" << std::endl;
            }
        } ; 

public:
    //parametrized constructor
    Rectangle( double a, double b, const Point &p ) : Rectangle(a, b, p, "Rectangle") {} 

    //methods:
    double area() const override {
        return m_a * m_b;
    }

    //getters:
    double getSideA() const {
        return m_a;
    }

    double getSideB() const {
        return m_b;
    }

    //setters:
    void setSideA( double a ) {
        if ( a > 0 ){       //validation
            m_a = a;
        } else {
            std::cout << "Side a has to be positive and non zero!" << std::endl;
        }
     }
     void setSideB( double b ) {
        if ( b > 0 ){       //validation
            m_b = b;
        } else {
            std::cout << "Side b has to be positive and non zero!" << std::endl;
        }
     }
     void setSides( double a, double b) {
        if ( a > 0 ){       //validation
            m_a = a;
        } else {
            std::cout << "Side a has to be positive and non zero!" << std::endl;
        }
        if ( b > 0 ){       
            m_b = b;
        } else {
            std::cout << "Side b has to be positive and non zero!" << std::endl;
        }
     }

     void description() const override {
        std::cout << "I have sides of length " << m_a << " and " << m_b << std::endl;
        printCentre();
     }
};