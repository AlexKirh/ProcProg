#include <iostream>
#include <cmath>
#include <clocale>;
#include <string>
#include <fstream>
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
    std::ofstream file;
    file.open("textfile.txt");

    if (!file.is_open()) {
        std::cerr << "Невозможно открыть файл для записи" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(std::cin, line)) {
        file << line << std::endl;
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

int main() {
    setlocale(LC_ALL, "Russian");
    /*
    evclid();

    eretocfen();

    askii();

    setInFile();*/

    riadi1();

    return 0;
}