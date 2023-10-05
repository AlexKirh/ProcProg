#include <iostream>;
#include <clocale>;
using namespace std;

#define _USE_MATH_DEFINES
#include <math.h>;
#include <cmath>;
#include <iomanip>;

int konus() {
    float h; 
    float R;
    float r;

    cout << "Введите высоту, Верхний радиус, нижний радиус: ";
    cin >> h >> R >> r;

    if (h <= 0 || R <= 0 || r <= 0) {
        cout << "Неправильно введены данные" << endl;
        return 0;
    }
    else if (r >= R) {
        cout << "входые данные не образуют усеченный конус" << endl;
        return 0;
    }

    float l = pow(pow(R - r, 2) + pow(h, 2), 0.5);
    double V = (M_PI * h * (R * R + R * r + r * r)) / 3;
    double S = M_PI * (R * R + (R + r) * l + r * r);
    cout << setprecision(15) << "Объем = " << V << "\nПлощадь = " << S << endl;
    return 0;
}

int razvetvlenie() {
    int x;
    int a;

    cout << "Введите x и a: ";
    cin >> x >> a;

    if (x == 0) {
        cout << "х не может быть равен нулю" << endl;
        return 0;
    }

    if (abs(x) < 1) {
        cout << "w = " << a * log(abs(x)) << endl;
        return 0;
    }
    else if ((a - x * x) >= 0) {
        cout << "w = " << pow(a - x * x, 0.5) << endl;
        return 0;
    }
    else {
        cout << "Нет решений" << endl;
        return 0;
    }
    return 0;
}

int func() {
    int x;
    int y;
    int b;

    cout << "Введите х, y, b: ";
    cin >> x >> y >> b;

    if (b - y > 0 && b - x >= 0) {
        cout << log(b - y) * pow(b - x, 0.5) << endl;
        return 0;
    }
    else {
        cout << "Нет решений" << endl;
        return 0;
    }
    return 0;
}

int poriadok() {
    int N;
    cout << "Введите N: ";
    cin >> N;

    if (N <= 0) {
        for (int i = 1; i < 11; i++) {
            cout << i << endl;
        }
        return 0;
    }
    else {
        for (int n = N; n < N + 10; n++) {
            cout << n << endl;
        }
        return 0;
    }
}

int tabulation() {
    for (float x = -4; x <= 4; x += 0.5) {
        double y = (pow(x, 2) - 2 * x + 2) / (x - 1);
        cout << setprecision(4) << "f(" << setw(2) << x << ") = " << setw(6) << y << "  ";
        if (floor(x) != x) {
            cout << "\n";
        }
    }
    cout << endl;
    return 0;
}

int main2() {
    setlocale(LC_ALL, "Russian");
    konus();
    razvetvlenie();
    func();
    poriadok();
    tabulation();
    return 0;
}