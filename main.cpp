#include <iostream>
#include "grocery_shop/grocery_shop.h"
#include "complex_number/complex_number.h"
#include "complex_vector/complex_vector.h"




using namespace std;

void demoGroceryShop();
void demoAllOperators();

int main() {
    demoGroceryShop();

    demoAllOperators();

    return 0;
}

void demoAllOperators() {
    auto cn1 = new ComplexNumber();

    cin >> *cn1;

    cout << "Complex number #1:";
    cout << '\t' << *cn1;

    auto cn2 = new ComplexNumber(15, 12.5);
    cout << "\nComplex number #2:";
    cout << '\t' << *cn2;

    cout << "\n\nAddition:";
    cout << '\t' << *cn1 + *cn2;
    cout << '\t' << 15.2 + *cn2;
    cout << '\t' << *cn1 + 14.1;

    cout << "\n\nSubtraction:";
    cout << '\t' << *cn1 - *cn2;
    cout << '\t' << 15.2 - *cn2;
    cout << '\t' << *cn1 - 14.1;

    cout << "\n\nMultiplication:";
    cout << '\t' << *cn1 * *cn2;
    cout << '\t' << 15.2 * *cn2;
    cout << '\t' << *cn1 * 14.1;

    cout << "\n\nDivision:";
    cout << '\t' << *cn1 / *cn2;
    cout << '\t' << 15.2 / *cn2;
    cout << '\t' << *cn1 / 14.1;

    cout << "\n\nSelf-addition:";
    *cn1 += *cn2;
    cout << '\t' << *cn1;
    *cn1 += 2.28;
    cout << '\t' << *cn1;

    cout << "\n\nSelf-subtraction:";
    *cn1 -= *cn2;
    cout << '\t' << *cn1;
    *cn1 -= 2.28;
    cout << '\t' << *cn1;

    cout << "\n\nSelf-multiplication:";
    *cn1 *= *cn2;
    cout << '\t' << *cn1;
    *cn1 *= 2.28;
    cout << '\t' << *cn1;


    cout << "\n\nSelf-division:";
    *cn1 /= *cn2;
    cout << '\t' << *cn1;
    *cn1 /= 2.28;
    cout << '\t' << *cn1;


    auto vector1 = new ComplexVector(*cn1);
    cout << "\nComplex vector #1: " << *vector1;

    auto vector2 = new ComplexVector(3, 4);
    cout << "\nComplex vector #2: " << *vector2;

    cout << "\n\nAddition:";
    cout << '\t' << *vector1 + *vector2;

    cout << "\n\nSubtraction:";
    cout << '\t' << *vector1 - *vector2;

    cout << "\n\nMultiplication:";
    cout << '\t' << 15.2 * *vector1;
    cout << '\t' << *vector2 * 14.1;

    cout << "\n\nSelf-addition:";
    *vector1 += *vector2;
    cout << '\t' << *vector1;

    cout << "\n\nSelf-subtraction:";
    *vector1 -= *vector2;
    cout << '\t' << *vector1;

    cout << "\n\nSelf-multiplication:";
    *vector1 *= 2.28;
    cout << '\t' << *vector1;

    cout << "\n\nScalar multiplication:";
    cout << '\t' << *vector1 * *vector2;

    cout << "\n\nSelf scalar multiplication:";
    *vector1 *= *vector2;
    cout << '\t' << *vector1;

    cout << "\n\nCalculate module of a vector:";
    cout << '\t' << vector1->getModule();

}

void demoGroceryShop() {
    auto shop = new GroceryShop("input.txt");

    shop->printData();

    cout << endl << endl;

    shop->outputExpired();

    cout << endl << endl;

    shop->outputMostExpensiveProducts();

    cout << endl << endl;

    shop->outputProductsNumberByTypeId(MEAT);
}
