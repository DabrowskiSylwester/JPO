#include <iostream>

using std::cout, std::cin, std::endl;

class Animal{
    public:
    virtual void makeSound() = 0; //pure virtual method
};

class Dog : public Animal{
    public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal{
    public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

Animal* chooseAnimal(int number) {
    if (number%2 == 0){
        return new Dog();
    } else {
        return new Cat();
    }
}

int main(){
    cout << "Enter a number: ";
    int x{};
    cin >> x;

    Animal *animal = chooseAnimal(x);
    animal->makeSound();

    delete animal;
}

/*
adminmint@adminmint-HP-ZBook-Studio-G5:~/Programowanie/JPO - AGH kurs/lab04$ ./prog
Enter a number: 1
Meow!
adminmint@adminmint-HP-ZBook-Studio-G5:~/Programowanie/JPO - AGH kurs/lab04$ ./prog
Enter a number: 0
Woof!
*/