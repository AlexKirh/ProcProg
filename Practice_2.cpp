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

<<<<<<< HEAD
    cout << "Введите высоту, Верхний радиус, нижний радиус: ";
    cin >> h >> R >> r;

    if (h <= 0 || R <= 0 || r <= 0) {
        cout << "Неправильно введены данные" << endl;
        return 0;
    }
    else if (r >= R) {
        cout << "входые данные не образуют усеченный конус" << endl;
=======
    cout << "Ââåäèòå âûñîòó, Âåðõíèé ðàäèóñ, íèæíèé ðàäèóñ: ";
    cin >> h >> R >> r;

    if (h <= 0 || R <= 0 || r <= 0) {
        cout << "Íåïðàâèëüíî ââåäåíû äàííûå" << endl;
        return 0;
    }
    else if (r >= R) {
        cout << "âõîäûå äàííûå íå îáðàçóþò óñå÷åííûé êîíóñ" << endl;
>>>>>>> 04bdcfa06d8d53fd785dd3ae86cf1af476143853
        return 0;
    }

    float l = pow(pow(R - r, 2) + pow(h, 2), 0.5);
    double V = (M_PI * h * (R * R + R * r + r * r)) / 3;
    double S = M_PI * (R * R + (R + r) * l + r * r);
<<<<<<< HEAD
    cout << setprecision(15) << "Объем = " << V << "\nПлощадь = " << S << endl;
=======
    cout << setprecision(15) << "Îáúåì = " << V << "\nÏëîùàäü = " << S << endl;
>>>>>>> 04bdcfa06d8d53fd785dd3ae86cf1af476143853
    return 0;
}

int razvetvlenie() {
    int x;
    int a;

<<<<<<< HEAD
    cout << "Введите x и a: ";
    cin >> x >> a;

    if (x == 0) {
        cout << "х не может быть равен нулю" << endl;
=======
    cout << "Ââåäèòå x è a: ";
    cin >> x >> a;

    if (x == 0) {
        cout << "õ íå ìîæåò áûòü ðàâåí íóëþ" << endl;
>>>>>>> 04bdcfa06d8d53fd785dd3ae86cf1af476143853
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
<<<<<<< HEAD
        cout << "Нет решений" << endl;
=======
        cout << "Íåò ðåøåíèé" << endl;
>>>>>>> 04bdcfa06d8d53fd785dd3ae86cf1af476143853
        return 0;
    }
    return 0;
}

int func() {
    int x;
    int y;
    int b;

<<<<<<< HEAD
    cout << "Введите х, y, b: ";
=======
    cout << "Ââåäèòå õ, y, b: ";
>>>>>>> 04bdcfa06d8d53fd785dd3ae86cf1af476143853
    cin >> x >> y >> b;

    if (b - y > 0 && b - x >= 0) {
        cout << log(b - y) * pow(b - x, 0.5) << endl;
        return 0;
    }
    else {
<<<<<<< HEAD
        cout << "Нет решений" << endl;
=======
        cout << "Íåò ðåøåíèé" << endl;
>>>>>>> 04bdcfa06d8d53fd785dd3ae86cf1af476143853
        return 0;
    }
    return 0;
}

int poriadok() {
    int N;
<<<<<<< HEAD
    cout << "Введите N: ";
=======
    cout << "Ââåäèòå N: ";
>>>>>>> 04bdcfa06d8d53fd785dd3ae86cf1af476143853
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
