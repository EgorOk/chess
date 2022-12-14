#pragma once
const unsigned int STRK = 8;
const unsigned int STLB = 8;

// Доска
class table {
public:
	int print(int STRK, int STLB) {
		return tabl[STRK][STLB];
	};
	void going(int STRK, int STLB, int STRK_GO, int STLB_GO) {
		tabl[STRK_GO][STLB_GO] = tabl[STRK][STLB];
		tabl[STRK][STLB] = NULL;
	};

private:
	int tabl[STRK][STLB] = {
	{4, 12, 6, 2, 8, 6, 12, 4},
	{10, 10, 10, 10, 10, 10, 10, 10},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{11, 11, 11, 11, 11, 11, 11, 11},
	{5, 13, 7, 3, 9, 7, 13, 5} };
};

class tableColor {
public:
	int print(int STRK, int STLB) {
		return tabl[STRK][STLB];
	};

	void perecras(int STRK, int STLB) {
		tabl[STRK][STLB] = 1;
	};

	void perecrasF(int STRK, int STLB) {
		tabl[STRK][STLB] = 2;
	};

private:
	int tabl[STRK][STLB] = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0} };
};