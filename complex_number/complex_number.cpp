#include "complex_number.h"

ComplexNumber::ComplexNumber() {
    re = 0.0;
    im = 0.0;
}
ComplexNumber::ComplexNumber(const float &re, const float &im) {
    this->re = re;
    this->im = im;
}
ComplexNumber::ComplexNumber(const ComplexNumber &cn) {
    this->re = cn.re;
    this->im = cn.im;
}
ComplexNumber::~ComplexNumber() {
    re = 0.0;
    im = 0.0;
}

float ComplexNumber::getRe() const {
    return re;
}
void ComplexNumber::setRe(const float &_re) {
    re = _re;
}
float ComplexNumber::getIm() const  {
    return im;
}
void ComplexNumber::setIm(const float &_im) {
    im = _im;
}
float ComplexNumber::getRe()  {
    return re;
}
float ComplexNumber::getIm() {
    return im;
}

ComplexNumber &ComplexNumber::operator=(const ComplexNumber &cn) {
    if (this != &cn) {
        re = cn.re;
        im = cn.im;
    } else {
        throw std::invalid_argument("Trying to assign the same object.");
    }

    return *this;
}
ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &cn) {
    re += cn.re;
    im += cn.im;

    return *this;
}
ComplexNumber &ComplexNumber::operator-=(const ComplexNumber &cn) {
    re -= cn.re;
    im -= cn.im;

    return *this;
}
ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &cn) {
    re = re * cn.getRe() - im * cn.getIm();
    im = re * cn.getRe() + im * cn.getIm();

    return *this;
}
ComplexNumber &ComplexNumber::operator/=(const ComplexNumber &cn) {
    const float denominator = cn.getRe() * cn.getRe() - cn.getIm() * cn.getIm();
    const ComplexNumber *temp = new ComplexNumber(cn.getRe(), cn.getIm() * (-1));
    const ComplexNumber numerator = *this * *temp;

    *this = numerator / denominator;

    return *this;
}

ComplexNumber &ComplexNumber::operator=(const float &re) {
    this->im = 0;
    this->re = re;

    return *this;
}
ComplexNumber &ComplexNumber::operator+=(const float &re) {
    this->re += re;

    return *this;
}
ComplexNumber &ComplexNumber::operator-=(const float &re) {
    this->re -= re;

    return *this;
}
ComplexNumber &ComplexNumber::operator*=(const float &value) {
    re *= value;
    im *= value;

    return *this;
}
ComplexNumber &ComplexNumber::operator/=(const float &value) {
    this->re /= value;
    this->im /= value;

    return *this;
}

ComplexNumber operator+(const ComplexNumber &a, const ComplexNumber &b) {
    return *(new ComplexNumber(a.getRe() + b.getRe(), a.getIm() + b.getIm()));
}
ComplexNumber operator+(const float &a, const ComplexNumber &b) {
    return *(new ComplexNumber(a + b.getRe(), b.getIm()));
}
ComplexNumber operator+(const ComplexNumber &a, const float &b) {
    return *(new ComplexNumber(b + a.getRe(), a.getIm()));

}

ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b) {
    return *(new ComplexNumber(a.getRe() - b.getRe(), a.getIm() - b.getIm()));
}
ComplexNumber operator-(const float &a, const ComplexNumber &b) {
    return *(new ComplexNumber(a - b.getRe(), b.getIm() * (-1)));
}
ComplexNumber operator-(const ComplexNumber &a, const float &b) {
    return *(new ComplexNumber(a.getRe() - b, a.getIm()));

}

ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b) {
    float re = a.getRe() * b.getRe() - a.getIm() * b.getIm();
    float im = a.getRe() * b.getRe() + a.getIm() * b.getIm();
    return *(new ComplexNumber(re, im));
}
ComplexNumber operator*(const float &a, const ComplexNumber &b) {
    return *(new ComplexNumber(a * b.getRe(), a * b.getIm()));
}
ComplexNumber operator*(const ComplexNumber &a, const float &b) {
    return *(new ComplexNumber(b * a.getRe(), b * a.getIm()));

}

