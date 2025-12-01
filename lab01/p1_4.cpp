#include <iostream>

double fahr_to_cel( double fahr){
    return (fahr - 32.0) * 5.0 / 9.0;
}

int main(){
    double temp_fahr{}, temp_cel{};
    std::cout << "Enter temperature in Fahrenheit: ";
    std::cin >> temp_fahr;
    temp_cel = fahr_to_cel(temp_fahr);
    std::cout << "Temperature in Celsius: " << temp_cel << std::endl;
    return 0;
}