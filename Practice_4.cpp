using namespace std;
#include <iostream>;
#include <clocale>;
#include <fstream>;
#include <stdlib.h>;
#include <cmath>;
#define _USE_MATH_DEFINES
#include <math.h>;
#include <windows.h>;
#include <algorithm> 
#include <array>
#include <iomanip>;

int file() {
    ofstream outFile("numbers.txt");

    if (outFile.is_open()) {
        int numbers[10];

        for (int i = 1; i <= 10; ++i) {
            int n = rand() % 100 + 1;
            outFile << n << " ";
            numbers[i - 1] = n;
        }

        outFile.close();
        cout << "Ôàéë óñïåøíî ñîçäàí è ÷èñëà çàïèñàíû.\n×èñëà: ";
        for (int i = 0; i < 10; i++)
        {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Îøèáêà ïðè îòêðûòèè ôàéëà äëÿ çàïèñè." << endl;
        return 0;
    }

    ifstream inFile("numbers.txt");

    if (inFile.is_open()) {
        int number, sum = 0;

        while (inFile >> number) {
            sum += number;
        }

        inFile.close();

        cout << "Ñóììà ÷èñåë: " << sum << endl;
    }
    else {
        cout << "Îøèáêà ïðè îòêðûòèè ôàéëà äëÿ ÷òåíèÿ." << endl;
        return 0;
    }

    return 0;
}



int sign(float x) {
    if (x > 0) {
        cout << 1 << endl;
    }
    else if (x < 0) {
        cout << -1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}



double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateCircleArea(double radius) {
    return M_PI * pow(radius, 2);
}

int areas() {
    double length, width, base, height, radius;
    
    int c;
    cout << "Êàêóþ ïëîùàäü ñ÷èòàåì? 1 - ïðÿìîóãîëüíèê, 2 = òðåóãîëüíèê, 3 - êðóã: ";
    cin >> c;

    switch (c)
    {
        case 1:
        {
            cout << "Ââåäèòå äëèíó è øèðèíó ïðÿìîóãîëüíèêà: ";
            cin >> length >> width;
            double rectangleArea = calculateRectangleArea(length, width);
            cout << "Ïëîùàäü ïðÿìîóãîëüíèêà: " << rectangleArea << endl;
            break;
        }

        case 2:
        {
            cout << "Ââåäèòå îñíîâàíèå è âûñîòó òðåóãîëüíèêà: ";
            cin >> base >> height;
            double triangleArea = calculateTriangleArea(base, height);
            cout << "Ïëîùàäü òðåóãîëüíèêà: " << triangleArea << endl;
            break;
        }
        case 3:
        {
            cout << "Ââåäèòå ðàäèóñ êðóãà: ";
            cin >> radius;
            double circleArea = calculateCircleArea(radius);
            cout << "Ïëîùàäü êðóãà: " << circleArea << endl;
            break;
        }
        default: break;
    }
    return 0;
}


int whiteGlory() {
    for (int i = 0; i < 13; i++) {
        if (i < 8) {
            for (int j = 0; j < 6; j++) {
                cout << "  *";
            }
            for (int j = 0; j < 26; j++) {
                cout << "_";
            }
        }
        else {
            for (int j = 0; j < 44; j++) {
                cout << "_";
            }
        }
        cout << endl;
    }
    return 0;

}




void gotoxy(int x, int y) {
    COORD xy;
    xy.X = x;
    xy.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

int sinus() {
    for (double x = -10; x < 10; x += 0.1) {
        int y = round((sin(x) * 10) + 52);
        gotoxy(round(x * 10), y);
        cout << '*';
    }
    for (int i = 0; i < 120; i++) {
        gotoxy(i, 22);
        cout << ' ';
    }
    gotoxy(0, 24);
    return 0;
}



int RomeToArabic() {
    string s;
    cout << "Ââåäèòå ðèìñêîå ÷èñëî: ";
    cin >> s;
    char letters[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

    for (int i = 0; i < size(s); i++) {
        bool exist = count(begin(letters), end(letters), s[i]) > 0;
        if (exist) {
            continue;
        }
        else {
            cout << "Íåïðàâèëüíûé ââîä" << endl;
            return 0;
        }
    }

    int fin = 0;

    for (int i = 0; i < size(s); i++) {
        int n = i - 1;
        int m = i + 1;

        if (n < 0) {
            n += 1;
        }
        if (m >= size(s)) {
            m -= 1;
        }

        if (s[i] == 'I' and s[m] != 'V' and s[m] != 'X') {
            fin += 1;
        }
        else if (s[i] == 'I' and s[m] == 'X') {
            fin += 9;
            i++;
        }
        else if (s[i] == 'I' and s[m] == 'V') {
            fin += 4;
            i++;
        }
        else if (s[i] == 'X' and s[n] != 'I') {
            fin += 10;
        }
        else if (s[i] == 'V' and s[n] != 'I') {
            fin += 5;
        }
        else if (s[i] == 'L' and s[n] != 'I' and s[n] != 'V' and s[n] != 'X') {
            fin += 50;
        }
        else if (s[i] == 'C' and s[n] != 'I' and s[n] != 'V' and s[n] != 'X' and s[n] != 'L') {
            fin += 100;
        }
        else if (s[i] == 'D' and s[n] != 'I' and s[n] != 'V' and s[n] != 'X' and s[n] != 'L' and s[n] != 'C') {
            fin += 500;
        }
        else if (s[i] == 'M' and s[n] != 'I' and s[n] != 'V' and s[n] != 'X' and s[n] != 'L' and s[n] != 'C' and s[n] != 'D') {
            fin += 1000;
        }
        else {
            cout << "Íåïðàâèëüíûé ââîä ÷èñëà: " << i + 1 << endl;
            return 0;
        }
    }
    cout << fin << endl;
    return 0;
}



int generator() {
    int m, b, c, i;
    cout << "Ââåäèòå m, b, c, i: ";
    cin >> m >> b >> c >> i;

    int* chisla{ new int[i] {0} };

    for (int j = 0; j <= i; j++) {
        chisla[j + 1] = (m * chisla[j] + b) % c;
    }

    cout << chisla[i] << endl;
    return 0;
}



int matrix() {
    double A[3][4] = {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0}
    };

    double B[4][2] = {
        {1.20, 0.50},
        {2.80, 0.40},
        {5.00, 1.00},
        {2.00, 1.50}
    };

    double C[3][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << setw(4) << C[i][j] << "  ";
        }
        cout << endl;
    }


    int highSeller = 0;
    int lowSeller = 0;
    float maxProfit = 0;
    float minProfit = 10000000;

    for (int i = 0; i < 3; i++) {
        if (C[i][0] > maxProfit) {
            maxProfit = C[i][0];
            highSeller = i + 1;
        }
        else if (C[i][0] < minProfit) {
            minProfit = C[i][0];
            lowSeller = i + 1;
        }
    }

    cout << "Ïðîäàâåö " << highSeller << " âûðó÷èë áîëüøå âñåãî äåíåã ñ ïðîäàæè: " << maxProfit << "\nÏðîäàâåö " << lowSeller << " âûðó÷èë ìåíüøå âñåãî äåíåã ñ ïðîäàæè: " << minProfit << endl;


    int highSeller2 = 0;
    int lowSeller2 = 0;
    float maxComm = 0;
    float minComm = 10000000;

    for (int i = 0; i < 3; i++) {
        if (C[i][1] > maxComm) {
            maxComm = C[i][1];
            highSeller2 = i + 1;
        }
        else if (C[i][1] < minComm) {
            minComm = C[i][1];
            lowSeller2 = i + 1;
        }
    }

    cout << "Ïðîäàâåö " << highSeller2 << " âûðó÷èë áîëüøå âñåãî êîìèñèîííûõ ñ ïðîäàæè: " << maxComm << "\nÏðîäàâåö " << lowSeller2 << " âûðó÷èë ìåíüøå âñåãî êîìèñèîííûõ ñ ïðîäàæè: " << minComm << endl;


    double money = 0;
    for (int i = 0; i < 3; i++) {
        money += C[i][0];
    }
    cout << "Îáùàÿ ñóììà äåíåã, âûðó÷åííûõ çà ïðîäàííûå òîâàðû: " << money << endl;


    double coms = 0;
    for (int i = 0; i < 3; i++) {
        coms += C[i][1];
    }
    cout << "Âñåãî êîìèññèîííûõ ïðîäàâöû ïîëó÷èëè: " << coms << endl;


    cout << "Îáùàÿ ñóììà äåíåã, ïðîøåäøàÿ ðóêè ïðîäàâöîâ: " << coms + money << endl;

    return 0;
}



int char_to_int(char symbol) {
    switch (symbol) {
    case '0': return 0; break;
    case '1': return 1; break;
    case '2': return 2; break;
    case '3': return 3; break;
    case '4': return 4; break;
    case '5': return 5; break;
    case '6': return 6; break;
    case '7': return 7; break;
    case '8': return 8; break;
    case '9': return 9; break;
    case 'A': return 10; break;
    case 'B': return 11; break;
    case 'C': return 12; break;
    case 'D': return 13; break;
    case 'E': return 14; break;
    case 'F': return 15; break;
    case 'G': return 16; break;
    case 'H': return 17; break;
    case 'I': return 18; break;
    case 'J': return 19; break;
    case 'K': return 20; break;
    case 'L': return 21; break;
    case 'M': return 22; break;
    case 'N': return 23; break;
    case 'O': return 24; break;
    case 'P': return 25; break;
    case 'Q': return 26; break;
    case 'R': return 27; break;
    case 'S': return 28; break;
    case 'T': return 29; break;
    case 'U': return 30; break;
    case 'V': return 31; break;
    case 'W': return 32; break;
    case 'X': return 33; break;
    case 'Y': return 34; break;
    case 'Z': return 35; break;

    }
    return -1;
}


string int_to_char(int symbol) {
    switch (symbol) {
    case 0: return "0"; break;
    case 1: return "1"; break;
    case 2: return "2"; break;
    case 3: return "3"; break;
    case 4: return "4"; break;
    case 5: return "5"; break;
    case 6: return "6"; break;
    case 7: return "7"; break;
    case 8: return "8"; break;
    case 9: return "9"; break;
    case 10: return "A"; break;
    case 11: return "B"; break;
    case 12: return "C"; break;
    case 13: return "D"; break;
    case 14: return "E"; break;
    case 15: return "F"; break;
    case 16: return "G"; break;
    case 17: return "H"; break;
    case 18: return "I"; break;
    case 19: return "J"; break;
    case 20: return "K"; break;
    case 21: return "L"; break;
    case 22: return "M"; break;
    case 23: return "N"; break;
    case 24: return "O"; break;
    case 25: return "P"; break;
    case 26: return "Q"; break;
    case 27: return "R"; break;
    case 28: return "S"; break;
    case 29: return "T"; break;
    case 30: return "U"; break;
    case 31: return "V"; break;
    case 32: return "W"; break;
    case 33: return "X"; break;
    case 34: return "Y"; break;
    case 35: return "Z"; break;

    }
    return "";
}

int converter() {
    string x;
    int ss_in, ss_out;
    cout << "Ââåäèòå ÷èñëî, åãî ÑÑ ì CC, â êîòðóþ íóæíî ïåðåâåñòè: ";
    cin >> x >> ss_in >> ss_out;

    int decX = 0;
    for (int i = 0; i < size(x); i++) {
        decX += char_to_int(x[i]) * pow(ss_in, size(x) - i - 1);
    }

    string ssOutX = "";
    while (decX > 0) {
        ssOutX += int_to_char(decX % ss_out);
        decX /= ss_out;
    }
    reverse(ssOutX.begin(), ssOutX.end());
    cout << ssOutX << endl;
    return 0;
}

#include <iostream>
using namespace std;



int main4() {
    setlocale(LC_ALL, "Russian");
    /*file();

    float x;
    cout << "Ââåäèòå x: ";
    cin >> x;
    sign(x);

    areas();*/

    whiteGlory();
    /*sinus();
    RomeToArabic();
    generator();
    converter();
    gotoxy(0, 65);*/
    return 0;

}
