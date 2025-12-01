#include <iostream>
#include "Circle.hpp"

using std::cout, std::cin, std::endl;

int main(){
    Circle cir1( 1.0 ); //intialization of default circle with radius equals 1
    cout << "Cir1 = Default center, radius 1 :" << endl;
    cout << "Center coordiantes: ";
    cir1.centerCoordinates.display(); 
    cout << endl;
    cout << "Area: " << cir1.area() << endl;

    Circle cir2( 2.0 ); //intialization of default circle with radius equals 2
    cout << "Cir2 = Default center, radius 2 :" << endl;
    cout << "Center coordiantes: ";
    cir2.centerCoordinates.display(); 
    cout << endl;
    cout << "Area: " << cir2.area() << endl;

    cout << "Setter and getter." << endl;
    cir2.setRadius( 3.0 );
    cir2.centerCoordinates.x = -2.0; //new center -> we can change it, because 
    cir2.centerCoordinates.y = 3.0;  //Point class has public fields and centerCoordinates is public as well
    cout << "New cir2 = new center, radius 3 :" << endl;
    cout << "Center coordiantes: ";
    cir2.centerCoordinates.display(); 
    cout << endl;
    cout << "Area: " << cir2.area() << endl;
    cout << "New radius: " << cir2.getRadius() << endl;

    cout << "Validation test!" << endl;
    cout << "Constructor:" << endl;
    Circle cir3(-1.0); //constructor with negative value
    cout << "Area: " << cir3.area() << endl;
    Circle cir4(1.0);
    cir4.setRadius(-2.0); //negative value in setter
    cout << "Area: " << cir4.area() << endl;

}