#include <iostream>
#include <clocale>
using namespace std;
#include <climits> /* �������*/
#include <math.h>
#include <string>

int name() {
    for (int i = 0; i <= 5; i++) {
        std::cout << "�������\n";
    }
    return 0;
}


int stuff() {
    unsigned long long int x = 100000000000000;
    signed int y = -3;
    cout << x << " " << y << endl;
    return 0;

}

int arifmetika() { /* ���������� */
    float x;
    float y;
    cin >> x >> y;
    if (y == 0) {

        return 0;
    }
    cout << "�����: " << x + y << "\n������������: " << x * y << "\n��������: " << x - y << "\n�������: " << x / y << endl;
    return 0;
}

int yravn() {
    float b;
    float c;
    cin >> b >> c;
    if (b == 0 && c == 0) {
        cout << "���������� ����� �������";
    }
    else if (b == 0) {
        cout << "��� �������" << endl;
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
            cout << "��� ������" << endl;
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
            cout << "���������� ����� �������";
        }
        else if (a == 0 && b != 0 && c != 0) {
            cout << (-1 * c) / b;
        }
        else if (a != 0 && b == 0 && c != 0) {
            int x = (-1 * c) / a;
            if (x >= 0) {
                cout << "x1 = " << pow(x, 0.5) << "\nx2 = " << -1 * pow(x, 0.5);
            }
            else { cout << "��� �������"; }
        }
        else if (a != 0 && b != 0 && c == 0) {
            cout << "x1 = 0\nx2 == " << (-1 * b) / a;
        }
        else if (a == 0 && b == 0 && c != 0) {
            cout << "��� �������";
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

    cout << "������� ������ ���? ";
    cin >> chas;

    if (chas >= 23 || chas <= 0) {
        cout << "Error: �������������� ���";
        return 0;
    }

    string shtory1;
    cout << "������� �� �����? Y/N ";
    cin >> shtory1;

    if (shtory1 == "Y") {
        shtory = true;
    }
    else if (shtory1 == "N") {
        shtory = false;
    }
    else {
        cout << "Error: ������������ ���� ������";
        return 0;
    }

    string lampa1;
    cout << "�������� �� �����? Y/N ";
    cin >> lampa1;

    if (lampa1 == "Y") {
        lampa = true;
    }
    else if (lampa1 == "N") {
        lampa = false;
    }
    else {
        cout << "Error: ������������ ���� ������";
        return 0;
    }

    if (chas <= 18 && chas >= 4) {
        if (shtory == true) {
            cout << "������";
        }
        else if (shtory == false && lampa == true)
        {
            cout << "������";
        }
        else {
            cout << "�����";
        }
    }
    else {
        if (lampa == true) {
            cout << "������";
        }
        else {
            cout << "�����";
        }
    }


    return 0;
}

int main1() {
    setlocale(LC_ALL, "Russian");

    cout << "���������� \n������� x, y: ";
    arifmetika();
    cout << endl;

    cout << "��������� bx + c = 0\n������� b, c: ";
    yravn();
    cout << " " << endl;

    cout << "��� ��������� ax2 + bx + c = 0\n������� a, b, c: ";
    uravn2();
    cout << " " << endl;

    cout << "����� �� ������" << endl;
    lamp();
    return 0;
}