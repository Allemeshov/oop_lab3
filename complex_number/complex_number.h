#ifndef LAB3_COMPLEX_NUMBER_H
#define LAB3_COMPLEX_NUMBER_H

#include <iostream>
#include <stdexcept>
#include <sstream>


class ComplexNumber {
private:
    float im;
    float re;

public:
    ComplexNumber();
    ComplexNumber(const float &re, const float &im);
    ComplexNumber(const ComplexNumber &cn);
    ~ComplexNumber();

    float getRe() const;
    float getIm() const;

    float getRe();
    void setRe(const float &re);
    float getIm();
    void setIm(const float &im);

    ComplexNumber &operator=(const ComplexNumber &cn);
    ComplexNumber &operator+=(const ComplexNumber &cn);
    ComplexNumber &operator-=(const ComplexNumber &cn);
    ComplexNumber &operator*=(const ComplexNumber &cn);
    ComplexNumber &operator/=(const ComplexNumber &cn);

    ComplexNumber &operator=(const float &re);
    ComplexNumber &operator+=(const float &re);
    ComplexNumber &operator-=(const float &re);
    ComplexNumber &operator*=(const float &value);
    ComplexNumber &operator/=(const float &value);

    friend ComplexNumber operator+(const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator+(const float &a, const ComplexNumber &b);
    friend ComplexNumber operator+(const ComplexNumber &a, const float &b);

    friend ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator-(const float &a, const ComplexNumber &b);
    friend ComplexNumber operator-(const ComplexNumber &b, const float &a);

    friend ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator*(const float &a, const ComplexNumber &b);
    friend ComplexNumber operator*(const ComplexNumber &b, const float &a);

    friend ComplexNumber operator/(const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator/(const float &a, const ComplexNumber &b);
    friend ComplexNumber operator/(const ComplexNumber &b, const float &a);

    friend std::istream& operator>>(std::istream &in, ComplexNumber &cn);
    friend std::ostream& operator<<(std::ostream &out, const ComplexNumber &cn);
};

#endif //LAB3_COMPLEX_NUMBER_H
