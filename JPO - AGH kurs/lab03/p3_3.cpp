#include <iostream>

using std::cout, std::cin, std::endl;
using std::string;

class MyClass{
    private:
    string m_name;
    
    public:
    //parametrical constructor:
    MyClass (string n) : m_name(n){
        cout << "Constructor of " << m_name << " called." << endl;
    }

    //destructor:
    ~MyClass(){
        cout << "Destruktor of " << m_name << " called." << endl;
    }

};

//global object of MyClass:
MyClass globalObject("global");

int main(){
    cout << "Entering main() function." << endl;
    MyClass localObject("local");
    while(1){
        MyClass blockObject("block");
        break;
    }
    cout << "Leaving main() function." << endl;
}

/*
Constructor of global called.
Entering main() function.
Constructor of local called.
Constructor of block called.
Destruktor of block called.
Leaving main() function.
Destruktor of local called.
Destruktor of global called.
*/