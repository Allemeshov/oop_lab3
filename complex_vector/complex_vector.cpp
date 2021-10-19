//
// Created by Alexander on 19.10.2021.
//

#include "complex_vector.h"

void ComplexVector::calcArgZ() {
    if (y == 0 || x == 0) {
        std::cout << "\nNull vector error!\n";
        return;
    }

    if (y > 0) {
        arg_z = atan(x / y);
    } else {
        if (x > 0) {
            arg_z = PI + atan(x / y);
        } else {
            const float negative_PI = -1 * PI;
            arg_z =  negative_PI + atan(x / y);
        }
    }
}

ComplexVector::ComplexVector() {
    x = 0.0;
    y = 0.0;
    arg_z = 0.0;
}
ComplexVector::ComplexVector(const float &_x, const float &_y) {
    this->x = _x;
    this->y = _y;

    calcArgZ();
}
ComplexVector::ComplexVector(const ComplexNumber &cn) {
    this->x = cn.getRe();
    this->y = cn.getIm();

    calcArgZ();
}
ComplexVector::ComplexVector(const ComplexVector &cv) {
    this->x = cv.x;
    this->y = cv.y;

    calcArgZ();
}
ComplexVector::~ComplexVector() {
    x = 0.0;
    y = 0.0;
    arg_z = 0.0;
}

float ComplexVector::getX() const {
    return x;
}
//void ComplexVector::setX(const float &_x) {
//    x = _x;
//}
float ComplexVector::getY() const {
    return y;
}
//void ComplexVector::setY(const float &_y) {
//    y = _y;
//}

float ComplexVector::getModule() const {
    const float x_2 = x * x;
    const float y_2 = y * y;
    return sqrt(x_2 + y_2);
}

ComplexVector &ComplexVector::operator=(const ComplexVector &cv) {
    if (this != &cv) {
        x = cv.x;
        y = cv.y;
        arg_z = cv.arg_z;
    } else {
        throw std::invalid_argument("Trying to assign the same object.");
    }

    return *this;
}
ComplexVector &ComplexVector::operator+=(const ComplexVector &cn) {
    x += cn.x;
    y += cn.y;

    calcArgZ();

    return *this;
}
ComplexVector &ComplexVector::operator-=(const ComplexVector &cn) {
    x -= cn.x;
    y -= cn.y;

    calcArgZ();

    return *this;
}

ComplexVector &ComplexVector::operator*=(const float &value) {
    x *= value;
    y *= value;

    calcArgZ();

    return *this;
}
ComplexVector &ComplexVector::operator*=(const ComplexVector &cv) {
    x *= cv.x;
    y *= cv.y;

    calcArgZ();

    return *this;
}

ComplexVector operator+(const ComplexVector &a, const ComplexVector &b) {
    const float x = a.x + b.x;
    const float y = a.y + b.y;
    return *(new ComplexVector(x, y));
}

ComplexVector operator-(const ComplexVector &a, const ComplexVector &b) {
    const float x = a.x - b.x;
    const float y = a.y - b.y;
    return *(new ComplexVector(x, y));
}

ComplexVector operator*(const ComplexVector &a, const ComplexVector &b) {
    const float x = a.getX() * b.getX();
    const float y = a.getY() * b.getY();

    return *(new ComplexVector(x, y));
}
ComplexVector operator*(const float &a, const ComplexVector &b) {
    return *(new ComplexVector(b.x * a, b.y * a));
}
ComplexVector operator*(const ComplexVector &a, const float &b) {
    return *(new ComplexVector(a.x * b, a.y * b));
}

std::ostream& operator<<(std::ostream &out, const ComplexVector &cn) {
    out << "\nComplex number:\t";
    out << cn.getX() << " ";
    if (cn.getY() > 0)
        out << "+ " << cn.getY() << "i";
    else if (cn.getY() < 0)
        out << "- " << cn.getY() * (-1) << "i";

    out << std::endl;

    return out;
}



