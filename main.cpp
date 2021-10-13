#include <iostream>
#include "grocery_shop/grocery_shop.h"
#include "complex_number/complex_number.h"



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
