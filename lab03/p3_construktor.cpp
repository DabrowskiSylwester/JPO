#include <iostream>


class Student {
    public:
        std::string name;
        int age;
    
        // default constructor
        Student() {
            name = "unknown";
            age = 0;
            m_faculty = "what?";
        }
    
        // parameterized constructor
        Student(std::string n, int a, std::string f) : name(n), age(a), m_faculty(f) {
            // body of a constructor
        }
    
        void introduce(void) const {
            std::cout << "I'm " << name << ", I am a "
                << age << " years old student!" << std::endl;
            std::cout << "My faculty is: " << m_faculty << std::endl;
        }
    
    private:
        std::string m_faculty;
    };
    
    int main()
    {
    Student student1; // default constructor
    student1.name = "Jakub";
    student1.age = 25;
    student1.introduce();
    
    Student student2("Maciej", 22, "EiT"); // parameterized constructor
    student2.introduce();
    
    Student student3(student2); // implicit copy constructor
    student3.introduce();
    }
/* execution of program:
I'm Jakub, I am a 25 years old student!
My faculty is: what?     -----> It's not possible to change faculty from "outside World".
I'm Maciej, I am a 22 years old student!
My faculty is: EiT
I'm Maciej, I am a 22 years old student! ----> Contructor use the values from student2 automaticly.
My faculty is: EiT
*/