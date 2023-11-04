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
    cout << "Наибольший общий делитель с помощью вычитания: " << gcd_sub;

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
    cin >> text;

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
    cout << "Введите строки для ввода в файл:";
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
    cout << "Введите a: ";
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
    int n = 0;
    for (int i = 0; i < 5; i++) {
        std::cout << "Введите " << i + 1 << " число: ";
        std::cin >> numbers[i];

        sum += numbers[i];
        average = sum / (i + 1);
        n += 1;

        std::cout << "Ведено чисел: " << n << " " << "Сумма = " << sum << " " << "Среднее арифметическое полученной части последовательности: " << average << std::endl;
    }

    return 0;
}


int matrix() {
    int N = 0;
    cout << "Введите порядок для матриц: ";
    cin >> N;


    int** A = new int* [N];

    for (int i = 0; i < N; i++) {
        A[i] = new int[N];
    }

    int** B = new int* [N];

    for (int i = 0; i < N; i++) {
        B[i] = new int[N];
    }

    int** E = new int* [N];

    for (int i = 0; i < N; i++) {
        E[i] = new int[N];
    }

    double** C = new double* [N];

    for (int i = 0; i < N; i++) {
        C[i] = new double[N];
    }

    double** res = new double* [N];

    for (int i = 0; i < N; i++) {
        res[i] = new double[N];
    }

    int** res2 = new int* [N];

    for (int i = 0; i < N; i++) {
        res2[i] = new int[N];
    }

    ////////////////////////////////////////// заполнение

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 50;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = rand() % 50;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                E[i][j] = 1;
            }
            else {
                E[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 1.0 / (i + j + 2);
        }
    }
    ////////////////////////////////////////// вывод

    cout << "Матрица А:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << " " << endl;

    cout << "Матрица B:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    cout << " " << endl;

    cout << "Матрица E:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << E[i][j] << "\t";
        }
        cout << endl;
    }
    cout << " " << endl;

    cout << "Матрица C:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setprecision(3) << C[i][j] << "\t";
        }
        cout << endl;
    }
    cout << " " << endl;

    ////////////////////////////////////////// вычисления

    cout << "Матрица B - E:" << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = B[i][j] - E[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    cout << " " << endl;


    cout << "Матрица A(B - E):" << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int pr = 0;
            for (int k = 0; k < N; k++) {
                pr += A[i][k] * res[k][j];
            }
            res2[i][j] = pr;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << res2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << " " << endl;


    cout << "Матрица A(B - E) - C:" << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double x = res[i][j];
            double y = C[i][j];
            res[i][j] = x - y;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    cout << " " << endl;

    ////////////////////////////////////////// запись в файл

    ofstream file;
    file.open("Matrix.txt");

    file << "Матрица А:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file << A[i][j] << "\t";
        }
        file << endl;
    }
    file << " " << endl;

    file << "Матрица B:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file << B[i][j] << "\t";
        }
        file << endl;
    }
    file << " " << endl;

    file << "Матрица E:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file << E[i][j] << "\t";
        }
        file << endl;
    }
    file << " " << endl;

    file << "Матрица C:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file << setprecision(3) << C[i][j] << "\t";
        }
        file << endl;
    }
    file << " " << endl;

    file << "Матрица A(B - E) - C:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file << res[i][j] << "\t";
        }
        file << endl;
    }

    file.close();

    ////////////////////////////////////////// очистка

    for (int i = 0; i < N; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
        delete[] E[i];
        delete[] res[i];
        delete[] res2[i];
    }

    delete[] A;
    delete[] B;
    delete[] E;
    delete[] C;
    delete[] res;
    delete[] res2;

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


    map<double, string> countries;

    ifstream in;
    in.open("C:/Users/Admin/Documents/mirea/Project3/Project3/Olimpiada.txt");

    while (!in.eof())
    {
        string str;
        getline(in, str);
        string points_S = str.substr(str.rfind(" ") + 1, size(str));
        double points = atoi(points_S.c_str());

        if (points != 0) {
            if (countries.count(1000000000.0 - points)) {
                while (countries.count(1000000000.0 - points))
                {
                    points -= 0.000001;
                }
                countries[1000000000.0 - points] = str;
            }
            else {
                countries[1000000000.0 - points] = str;
            }
        }
    }
    in.close();


    ofstream offile;
    offile.open("C:/Users/Admin/Documents/mirea/Project3/Project3/Olimpiada.txt", std::ofstream::out | std::ofstream::trunc);

    for (auto& i : countries) {
        offile << i.second << endl;
    }
    offile << "$";
    offile.close();


    ifstream in2;
    in2.open("C:/Users/Admin/Documents/mirea/Project3/Project3/Olimpiada.txt");

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
    in2.close();
    return 0;
}



int main() {
    setlocale(LC_ALL, "Russian");

    setInFile();
    cout << " " << endl;

    evclid();
    cout << " " << endl;

    eretocfen();
    cout << " " << endl;

    askii();
    cout << " " << endl;

    riadi1();
    cout << " " << endl;

    riad2();
    cout << " " << endl;
     
    olimp();
    cout << " " << endl;

    matrix();
    cout << " " << endl;

    return 0;
}