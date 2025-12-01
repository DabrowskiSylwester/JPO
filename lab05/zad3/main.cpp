#include <iostream>

#include "ComplexNumber.hpp"

using std::cout, std::endl;

int main() {
    sd::jpo::ComplexNumber c1(2.0,-5.0);
    sd::jpo::ComplexNumber c2(3.0,4.0);
    sd::jpo::ComplexNumber c3 = c1 + c2;
    cout << "Number 1: " << c1 << endl << "Number 2: " << c2 << endl;
    cout << "Complex adding: " << c3 << endl;
    c3 += c3;
    cout << "c3 += c3: " << c3  << endl;
    c3 = c1 - c2;
    cout << "Complex substracting: " << c3 << endl;
    c3 -= c1;
    cout << "c3 -= c1: " << c3 << endl;
    c3 = c1 * c2;
    cout << "Complex multiplication: " << c3 << endl;
    c3 *= c1;
    cout << "c3 *= c1;" << c3 << endl;
    c3 = c1 / c2;
    cout << "Complex division: " << c3 << endl;
    c3 /= c1;
    cout << "c3 /= c1;" << c3 << endl;
    cout << "Is c1 equal c2? : " << (c1 == c2) << endl;
    cout << "Is c1 equal c1? : " << (c1 == c1) << endl; 
    cout << "Is c1 diferent tahn c2? : " << (c1 != c2) << endl;
    cout << "Is c1 diferen than c1? : " << (c1 != c1) << endl; 
    //complex + double
    c3 = c1 + 1.0;
    cout << "Complex, double adding: " << c3 << endl;
    c3 += 1.0;
    cout << "c3 += 1.0 : " << c3 << endl;

    c3 = c1 - 1.0;
    cout << "Complex, double substracting: " << c3 << endl;
    c3 -= 1.0;
    cout << "c3 -= 1.0 : " << c3 << endl;


    cout << "inty: " << endl;
    sd::jpo::ComplexNumber c11(2,-5);
    sd::jpo::ComplexNumber c21(3,4);
    sd::jpo::ComplexNumber c31 = c11 + c21;
    cout << "Number 1: " << c11 << endl << "Number 2: " << c21 << endl;
    cout << "Complex adding: " << c31 << endl;
    c31 += c31;
    cout << "c3 += c3: " << c3  << endl;
    c3 = c1 - c2;
    cout << "Complex substracting: " << c3 << endl;
    c3 -= c1;
    cout << "c3 -= c1: " << c3 << endl;
    c3 = c1 * c2;
    cout << "Complex multiplication: " << c3 << endl;
    c3 *= c1;
    cout << "c3 *= c1;" << c3 << endl;
    c3 = c1 / c2;
    cout << "Complex division: " << c3 << endl;
    c3 /= c1;
    cout << "c3 /= c1;" << c3 << endl;
    cout << "Is c1 equal c2? : " << (c1 == c2) << endl;
    cout << "Is c1 equal c1? : " << (c1 == c1) << endl; 
    cout << "Is c1 diferent tahn c2? : " << (c1 != c2) << endl;
    cout << "Is c1 diferen than c1? : " << (c1 != c1) << endl; 
    //complex + double
    c3 = c1 + 1.0;
    cout << "Complex, double adding: " << c3 << endl;
    c3 += 1.0;
    cout << "c3 += 1.0 : " << c3 << endl;

    c3 = c1 - 1.0;
    cout << "Complex, double substracting: " << c3 << endl;
    c3 -= 1.0;
    cout << "c3 -= 1.0 : " << c3 << endl;
}