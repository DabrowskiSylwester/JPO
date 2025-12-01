#pragma once

class Point {
private:
    int m_x;
    int m_y;
public:
    //parametrized constructor
    Point( int x, int y ) : m_x( x ), m_y( y ){};

    //getters:
    int getX() const {
        return m_x;
    }

    int getY() const {
        return m_y;
    }

    //setters:
    void setX( int value ) {
        m_x = value;    //actually no validation needed
    }

    void setY( int value ) {
        m_y = value;
    }
};