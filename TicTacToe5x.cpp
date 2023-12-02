#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <map>
#include <utility>
using namespace std;

void Col(int txt) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(txt));
}

void setcur(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}

POINT getPosition(HWND hwnd) {
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(hwnd, &p);
	return p;
}

bool check(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord) {
	for (auto& item : coordmap)
	{
		pair<int, int> itempair = item.first;
		if (itempair.first == nowCoord.first && itempair.second == nowCoord.second) {
			return false;
		}
	}
	return true;
}

int check_N(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord, char symbol) {
	if (!(check(coordmap, nowCoord))) {
		if (coordmap[nowCoord] == symbol) {

			pair<int, int> northCoord;
			northCoord.first = nowCoord.first;
			northCoord.second = nowCoord.second - 1;

			return (1 + check_N(coordmap, northCoord, symbol));
		}
	}
	return 0;
}


int check_S(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord, char symbol) {
	if (!(check(coordmap, nowCoord))) {
		if (coordmap[nowCoord] == symbol) {

			pair<int, int> southCoord;
			southCoord.first = nowCoord.first;
			southCoord.second = nowCoord.second + 1;

			return (1 + check_S(coordmap, southCoord, symbol));
		}
	}
	return 0;
}

int check_E(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord, char symbol) {
	if (!(check(coordmap, nowCoord))) {
		if (coordmap[nowCoord] == symbol) {

			pair<int, int> eastCoord;
			eastCoord.first = nowCoord.first + 1;
			eastCoord.second = nowCoord.second;

			return (1 + check_E(coordmap, eastCoord, symbol));
		}
	}
	return 0;
}

int check_W(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord, char symbol) {
	if (!(check(coordmap, nowCoord))) {
		if (coordmap[nowCoord] == symbol) {

			pair<int, int> westCoord;
			westCoord.first = nowCoord.first - 1;
			westCoord.second = nowCoord.second;

			return (1 + check_W(coordmap, westCoord, symbol));
		}
	}
	return 0;
}

int check_NE(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord, char symbol) {
	if (!(check(coordmap, nowCoord))) {
		if (coordmap[nowCoord] == symbol) {

			pair<int, int> north_eastCoord;
			north_eastCoord.first = nowCoord.first + 1;
			north_eastCoord.second = nowCoord.second - 1;

			return (1 + check_NE(coordmap, north_eastCoord, symbol));
		}
	}
	return 0;
}

int check_SW(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord, char symbol) {
	if (!(check(coordmap, nowCoord))) {
		if (coordmap[nowCoord] == symbol) {

			pair<int, int> south_westCoord;
			south_westCoord.first = nowCoord.first - 1;
			south_westCoord.second = nowCoord.second + 1;

			return (1 + check_SW(coordmap, south_westCoord, symbol));
		}
	}
	return 0;
}

int check_SE(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord, char symbol) {
	if (!(check(coordmap, nowCoord))) {
		if (coordmap[nowCoord] == symbol) {

			pair<int, int> south_eastCoord;
			south_eastCoord.first = nowCoord.first + 1;
			south_eastCoord.second = nowCoord.second + 1;

			return (1 + check_SE(coordmap, south_eastCoord, symbol));
		}
	}
	return 0;
}

int check_NW(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord, char symbol) {
	if (!(check(coordmap, nowCoord))) {
		if (coordmap[nowCoord] == symbol) {

			pair<int, int> north_westCoord;
			north_westCoord.first = nowCoord.first - 1;
			north_westCoord.second = nowCoord.second - 1;

			return (1 + check_NW(coordmap, north_westCoord, symbol));
		}
	}
	return 0;
}

bool checkWin(map<pair<int, int>, char> coordmap, pair<int, int> nowCoord, char symbol) {
	if (check_N(coordmap, nowCoord, symbol) + check_S(coordmap, nowCoord, symbol) - 1 >= 5) {
		return true;
	}
	else if (check_E(coordmap, nowCoord, symbol) + check_W(coordmap, nowCoord, symbol) - 1 >= 5) {
		return true;
	}
	else if (check_NE(coordmap, nowCoord, symbol) + check_SW(coordmap, nowCoord, symbol) - 1 >= 5) {
		return true;
	}
	else if (check_SE(coordmap, nowCoord, symbol) + check_NW(coordmap, nowCoord, symbol) - 1 >= 5) {
		return true;
	}
	else {
		return false;
	}
}

