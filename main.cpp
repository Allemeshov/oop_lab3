#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <stdexcept>
#include <list>
#include <stdexcept>
#include "date.h"
#include "fort/fort.hpp"

#define MEAT 1
#define SEAFOOD 2
#define BEER_AND_WINE 3
#define HEALTH_AND_BEAUTY 4
#define BAKERY 5
#define PRODUCE 6

using namespace std;

void startTitle() {
    printf("############### START PROGRAM ##################\n");
}


void endTitle() {
    printf("############## PROGRAM COMPLETE ################\n");
}


void split() {
    printf("------------------------------------------------\n");
}

using namespace std;


//------------------------------------------------------------
struct Date {

    int day;
    int month;
    int year;

    Date() {
        day = 0;
        month = 0;
        year = 0;
    }

    void SetDate(int y, int m, int d) {

        if (y > 1900 && y < 2022) {
            this->year = y;
        } else {
            throw invalid_argument("");
        }

        if (m > 0 && m < 12) {
            this->month = m;
        } else {
            throw invalid_argument("");
        }

        if (d > 0 && d < 32) {
            this->day = d;
        } else {
            throw invalid_argument("");
        }
    }

    void datePrint() {
        cout << this->day << ":" << this->month << ":" << this->year;
    }

    string to_string() {
        return std::to_string(this->day) + ":" +
               std::to_string(this->month) + ":" +
               std::to_string(this->year);
    }

    int getDay() const {
        return this->day;
    }

    void setDay(const int &_day) {
        this->day = _day;
    }

    int getMonth() const {
        return this->month;
    }

    void setMonth(const int &_month) {
        this->month = _month;
    }

    int getYear() const {
        return this->year;
    }

    void setYear(const int &_year) {
        this->year = _year;
    }

};

struct Type {
    int type_raw;

    Type() {
        type_raw = 0;
    };

    explicit Type(const int &_type) : type_raw(_type) {};

    string to_string() const {
        string result;
        switch (type_raw) {
            case MEAT: {
                result = "Meat";
                break;
            }
            case SEAFOOD: {
                result = "Seafood";
                break;
            }
            case BEER_AND_WINE: {
                result = "Beer and wine";
                break;
            }
            case HEALTH_AND_BEAUTY: {
                result = "Health and beauty";
                break;
            }
            case BAKERY: {
                result = "Bakery";
                break;
            }
            case PRODUCE: {
                result = "Produce";
                break;
            }
            default: {
                result = "UNDEFINED" + std::to_string(type_raw);
                break;
            }
        }
        return result;
    };
};


//------------------------------------------------------------
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
            const float &_cost) {
        this->id = Product::ID++;
        this->title = _title;
        this->amount = _amount;
        this->date_created = _date_created;
        this->gultig = _gultig;
        this->type = _type;
        this->cost = _cost;
    }

    Product(const int &_id, const string &_title, const int &_amount, const Date &_date_created, const int &_gultig,
            const Type &_type,
            const float &_cost) {

        this->id = _id;
        this->title = _title;
        this->amount = _amount;
        this->date_created = _date_created;
        this->gultig = _gultig;
        this->type = _type;
        this->cost = _cost;
    }

    string getTitle() {
        return this->title;
    }

    void setTitle(const string &_title) {
        this->title = _title;
    }

    int getAmount() const {
        return this->amount;
    }

    void setAmount(const int &_amount) {
        this->amount = _amount;
    }

    Date getDateCreated() {
        return this->date_created;
    }

    void setDateCreated(const Date &_date_created) {
        this->date_created = _date_created;
    }

    int getGultig() const {
        return this->gultig;
    }

    void setGultig(const int &_gultig) {
        this->gultig = _gultig;
    }

    Type getType() {
        return this->type;
    }

    void setType(const Type &_type) {
        this->type = _type;
    }

    float getCost() const {
        return this->cost;
    }

    void setCost(const float &_cost) {
        this->cost = _cost;
    }

};

int Product::ID = 0;


class GroceryShop {
private:
    list<Product> products;

public:
    GroceryShop() {};

