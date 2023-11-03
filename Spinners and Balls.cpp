#include <iostream>
#include <clocale>
using namespace std;

class Counter {
public:
    int get_count() {
        return cnt;
    }

    void plus_1() {
        cnt += 1;
    }
private:
    int cnt = 0;
};

void balls_permutation(int* m, int l, int n, Counter& counter)
{
    if (l == n - 1)
    {
        for (int i = 0; i < n; i++) {
            if (i + 1 == m[i]) {
                counter.plus_1();
                break;
            }
        }
    }
    else
    {
        for (int i = l; i < n; i++)
        {
            int tmp = m[l];
            m[l] = m[i];
            m[i] = tmp;
            balls_permutation(m, l + 1, n, counter);
            tmp = m[l];
            m[l] = m[i];
            m[i] = tmp;
        }
    }
}

void balls()
{
    Counter counter;
    int n = 10;
    int* m = new int[n];

    for (int i = 0; i < n; i++) {
        m[i] = i + 1;
    }

    balls_permutation(m, 0, n, counter);
    cout << "�����: " << counter.get_count() << endl;
}

int spinners_1() {
    int a, b, c;
    cout << "������� ��������� ��������� ��������, ��������� ����� ������� � ������������ ��������� ����� ��������: ";
    cin >> a >> b >> c;
    int n = (c - a) / b;
    cout << "n = " << n << endl;
    return 0;
}

int spinners_2() {
    int m;
    cout << "������� ���-�� ��������: ";
    cin >> m;
    int lop4 = m % 3;
    int lop3 = (m - 4 * lop4) / 3;
    if (lop3 >= 0) {
        cout << "���-�� �������� � ����� ���������: " << lop3 << endl;
        cout << "��� - �� �������� � ����� ���������: " << lop4 << endl;
    }
    else {
        cout << "���������� ���������� ������� ���, ����� ��������� ����� �������� ����: " << m << endl;
    }
    return 0;
}

int sasha() {
    int m, n;
    cout << "������� M � N: ";
    cin >> m >> n;
    int s = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int x = m - (i - 1);
            int y = n - (j - 1);
            s += x * y;
        }
    }
    cout << "���-��: " << s << endl;
    return 0;
}


int coupe_num(int k) {
    if (k > 36) {
        return 8 - (k - 37) / 2;
    }
    else {
        return (k - 1) / 4;
    }
}

int plackart() {
    int cupe[9] = { 0 };
    int mesto = 1000000;

    cout << "������� ������ ��������� ����: (����� ��������� ����, ������� 0)" << endl;

    while (mesto != 0) {
        cin >> mesto;
        cupe[coupe_num(mesto)] += 1;
    }

    int k = 0;

    for (int i = 0; i < 9; i++) {
        if (cupe[i] == 6) {
            k += 1;
        }
    }
    cout << "������ ����: " << k << endl;
    return 0;
}

int kino() {
    int n, k;
    cout << "������� ���-�� �������� � ���-�� ����������: ";
    cin >> n >> k;

    int iter = 0;

    while (pow(2, iter + 1) < k)
    {
        iter += 1;
    }

    bool chetnost = false;

    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    balls();
    spinners_1();
    spinners_2();
    sasha();
    plackart();
    return 0;
}