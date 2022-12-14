#include <iostream>
#include <Windows.h>
#include <string>
#include "CFstruct.h"
#include "Table.h"
#include "figurs.h"
#include "controller.h"
#include "view.h"


using namespace std;

Controller controller;
View view;

int m_x(char ary[], char x);

int main()
{
	int hod = 1;

	int x, x_go, y, y_go;
	char buff;

	setlocale(LC_ALL, "Russian");
	view.set_col(color::red);
	std::cout << "Шахматы 0.1 v";
	std::cout << "\n";
	view.set_col();

print:
	std::cout << "Ход номер " << hod << "\n";

	if (hod % 2 == 1) {
		std::cout << "Ход белых" << "\n";
	}
	else {
		std::cout << "Ход черных" << "\n";
	}

	tableColor tableCs;
	view.tableVies(tableCs);

	std::cout << "Ваша фигура" << "\n";
	std::cin >> buff >> y;

	x = m_x(ary, buff) + 1;

	int nomber_f = tables.print(y - 1, x - 1);

	if (tables.print(y - 1, x - 1) == NULL) {
		std::cout << "Не ваша фигура" << "\n";

		goto print;
	}

	if (nomber_f % 2 != hod % 2) {
			std::cout << "Не ваша фигура" << "\n";
		goto print;
	}

	controller.goController(nomber_f, x, y, &tableCs);

	view.tableVies(tableCs);

	std::cout << "Ваш ход на позицию" << "\n";
	std::cin >> buff >> y_go;
	std::cout << "\n";

	x_go = m_x(ary, buff) + 1;

	if(tableCs.print(y_go-1, x_go-1) == 1){
		tables.going(y - 1, x - 1, y_go - 1, x_go-1);
		hod++;
	}
	goto print;

	return 0;
}

int m_x(char ary[], char x) {
	for (int q = 0; q < 8; q++) {
		if (ary[q] == x) {
			return q;
		}
	}
}