    GroceryShop(string filePath) {
        int n;
        ifstream file(filePath);

        if (file.is_open()) {
            int ID_P = 0;
            string title;
            int amount;
            int day, month, year;
            Date date_created;
            int gultig;
            Type type;
            int type_raw;
            float cost;

            for (int i = 0; !file.eof(); i++) {

                file >> ID_P >> title >> amount >> day >> month >> year >> gultig >> type_raw >> cost;

                date_created.SetDate(year, month, day);
                type.type_raw = type_raw;

                products.emplace_back(ID_P, title, amount, date_created, gultig, type, cost);
            }

            cout << "База данных продуктового загружена" << endl;
            cout << "Число продуктов в базе данных: " << products.size() << endl;

            file.close();
        }
    }

    Date calcGultig(int year, int month, int day, int gultig) {
        Date result;
        if (month + gultig > 12) {
            year++;
            month = month % 12;
        } else {
            month += gultig;
        }

        switch (month) {
            case 4:
            case 6:
            case 9:
            case 11:
                if (day == 31)
                    day--;
                break;
            case 2:
                if (year % 4 == 0) {
                    if (day > 29) {
                        day = 29;
                    }
                } else {
                    if (day > 28) {
                        day = 28;
                    }
                }
                break;

            default:
                break;
        }

        result.SetDate(year, month, day);

        return result;
    }

    void printData() {
        cout << "База данных:" << endl;
        fort::char_table table;
        table.set_cell_text_align(fort::text_align::center);
        table.set_cell_min_width(10);
        list<Product>::iterator i;
        int x = 0;
        Date gultig;

        table << fort::header << "No." << "Product" << "Amount" << "Date of creation" << "Gultig bis" << "Type"
              << "Cost" << fort::endr;

        for (i = products.begin(); i != products.end(); ++i) {
            x++;

            gultig = calcGultig(i->getDateCreated().getYear(), i->getDateCreated().getMonth(),
                                i->getDateCreated().getDay(), i->getGultig());

            table << std::to_string(x) + '.'
                  << i->getTitle()
                  << i->getAmount()
                  << i->getDateCreated().to_string()
                  << gultig.to_string()
                  << i->getType().to_string()
                  << i->getCost() << fort::endr;
        }

        cout << table.to_string() << endl;
    }

    void outputExpired() {
        list<Product>::iterator i;
        Date gultig;

        cout << endl;


// Reduce verbosity but let you know what is in what namespace
        namespace C = std::chrono;
        namespace D = date;
        namespace S = std;

        auto tp = C::system_clock::now(); // tp is a C::system_clock::time_point
        auto dp = D::floor<D::days>(tp);  // dp is a sys_days, which is a
        auto nowDate = D::year_month_day{dp};

        int x = 1;
        fort::char_table table;
        table.set_cell_text_align(fort::text_align::center);
        table.set_cell_min_width(10);
        table << fort::header << "No." << "Product" << "Amount" << "Date of creation" << "Gultig bis" << "Type"
              << "Cost" << fort::endr;


        for (i = products.begin(); i != products.end(); ++i) {
            gultig = calcGultig(i->getDateCreated().getYear(), i->getDateCreated().getMonth(),
                                i->getDateCreated().getDay(), i->getGultig());

            auto gultigBisDate = D::year_month_day(D::year(gultig.getYear()), D::month(gultig.getMonth()),
                                                   D::day(gultig.getDay()));

            if (nowDate > gultigBisDate) {
                table << std::to_string(x++) + '.'
                      << i->getTitle()
                      << i->getAmount()
                      << i->getDateCreated().to_string()
                      << gultig.to_string()
                      << i->getType().to_string()
                      << i->getCost() << fort::endr;
            }
        }

        cout << table.to_string() << endl;
    }

    void outputProductsNumberByTypeId(int _typeId) {
        int result = 0;
        list<Product>::iterator i;
        string typeStr;

        cout << endl;

        for (i = products.begin(); i != products.end(); ++i) {
            if (i->getType().type_raw == _typeId) {
                result++;
                if (!result)
                    typeStr = i->getType().to_string();
            }
        }

        cout << "Most of all there are " << result << "products in "
             << typeStr << endl;
    }

