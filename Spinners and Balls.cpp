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
    cout << "Ответ: " << counter.get_count() << endl;
}

int spinners_1() {
    int a, b, c;
    cout << "Введите стоимость основания спиннера, стоимость одной лопасти и максимальная стоимость всего спиннера: ";
    cin >> a >> b >> c;
    int n = (c - a) / b;
    cout << "n = " << n << endl;
    return 0;
}

int spinners_2() {
    int m;
    cout << "Введите кол-во ллпастей: ";
    cin >> m;
    int lop4 = m % 3;
    int lop3 = (m - 4 * lop4) / 3;
    if (lop3 >= 0) {
        cout << "Кол-во спинеров с тремя лопастями: " << lop3 << endl;
        cout << "Кол - во спинеров с тремя лопастями: " << lop4 << endl;
    }
    else {
        cout << "невозможно произвести спинеры так, чтобы суммарное число лопастей было: " << m << endl;
    }
    return 0;
}

int sasha() {
    int m, n;
    cout << "Введите M и N: ";
    cin >> m >> n;
    int s = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int x = m - (i - 1);
            int y = n - (j - 1);
            s += x * y;
        }
    }
    cout << "Кол-во: " << s << endl;
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

    cout << "Вводите номера свободных мест: (чтобы закончить ввод, введите 0)" << endl;

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
    cout << "Пустых купэ: " << k << endl;
    return 0;
}

int kino() {
    int n, k;
    cout << "Введите кол-во сиденьев и кол-во школьников: ";
    cin >> n >> k;

    if (k > n) {
        cout << "Мест не хватило" << endl;
        return 0;
    }

    vector<int> promezutki{ n };

    int left = 0;
    int right = 0;

    for (int i = 0; i < k; i++) {
        int max_l = promezutki.back();

        left = max_l / 2;
        right = (max_l != 1) ? ((max_l % 2 != 0) ? max_l / 2 : max_l / 2 - 1) : (0);
        promezutki[promezutki.size() - 1] = right;
        promezutki.push_back(left);

        sort(promezutki.begin(), promezutki.end());
    }
    cout << "Мест с одной стороны: " << right << " С другой: " << left;
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    balls();
    spinners_1();
    spinners_2();
    sasha();
    plackart();
    kino();
    return 0;
}