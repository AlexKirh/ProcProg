#include <iostream>
#include <cmath>
#include <clocale>;
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <algorithm>
#include <iomanip>;
using namespace std;

int evclid() {
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;

    int gcd_div = 1;
    for (int i = 2; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            gcd_div = i;
        }
    }

    int gcd_sub = 1;
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
        gcd_sub = a;
    }

    cout << "Наибольший общий делитель с помощью деления: " << gcd_div << endl;
    cout << "Наибольший общий делитель с помощью вычитания: " << gcd_sub << endl;

    return 0;
}

int eretocfen() {
    int n;
    cout << "Введите натуральное число: ";
    cin >> n;

    cout << "Простые числа в диапазоне от 2 до " << n << ":" << endl;
    for (int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            cout << i << " ";
        }
    }
    return 0;
}

int askii() {
    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    string ascii_codes;
    for (char c : text) {
        ascii_codes += to_string(int(c)) + " ";
    }

    cout << "Цепочка ASCII-кодов: " << ascii_codes << endl;

    return 0;
}

int setInFile() {
    ofstream file;
    file.open("textfile.txt");

    if (!file.is_open()) {
        cerr << "Невозможно открыть файл для записи" << endl;
        return 1;
    }

    string line = "_";
    while (getline(cin, line) && line != "") {
        file << line << endl;
    }

    file.close();
    return 0;
}

int riadi1() {
    int n;
    cout << "Введите n: ";
    cin >> n;

    double a;
    cout << "Введите a:";
    cin >> a;

    long double x = 0.0;
    for (int i = 1; i <= n + 1; i++) {
        double chislitel = i;
        long double znamenatel = a;
        for (int j = 1; j <= i - 1; j++) {
            znamenatel *= (a + j);
        }
        x += (chislitel / znamenatel);
    }
    cout << "y = " << x;

    return 0;
}

int riad2() {
    double numbers[5];
    double sum = 0;
    double average;

    for (int i = 0; i < 5; i++) {
        std::cout << "Введите " << i + 1 << " число: ";
        std::cin >> numbers[i];

        sum += numbers[i];
        average = sum / (i + 1);

        std::cout << "Среднее арифметическое полученной части последовательности: " << average << std::endl;
    }

    return 0;
}

int olimp() {
    ofstream file;
    file.open("Olimpiada.txt");


    if (!file.is_open()) {
        cerr << "Невозможно открыть файл для записи" << endl;
        return 1;
    }

    string line;
    while (line != "Y") {
        string CountryName;
        cout << "Введите название страны: ";
        cin >> CountryName;

        int golds;
        cout << "Введите кол-во золота: ";
        cin >> golds;

        int silver;
        cout << "Введите кол-во серебра: ";
        cin >> silver;

        int bronze;
        cout << "Введите кол-во бронзы: ";
        cin >> bronze;

        string zapis = CountryName + " " + to_string(golds) + " " + to_string(silver) + " " + to_string(bronze) + " " + to_string(golds * 7 + silver * 6 + bronze * 5);

        file << zapis << endl;

        cout << "Команды кончились? Y/N: ";
        cin >> line;
    }
    file.close();


    map<int, string> countries;

    ifstream in;
    in.open("D:/mirea/Project1/Project1/Olimpiada.txt");

    while (!in.eof())
    {
        string str;
        getline(in, str);
        string points_S = str.substr(str.rfind(" ") + 1, size(str));
        int points = atoi(points_S.c_str());
        if (points != 0) {
            countries[1000000000 - points] = str;
        }
    }
    in.close();


    ofstream offile;
    offile.open("D:/mirea/Project1/Project1/Olimpiada.txt", std::ofstream::out | std::ofstream::trunc);

    for (auto& i : countries) {
        offile << i.second << endl;
    }
    offile << "$";
    offile.close();


    ifstream in2;
    in2.open("D:/mirea/Project1/Project1/Olimpiada.txt");

    cout << setw(10) << " " << setw(10) << "Страна" << setw(10) << "Золото" << setw(10) << "Серебро" << setw(10) << "Бронза" << endl;

    int counter = 0;
    while (!in2.eof())
    {
        string s;
        getline(in2, s);

        if (s != "$") {
            counter++;
            cout << setw(10) << counter;

            string delimiter = " ";
            size_t pos = 0;
            string token;
            while ((pos = s.find(delimiter)) != string::npos) {
                token = s.substr(0, pos);
                cout << setw(10) << token;
                s.erase(0, pos + delimiter.length());
            }

            cout << endl;
        }
    }

    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    /*
    evclid();

    eretocfen();

    askii();

    setInFile();

    riadi1();

    riad2();*/

    olimp();

    return 0;
}