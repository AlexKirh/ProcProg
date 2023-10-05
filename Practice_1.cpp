#include <iostream>
#include <clocale>
using namespace std;
#include <climits> /* пределы*/
#include <math.h>
#include <string>

int name() {
    for (int i = 0; i <= 5; i++) {
        std::cout << "Алексей\n";
    }
    return 0;
}


int stuff() {
    unsigned long long int x = 100000000000000;
    signed int y = -3;
    cout << x << " " << y << endl;
    return 0;

}

int arifmetika() { /* Арифметика */
    float x;
    float y;
    cin >> x >> y;
    if (y == 0) {

        return 0;
    }
    cout << "Сумма: " << x + y << "\nПроизведение: " << x * y << "\nРазность: " << x - y << "\nДеление: " << x / y << endl;
    return 0;
}

int yravn() {
    float b;
    float c;
    cin >> b >> c;
    if (b == 0 && c == 0) {
        cout << "Бесконечно много решений";
    }
    else if (b == 0) {
        cout << "Нет решений" << endl;
    }
    else
    {
        cout << (-1 * c) / b << endl;
    }

    return 0;
}

int uravn2() {
    float a;
    float b;
    float c;
    cin >> a >> b >> c;

    if (a != 0 && b != 0 && c != 0) {
        float D = b * b - 4 * a * c;

        if (D < 0) {
            cout << "Нет корней" << endl;
        }
        else if (D == 0) {
            cout << (-1 * b) / (2 * a) << endl;
        }
        else {
            cout << "x1 = " << (-1 * b + pow(D, 0.5)) / (2 * a) << "\nx2 = " << (-1 * b - pow(D, 0.5)) / (2 * a) << endl;
        }
        return 0;

    }
    else {
        if (a == 0 && b == 0 && c == 0) {
            cout << "Бесконечно много решений";
        }
        else if (a == 0 && b != 0 && c != 0) {
            cout << (-1 * c) / b;
        }
        else if (a != 0 && b == 0 && c != 0) {
            int x = (-1 * c) / a;
            if (x >= 0) {
                cout << "x1 = " << pow(x, 0.5) << "\nx2 = " << -1 * pow(x, 0.5);
            }
            else { cout << "нет решений"; }
        }
        else if (a != 0 && b != 0 && c == 0) {
            cout << "x1 = 0\nx2 == " << (-1 * b) / a;
        }
        else if (a == 0 && b == 0 && c != 0) {
            cout << "Нет решений";
        }
        else if (a != 0 && b == 0 && c == 0) {
            cout << "x = 0";
        }
        else if (a == 0 && b != 0 && c == 0) {
            cout << "x = 0";
        }
    }


}

int lamp()
{
    int chas;
    bool shtory;
    bool lampa;

    cout << "Который сейчас час? ";
    cin >> chas;

    if (chas >= 23 || chas <= 0) {
        cout << "Error: несуществующий час";
        return 0;
    }

    string shtory1;
    cout << "Открыты ли шторы? Y/N ";
    cin >> shtory1;

    if (shtory1 == "Y") {
        shtory = true;
    }
    else if (shtory1 == "N") {
        shtory = false;
    }
    else {
        cout << "Error: неправильный ввод данных";
        return 0;
    }

    string lampa1;
    cout << "Включенв ли лампа? Y/N ";
    cin >> lampa1;

    if (lampa1 == "Y") {
        lampa = true;
    }
    else if (lampa1 == "N") {
        lampa = false;
    }
    else {
        cout << "Error: неправильный ввод данных";
        return 0;
    }

    if (chas <= 18 && chas >= 4) {
        if (shtory == true) {
            cout << "Светло";
        }
        else if (shtory == false && lampa == true)
        {
            cout << "Светло";
        }
        else {
            cout << "Темно";
        }
    }
    else {
        if (lampa == true) {
            cout << "Светло";
        }
        else {
            cout << "Темно";
        }
    }


    return 0;
}

int main1() {
    setlocale(LC_ALL, "Russian");

    cout << "Арифметика \nВведите x, y: ";
    arifmetika();
    cout << endl;

    cout << "Уравнение bx + c = 0\nВведите b, c: ";
    yravn();
    cout << " " << endl;

    cout << "Еще уравнение ax2 + bx + c = 0\nВведите a, b, c: ";
    uravn2();
    cout << " " << endl;

    cout << "Лампа со шторой" << endl;
    lamp();
    return 0;
}