void writeTable(pair<int, int> startpos, pair<int, int> size) {
	setcur(startpos.first, startpos.second);
	cout << '+';
	for (int i = startpos.first + 1; i < size.second + startpos.first - 1; i++) {
		setcur(i, startpos.second);
		cout << '-';
	}
	setcur(size.second + startpos.first - 1, startpos.second);
	cout << '+';

	setcur(startpos.first, startpos.second + size.first - 1);
	cout << '+';
	for (int i = startpos.first + 1; i < size.second + startpos.first - 1; i++) {
		setcur(i, startpos.second + size.first - 1);
		cout << '-';
	}
	setcur(size.second + startpos.first - 1, startpos.second + size.first - 1);
	cout << '+';

	for (int i = startpos.second + 1; i < startpos.second + size.first - 1; i++) {
		setcur(startpos.first, i);
		cout << '|';
	}
	for (int i = startpos.second + 1; i < startpos.second + size.first - 1; i++) {
		setcur(size.second + startpos.first - 1, i);
		cout << '|';
	}
}

int main() {
	pair<int, int> coords;
	map<pair<int, int>, char> coordinates;

	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну

	pair<int, int> startpos(4, 3);
	pair<int, int> size(10, 50);

	int headerWidth = 20;
	setcur((size.second / 2 - (headerWidth / 2) + 1) + startpos.first - 1, startpos.second - 2);
	cout << "---TIC TAC TOE 5x---";

	writeTable(startpos, size);

	string Player1name;
	string Player2name;

	setcur(startpos.first + 2, startpos.second + 3);
	Col(4);
	cout << "Player 1 (x):";
	setcur(startpos.first + 2, startpos.second + 6);
	Col(2);
	cout << "Player 2 (0):";
	Col(7);

	setcur(startpos.first + 16, startpos.second + 3);
	cin >> Player1name;
	setcur(startpos.first + 16, startpos.second + 6);
	cin >> Player2name;


	RECT WinCoord = {}; //Массив координат окна 
	GetWindowRect(hwnd, &WinCoord); //Узнаём координаты

	for (int y = 0; y <= WinCoord.right / 16; y++) {
		for (int x = 0; x <= WinCoord.right / 8; x++) {
			setcur(x, y);
			cout << '#';
		}
	}

	setcur(0, 0);

	char ch;
	int code;

	bool player = true; //x
	bool winnerFlag = true;

	while (winnerFlag)
	{
		ch = _getch();
		//code = static_cast<int>(ch);
		if (ch == 115) {
			char symbol;
			if (player) {
				Col(4);
				symbol = 'x';
			}
			else {
				Col(2);
				symbol = '0';
			}

			POINT p = getPosition(hwnd);
			int x = (p.x - 11) / 8 + 1;
			int y = (p.y - 21) / 16 + 1;
			setcur(x, y);
			coords.first = x;
			coords.second = y;

			if (check(coordinates, coords)) {
				coordinates[coords] = symbol;
				cout << symbol;
				if (checkWin(coordinates, coords, symbol)) {
					winnerFlag = false;

					for (int y = 0; y <= WinCoord.right / 16; y++) {
						for (int x = 0; x <= WinCoord.right / 8; x++) {
							setcur(x, y);
							cout << ' ';
						}
					}

					writeTable(startpos, size);

					setcur((size.second / 2 - 3 + 1) + startpos.first - 1, startpos.second + 3);
					cout << "WINNER";

					string winner;

					if (player) {
						winner = Player1name;
					}
					else {
						winner = Player2name;
					}

					int playerNameWidth = winner.size();

					setcur((size.second / 2 - (playerNameWidth / 2) + 1) + startpos.first - 1, startpos.second + 6);
					cout << winner;
				}
				player = !player;
			}
		}
	}

	setcur(0, startpos.second + size.first);

	return 0;
}