#pragma once

#include <iostream>

namespace sd{
namespace jpo{
template <typename T>
requires std::is_arithmetic_v<T>
class ComplexNumber {
private:
    T m_re, m_im;
public:
    //parametric constructor
    ComplexNumber( T re = 0.0, T im = 0.0 ) : m_re( re ), m_im( im ) {}

    //getters
    T getRe() const {
        return m_re;
    }
    T getIm() const {
        return m_im;
    }

    //setters
    void setRe( T re ) {
        m_re = re; //no validation needed
    }
    void setIm( T im ) {
        m_im = im;
    }

    //operators:

    // operator +
    ComplexNumber operator+( const ComplexNumber& other ) const {
        return ComplexNumber(m_re + other.m_re, m_im + other.m_im);
    }
    ComplexNumber operator+( const T& other ) const {
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
        return ((m_re == other.m_re) || (m_im == other.m_im));
    }

      //operator !=
      bool operator!=( const ComplexNumber& other) {
        return !(*this == other);
        // returm !operator==(other);
    }

    // operator <<
    friend std::ostream& operator<<( std::ostream& os, const ComplexNumber& c){
        os << c.m_re << (c.m_im >= 0 ? " + " : " - ") << std::abs(c.m_im) << "i";
        return os;
    }
};

}
}