ComplexNumber operator/(const ComplexNumber &a, const ComplexNumber &b) {
    const float denominator = b.getRe() * b.getRe() - b.getIm() * b.getIm();
    const ComplexNumber *temp = new ComplexNumber(b.getRe(), b.getIm() * (-1));
    const ComplexNumber numerator = a * *temp;

    return numerator / denominator;
}
ComplexNumber operator/(const float &a, const ComplexNumber &b) {
    const float denominator = b.getRe() * b.getRe() - b.getIm() * b.getIm();
    const ComplexNumber *temp = new ComplexNumber(b.getRe(), b.getIm() * (-1));
    const ComplexNumber numerator = a * *temp;

    return numerator / denominator;
}
ComplexNumber operator/(const ComplexNumber &a, const float &b) {
    return *(new ComplexNumber(a.getRe() / b, a.getIm() / b));
}

std::istream& operator>>(std::istream &in, ComplexNumber &cn) {
    std::string complexNumberStr;

    std::cout << "Enter complex number: ";
    std::getline(in, complexNumberStr);

    if (complexNumberStr.empty())
        throw std::invalid_argument("Empty line. Nothing to read.");

    std::string stringBuilder;
    bool isImPositive = true;
    if (complexNumberStr[0] == '+' || complexNumberStr[0] == ' ')
        throw std::invalid_argument("Invalid input. Complex number must look like: x + yi");
    bool savedRe = false, hasFoundI = false, hasMetSign = false;
    for (int i = 0; i < complexNumberStr.size(); ++i) {
        switch (complexNumberStr[i]) {
            case ' ':
                break;
            case '-':
                    isImPositive = false;
            case '+': {
                if (!hasMetSign)
                    hasMetSign = true;
                else {
                    throw std::invalid_argument("Twice repeated operation sign in reading line.");
                }

                float re = 0.0;
                std::istringstream ss(stringBuilder);
                if (ss >> re) {
                    savedRe = true;
                    cn.setRe(re);

                } else {
                    throw std::invalid_argument("Cannot save Re part. The value is: " + stringBuilder);
                }
                stringBuilder.clear();
                break;
            }
            case 'i': {
                if (!hasFoundI) {
                    hasFoundI = true;

                    float im = 0.0;
                    std::istringstream ss(stringBuilder);
                    if (ss >> im) {
                        im *= isImPositive ? 1.0 : -1.0;
                        cn.setIm(im);

                    } else {
                        throw std::invalid_argument("Cannot save Im part. The value is: " + stringBuilder);
                    }
                    break;
                } else {
                    throw std::invalid_argument("Twice repeated character 'i' in reading line.");
                }
            }
            case '\0': {
                bool isValid = true;
                int errorsCounter = 0;
                std::string errorMsg;
                if (!savedRe) {
                    isValid = false;
                    ++errorsCounter;
                    errorMsg += "\tRe part wasn't successfully saved.\n";
                }
                if (!hasFoundI) {
                    isValid = false;
                    ++errorsCounter;
                    errorMsg += "\tCharacter 'i' was not found in the reading line.\n";
                }

                if (!isValid) {
                    std::string warning = "Found " + std::to_string(errorsCounter) + " error";
                    warning += errorsCounter > 1 ? "s:\n" : ":\n";
                    throw std::invalid_argument(warning + errorMsg);
                }
            }
            default: {
                stringBuilder.push_back(complexNumberStr[i]);
                break;
            }
        }
    }

    return in;
}
std::ostream& operator<<(std::ostream &out, const ComplexNumber &cn) {
    out << "\nComplex number:\t";
    out << cn.getRe() << " ";
    if (cn.getIm() > 0)
        out << "+ " << cn.getIm() << "i";
    else if (cn.getIm() < 0)
        out << "- " << cn.getIm() * (-1) << "i";

    out << std::endl;

    return out;
}


