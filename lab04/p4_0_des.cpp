#include <iostream>

class Animal {
public:
    ~Animal() {
        std::cout << "ANIMAL DESTRUCTOR" << std::endl;
    }
};

class Dog : public Animal {
public:
    ~Dog() {
        std::cout << "DOG DESTRUCTOR" << std::endl;
    }
};

int main() {
    Dog dog;
    Animal *animal = new Dog();

    delete animal;
    
    return 0;
} 