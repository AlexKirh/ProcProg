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

    matrix();
    cout << " " << endl;

    return 0;
}