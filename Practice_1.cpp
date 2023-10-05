#include <iostream>
#include <clocale>
using namespace std;
#include <climits> /* ïðåäåëû*/
#include <math.h>
#include <string>

int name() {
    for (int i = 0; i <= 5; i++) {
        std::cout << "Àëåêñåé\n"; 
    }
    return 0;
}


int stuff() {
    unsigned long long int x = 100000000000000;
    signed int y = -3;
    cout << x << " " << y << endl;
    return 0;

}

int arifmetika() { /* Àðèôìåòèêà */
    float x;
    float y;
    cin >> x >> y;
    if (y == 0) {

        return 0;
    }
    cout << "Ñóììà: " << x + y << "\nÏðîèçâåäåíèå: " << x * y << "\nÐàçíîñòü: " << x - y << "\nÄåëåíèå: " << x / y << endl;
    return 0;
}

int yravn() {
    float b;
    float c;
    cin >> b >> c;
    if (b == 0 && c == 0) {
        cout << "Áåñêîíå÷íî ìíîãî ðåøåíèé";
    }
    else if (b == 0) {
        cout << "Íåò ðåøåíèé" << endl;
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
            cout << "Íåò êîðíåé" << endl;
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
            cout << "Áåñêîíå÷íî ìíîãî ðåøåíèé";
        }
        else if (a == 0 && b != 0 && c != 0) {
            cout << (-1 * c) / b;
        }
        else if (a != 0 && b == 0 && c != 0) {
            int x = (-1 * c) / a;
            if (x >= 0) {
                cout << "x1 = " << pow(x, 0.5) << "\nx2 = " << -1 * pow(x, 0.5);
            }
            else { cout << "íåò ðåøåíèé"; }
        }
        else if (a != 0 && b != 0 && c == 0) {
            cout << "x1 = 0\nx2 == " << (-1 * b) / a;
        }
        else if (a == 0 && b == 0 && c != 0) {
            cout << "Íåò ðåøåíèé";
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

    cout << "Êîòîðûé ñåé÷àñ ÷àñ? ";
    cin >> chas;

    if (chas >= 23 || chas <= 0) {
        cout << "Error: íåñóùåñòâóþùèé ÷àñ";
        return 0;
    }

    string shtory1;
    cout << "Îòêðûòû ëè øòîðû? Y/N ";
    cin >> shtory1;

    if (shtory1 == "Y") {
        shtory = true;
    }
    else if (shtory1 == "N") {
        shtory = false;
    }
    else {
        cout << "Error: íåïðàâèëüíûé ââîä äàííûõ";
        return 0;
    }

    string lampa1;
    cout << "Âêëþ÷åíâ ëè ëàìïà? Y/N ";
    cin >> lampa1;

    if (lampa1 == "Y") {
        lampa = true;
    }
    else if (lampa1 == "N") {
        lampa = false;
    }
    else {
        cout << "Error: íåïðàâèëüíûé ââîä äàííûõ";
        return 0;
    }

    if (chas <= 18 && chas >= 4) {
        if (shtory == true) {
            cout << "Ñâåòëî";
        }
        else if (shtory == false && lampa == true)
        {
            cout << "Ñâåòëî";
        }
        else {
            cout << "Òåìíî";
        }
    }
    else {
        if (lampa == true) {
            cout << "Ñâåòëî";
        }
        else {
            cout << "Òåìíî";
        }
    }


    return 0;
}

int main1() {
    setlocale(LC_ALL, "Russian");

    cout << "Àðèôìåòèêà \nÂâåäèòå x, y: ";
    arifmetika();
    cout << endl;

    cout << "Óðàâíåíèå bx + c = 0\nÂâåäèòå b, c: ";
    yravn();
    cout << " " << endl;

    cout << "Åùå óðàâíåíèå ax2 + bx + c = 0\nÂâåäèòå a, b, c: ";
    uravn2();
    cout << " " << endl;

    cout << "Ëàìïà ñî øòîðîé" << endl;
    lamp();
    return 0;
}