    void outputMostExpensiveProducts() {
        float max;
        string titleOfMostExpensive;
        list<Product>::iterator i;
        bool isMaxSet = false;
        for (int t = MEAT; t <= PRODUCE; ++t) {
            for (i = products.begin(); i != products.end(); ++i) {
                if (i->getType().type_raw == t) {
                    if (isMaxSet) {
                        if (max < i->getCost()) {
                            max = i->getCost();
                            titleOfMostExpensive = i->getTitle();
                        }
                    } else {
                        max = i->getCost();
                        titleOfMostExpensive = i->getTitle();
                        isMaxSet = true;
                    }
                }
            }

            auto temp = new Type(t);
            cout << "The title of most expensive product in " << temp->to_string()
                 << " category is " << titleOfMostExpensive
                 << ". It costs " << max << endl;
        }
    }
};
//
////------------------------------------------------------------
//
//
//
//void averageCost(list<Mail> &mail) {
//    list<Mail>::iterator i;
//    int Sum = 0;
//    float x = 0;
//    for (i = mail.begin(); i != mail.end(); ++i) {
//        Sum += i->getCost();
//    }
//
//    x = Sum / mail.size();
//
//    cout << "Средняя стоимость посылок равна: " << x << endl;
//}
//
//void averageWeight(list<Mail> &mail) {
//    list<Mail>::iterator i;
//    int Sum = 0;
//    float x = 0;
//    for (i = mail.begin(); i != mail.end(); ++i) {
//        Sum += i->getWeight();
//    }
//
//    x = Sum / mail.size();
//
//    cout << "Средний вес посылок равен: " << x << endl;
//}
//
//void Sort(list<Mail> &mail) {
//    int x;
//    cout << "Введите ID пользователя :" << endl;
//    cin >> x;
//    int a = 0;
//    list<Mail>::iterator i;
//    for (i = mail.begin(); i != mail.end(); ++i) {
//        if (i->getID_R() == x) {
//            a++;
//            cout << "Recipient: " << i->getFullName_R() << endl;
//            i = mail.end();
//            break;
//        }
//    }
//    if (!a) {
//        cout << "Такого получателя не существует:" << endl;
//        return;
//    }
//    a = 0;
//    for (i = mail.begin(); i != mail.end(); ++i) {
//        if (i->getID_R() == x) {
//            a++;
//            cout << "Посылка №" << a << " " << "weight: " << i->getWeight() << " | " << "cost: " << i->getCost()
//                 << " Data: " << i->getDay() << ":" << i->getMonth() << ":" << i->getYear() << endl;
//        }
//    }
//
//}
//
//void Add_element(list<Mail> &mail) {
//    int ID_R = 0;
//    string lastN_R;
//    string firstN_R;
//    string middleN_R;
//    int ID_S = 0;
//    string lastN_S;
//    string firstN_S;
//    string middleN_S;
//    int W = 0, C = 0, D = 0, M = 0, Y = 0;
//
//    mail.push_back(Mail(ID_R, lastN_R, firstN_R, middleN_R, ID_S, lastN_S, firstN_S, middleN_S, W, C, D, M, Y));
//}
//
//void Delete_element(list<Mail> &mail) {
//    printData(mail);
//
//    cout << "Введите элемент для удаления :" << endl;
//    int x = 0;
//    do {
//        cin >> x;
//        if (x <= 0 || x >= mail.size()) {
//            cout << "Неверное значение" << endl;
//        }
//
//    } while (x <= 0 || x >= mail.size());
//
//    int a = 0;
//    list<Mail>::iterator i;
//    for (i = mail.begin(); i != mail.end(); ++i) {
//        a++;
//
//        if (a == x) {
//            mail.erase(i);
//        }
//    }
//
//    cout << "Элемент удален" << endl;
//}

int main() {
    auto shop = new GroceryShop("input.txt");

    shop->printData();

    cout << endl << endl;

    shop->outputExpired();

    cout << endl << endl;

    shop->outputMostExpensiveProducts();

    cout << endl << endl;

    shop->outputProductsNumberByTypeId(MEAT);

//    startTitle();
//    inputData(mail, fileInputName);
//
//    printData(mail);
//
//    averageCost(mail);
//    split();
//    averageWeight(mail);
//
//    Sort(mail);
//
//    Delete_element(mail);
//    printData(mail);
//    endTitle();
//
//    cin.get();
    return 0;
}

