#include <iostream>
#include "cir_buff.h"
using std::cout, std::endl;

int main(){
    CircularBuffer<int> buffer1(5);
    for (int i=0;i<5;i++){
        buffer1.write(i);
    }
    for (int i=0;i<5;i++){
        cout << buffer1.read() << " ";
    }
    cout << endl;

}