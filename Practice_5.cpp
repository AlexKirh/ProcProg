#include <iostream>;
#include <clocale>;
using namespace std;


int kino() {
    int n, k;
    cout << "Введите кол-во сиденьев и кол-во школьников: ";
    cin >> n >> k;

    int iter = 0;

    while (pow(2, iter + 1) < k)
    {
        iter += 1;
    }

    bool chetnost = (n%2 == 0);
    cout << chetnost;
    
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