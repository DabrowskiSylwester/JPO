#pragma once
#include <iostream>

template <typename T>

class CircularBuffer {
private:
    int m_length;
    int m_read, m_write; //pointers
    int *m_data;
public:
//constructor:
    CircularBuffer (int length) : m_write(0),m_read(0) {
        if (length > 0){
            m_length = length;
            m_data = new T[m_length];
        } else {
            m_length = 0;
        }
    }
    //destructor
    ~CircularBuffer(){
        delete m_data;
    }
// geters:
//seters:
// write:
    void write(T data){
        if ((m_write >= m_length) || (m_write<0)){
            m_write = 0;
            m_data[m_write++] = data;
        } else {
            m_data[m_write++] = data;
        }
    }
//read:
    T read(){
        if ((m_read >= m_length) || (m_read<0)){
            m_read = 0;
            return m_data[m_read];
        } else{
            std::cout<<"Buffer is empty!" << std::endl;
        }
        
    }

};