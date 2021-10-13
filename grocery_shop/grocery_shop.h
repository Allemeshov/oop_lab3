#ifndef LAB3_GROCERY_SHOP_H
#define LAB3_GROCERY_SHOP_H

#define MEAT 1
#define SEAFOOD 2
#define BEER_AND_WINE 3
#define HEALTH_AND_BEAUTY 4
#define BAKERY 5
#define PRODUCE 6

#define CELL_MIN_WIDTH 8

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <stdexcept>
#include <list>
#include <stdexcept>
#include "../date.h"
#include "../fort/fort.hpp"

using namespace std;

struct Date {

    int day;
    int month;
    int year;

    Date();

    void SetDate(int y, int m, int d);

    void datePrint();
    string to_string();
    int getDay() const;
    void setDay(const int &_day);
    int getMonth() const;
    void setMonth(const int &_month);
    int getYear() const;
    void setYear(const int &_year);
};


struct Type {
    int type_raw;

    Type();

    explicit Type(const int &_type) : type_raw(_type) {};

    string to_string() const;
};


class Product {
private:
    static int ID;

    int id;

    string title;
    int amount;
    Date date_created;
    int gultig;
    Type type;
    float cost;

public:
    Product(const string &_title, const int &_amount, const Date &_date_created, const int &_gultig, const Type &_type,
            const float &_cost);
    Product(const int &_id, const string &_title, const int &_amount, const Date &_date_created, const int &_gultig,
            const Type &_type,
            const float &_cost);

    string getTitle();
    void setTitle(const string &_title);

    int getAmount() const;
    void setAmount(const int &_amount);

    Date getDateCreated();
    void setDateCreated(const Date &_date_created);

    int getGultig() const;
    void setGultig(const int &_gultig);

    Type getType();
    void setType(const Type &_type);

    float getCost() const;
    void setCost(const float &_cost);
};



class GroceryShop {
private:
    list<Product> products;

public:
    GroceryShop();
    GroceryShop(string filePath);

    Date calcGultig(int year, int month, int day, int gultig);

    void printData();

    void outputExpired();

    void outputProductsNumberByTypeId(int _typeId);

    void outputMostExpensiveProducts();
};


#endif //LAB3_GROCERY_SHOP_H
