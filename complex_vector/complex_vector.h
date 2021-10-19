#ifndef LAB3_COMPLEX_VECTOR_H
#define LAB3_COMPLEX_VECTOR_H

#define PI 3.14159

#include <iostream>
#include <cmath>
#include "../complex_number/complex_number.h"

class ComplexVector {
private:
    float x;
    float y;

    float arg_z;
    void calcArgZ();

public:
    ComplexVector();
    ComplexVector(const float &_x, const float &_y);
    ComplexVector(const ComplexVector &cv);
    explicit ComplexVector(const ComplexNumber &cn);
    ~ComplexVector();

    float getX() const;
    float getY() const;

    float getModule() const;

//    void setX(const float &_x);
//    void setY(const float &_y);

    ComplexVector &operator=(const ComplexVector &cv);
    ComplexVector &operator+=(const ComplexVector &cv);
    ComplexVector &operator-=(const ComplexVector &cv);
    ComplexVector &operator*=(const float &value);
    ComplexVector &operator*=(const ComplexVector &cv);

    friend ComplexVector operator+(const ComplexVector &a, const ComplexVector &b);
    friend ComplexVector operator-(const ComplexVector &a, const ComplexVector &b);
    friend ComplexVector operator*(const ComplexVector &a, const ComplexVector &b);
    friend ComplexVector operator*(const float &a, const ComplexVector &b);
    friend ComplexVector operator*(const ComplexVector &b, const float &a);

    friend std::ostream& operator<<(std::ostream &out, const ComplexVector &cn);

};

#endif //LAB3_COMPLEX_VECTOR_H
