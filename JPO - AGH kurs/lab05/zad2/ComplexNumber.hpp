#pragma once

#include <iostream>

namespace sd{
namespace jpo{
class ComplexNumber {
private:
    double m_re, m_im;
public:
    //parametric constructor
    ComplexNumber( double re = 0.0, double im = 0.0 ) : m_re( re ), m_im( im ) {}

    //getters
    double getRe() {
        return m_re;
    }
    double getIm() {
        return m_im;
    }

    //setters
    void setRe( double re ) {
        m_re = re; //no validation needed
    }
    void setIm( double im ) {
        m_im = im;
    }

    //operators:

    // operator +
    ComplexNumber operator+( const ComplexNumber& other ) const {
        return ComplexNumber(m_re + other.m_re, m_im + other.m_im);
    }
    ComplexNumber operator+( const double& other ) const {
        return ComplexNumber(m_re + other, m_im);
    }

    // operator +=
    ComplexNumber& operator+=( const ComplexNumber& other) {
        m_re += other.m_re;
        m_im += other.m_im;
        return *this;
    }
    ComplexNumber& operator+=( const double& other) {
        m_re += other;
        return *this;
    }

    // operator -
    ComplexNumber operator-( const ComplexNumber& other ) const {
        return ComplexNumber(m_re - other.m_re, m_im - other.m_im);
    }
    ComplexNumber operator-( const double& other ) const {
        return ComplexNumber(m_re - other, m_im);
    }

    // operator -=
    ComplexNumber& operator-=( const ComplexNumber& other) {
        m_re -= other.m_re;
        m_im -= other.m_im;
        return *this;
    }
    ComplexNumber& operator-=( const double& other) {
        m_re -= other;
        return *this;
    }

    // operator *
    ComplexNumber operator*( const ComplexNumber& other ) const {
        return ComplexNumber(m_re * other.m_re - m_im * other.m_im,
                             m_im * other.m_im + m_re * other.m_re);
    }

     // operator *=
     ComplexNumber& operator*=( const ComplexNumber& other) {
        m_re = m_re * other.m_re - m_im * other.m_im;
        m_im = m_im * other.m_im + m_re * other.m_re;
        return *this;
    }

    //operator /
    ComplexNumber operator/( const ComplexNumber& other) const {
        return ComplexNumber( (m_re * other.m_re + m_im * other.m_im ) / (other.m_im * other.m_im + other.m_re * other.m_re),
            (m_im * other.m_re - m_re * other.m_im ) / (other.m_im * other.m_im + other.m_re * other.m_re) );
    }

    //operator /=
    ComplexNumber& operator/=( const ComplexNumber& other) {
        m_re = (m_re * other.m_re + m_im * other.m_im) / (other.m_im * other.m_im + other.m_re * other.m_re);
        m_im = (m_im * other.m_re - m_re * other.m_im) / (other.m_im * other.m_im + other.m_re * other.m_re);
        return *this;
    }
    
    //operator ==
    bool operator==( const ComplexNumber& other) {
        if ((m_re == other.m_re) || (m_im == other.m_im)){
            return true;
        } else {
            return false;
        }
    }

      //operator !=
      bool operator!=( const ComplexNumber& other) {
        if ((m_re == other.m_re) || (m_im == other.m_im)){
            return false;
        } else {
            return true;
        }
    }

    // operator <<
    friend std::ostream& operator<<( std::ostream& os, const ComplexNumber& c){
        os << c.m_re << (c.m_im >= 0 ? " + " : " - ") << std::abs(c.m_im) << "i";
        return os;
    }
};

}
}