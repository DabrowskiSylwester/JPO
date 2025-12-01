#include <iostream>

using std::cout, std::cin, std::endl;

class Student {
    private:
        std::string m_name;
        int m_age;
    
    public:
        void setAge(int a) {
            if (a <= 0) {
                cout << "Given age is invalid!" << endl;
            } else {
                m_age = a;
            }
        }
        int getAge() const {
            return m_age;
        }
        void setName(std::string n) {
            if (n.size() == 0) {
                cout << "Empty string!" << endl;
            } else {
                m_name = n;
            }
        }
        std::string getName() const {
            return m_name;
        }
    };

int main(){
    Student student1; //default constructor
    
    //Getting age:
    int age{};
    cout << "Insert age:";
    cin >> age;
    student1.setAge(age);
    //Geting name:
    std::string name{};
    cout << "Insert name:";
    cin >> name;
    student1.setName(name);
    //Displaying:
    cout << "Name of student1: " << student1.getName() << endl
         << "Age of student1: " << student1.getAge() << endl;
}

/*
DOG DESTRUCTOR
ANIMAL DESTRUCTOR
DOG DESTRUCTOR
ANIMAL DESTRUCTOR
adminmint@adminmint-HP-ZBook-Studio-G5:~/Programowanie/JPO - AGH kurs/lab04$ g++ -o p4_0_d p4_0_des.cpp
adminmint@adminmint-HP-ZBook-Studio-G5:~/Programowanie/JPO - AGH kurs/lab04$ ./p4_0_d
ANIMAL DESTRUCTOR
DOG DESTRUCTOR
ANIMAL DESTRUCTOR
*/