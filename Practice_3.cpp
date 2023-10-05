#include <iostream>;
#include <clocale>;
using namespace std;
#include <math.h>;
#include <fstream>;
#include <string>;
#include <Windows.h>;
#include <locale>;

int zaem(float S, float p, float n) { 
    float r = (p * 1.0) / 100;
    if (12 * (pow(1 + r, n) - 1) == 0) {
        cout << "Нет решения" << endl;
    }
    else {
        double m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        cout << "m = " << m << endl;
    }
    return 0;
}

int ssuda(float S, float m, float n) {
    for (float p = 0; p <= 100; p += 0.00001) {
        float r = p / 100;
        if ((12 * (pow(1 + r, n) - 1)) == 0) {
            continue;
        }
        else {
            double m_test = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
            if (abs(m - m_test) <= 0.01) {
                cout << "p = " << round(p) << endl;
                return 0;
            }
        }
    }
    cout << "Нет решения" << endl;
    return 0;
}


int open_file1() {
    ifstream in;
    in.open("C:/Users/Admin/Documents/mirea/Project1/Project1/1.txt");

    string line;

    if (in.is_open()) {
        while (!in.eof()) {
            line = "";
            getline(in, line);
            cout << line << endl;
        }
    }
    else {
        cout << "error" << endl;
    }

    in.close();
    return 0;
}

int open_file2() {
    ifstream F;
    F.open("C:/Users/Admin/Documents/mirea/Project1/Project1/1.txt");

    char i;

    if (F.is_open()) {
        while (F.get(i)) {
            if (i<='9' && i>=48) {
                cout << i;
            }
        }
    }
    else {
        cout << "error" << endl;
    }
    cout << " " << endl;
    return 0;
}


bool compareChars(char c1, char c2) {
    locale loc("ru_RU.UTF-8");
    if (c1 == 'ё') {
        char c = 'ж';
        if (tolower(c, loc) <= tolower(c2, loc)) {
            return false;
        }
        else if (c2 != 'ё') {
            return true;
        }
        else {
            return false;
        }
    }
    else if (c2 == 'ё') {
        char c = 'ж';
        if (tolower(c, loc) <= tolower(c1, loc)) {
            return true;
        }
        else if (c1 != 'ё') {
            return false;
        }
        else {
            return true;
        }
    }
    return tolower(c1, loc) > tolower(c2, loc);
}

void bubbleSort(string& str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (compareChars(str[j], str[j + 1])) {
                swap(str[j], str[j + 1]);
            }
        }
    }
}

int sort() {
    cout << "Введите строку для сортировки: ";
    string input;
    getline(cin, input);

    bubbleSort(input);

    cout << "Отсортированная строка: " << input << endl;

    return 0;
}



int main3() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //float S1, p, n1;
    //cout << "Введите S(займ), p(процент), n(срок): ";
    //cin >> S1 >> p >> n1;
    //zaem(S1, p, n1);
    //cout << " " << endl;


    //float S2, m, n2;
    //cout << "Введите S(займ), m(выплата), n(срок): ";
    //cin >> S2 >> m >> n2;
    //ssuda(S2, m, n2);
    //cout << " " << endl;


    //open_file1();
    //cout << " " << endl;


    //open_file2();
    //cout << " " << endl;

    sort();

    return 0;
}