#pragma once
FiguraStruct f;
table tables;
tableColor tableColors;

class Figura {
public:
	Figura(std::string name = 0, int value = 0) :name(name), value(value) {}

	std::string nameFigura() {
		return name;
	};

	bool cong_hod(int positionX, int positionY, int colorfigura, tableColor* tc, table tabls = tables) {
		if ((positionY >= 0 && positionY < 8) && (positionX >= 0 && positionX < 8)) {

			if (tabls.print(positionY, positionX) != NULL && tabls.print(positionY, positionX) % 2 == colorfigura) {
				return false;
			}

			if (tabls.print(positionY, positionX) != NULL && tabls.print(positionY, positionX) % 2 != colorfigura) {
				tc->perecras(positionY, positionX);
				return false;
			}
				tc->perecras(positionY, positionX);
				return true;
			}
		return false;
	}

protected:
	std::string name;
	int value;
};

//пешка
class Pawn : public Figura {
public:
	Pawn(std::string name = f.Pw, int value = 1) :Figura(name, value)
	{
	}

	std::string nameFigura() {
		return name;
	};

	void going(int positionX, int positionY, tableColor* tc = &tableColors, table tabls = tables) {
		int colorfigura = tabls.print(positionY, positionX) % 2;

		tc->perecrasF(positionY, positionX);

		int q = 1;
		//первый ход
		if (positionY == 6 || positionY == 1) {
			q = 2;
		}

		if (colorfigura == 1) {
			if ((tabls.print(positionY - 1, positionX - 1) % 2) != colorfigura && tabls.print(positionY - 1, positionX - 1) != NULL && positionX - 1 >= 0) {
				tc->perecras(positionY - 1, positionX - 1);
			}

			if ((tabls.print(positionY - 1, positionX + 1) % 2) != colorfigura && tabls.print(positionY - 1, positionX + 1) != NULL && positionX + 1 <= 7) {
				tc->perecras(positionY - 1, positionX + 1);
			}
		}

		if (colorfigura == 0) {
			if ((tabls.print(positionY + 1, positionX - 1) % 2) != colorfigura && tabls.print(positionY + 1, positionX - 1) != NULL && positionX - 1 >= 0) {
				tc->perecras(positionY + 1, positionX - 1);
			}

			if ((tabls.print(positionY + 1, positionX + 1) % 2) != colorfigura && tabls.print(positionY + 1, positionX + 1) != NULL && positionX + 1 <= 7) {
				tc->perecras(positionY + 1, positionX + 1);
			}
		}

		for (int i = 0; i < q; i++)
		{
			if (colorfigura == 1) {
				positionY--;
			}
			else {
				positionY++;
			}

			if (tabls.print(positionY, positionX) != NULL) {
				break;
			}

			if ((positionY > 0 && positionY < 8)) {
				tc->perecras(positionY, positionX);
			}
		}
	}
};

class Rook: public Figura {
public:
	Rook(std::string name = f.Rk, int value = 15) :Figura(name, value)
	{
	}

	void going(int positionX, int positionY, tableColor* tc = &tableColors, table tabls = tables) {
		int colorfigura = tabls.print(positionY, positionX) % 2;

		int q = 7;

		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX, positionY - 1 - i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX, positionY + 1 + i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1 - i, positionY, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1 + i, positionY, colorfigura, tc)) {
				break;
			}
		}
		
		tc->perecrasF(positionY, positionX);

	}
};

class King : public Figura {
public:
	King(std::string name = f.Kn, int value = 1000) :Figura(name, value)
	{
	}

	void going(int positionX, int positionY, tableColor* tc = &tableColors, table tabls = tables) {
		int colorfigura = tabls.print(positionY, positionX) % 2;

		int q = 2;

		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX, positionY - 1, colorfigura, tc)){
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1, positionY, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1, positionY + 1, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1, positionY - 1, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX, positionY + 1, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1, positionY, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1, positionY + 1, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1, positionY - 1, colorfigura, tc)) {
				break;
			}
		}

		tc->perecrasF(positionY, positionX);
	}
};

class Bishop : public Figura {
public:
	Bishop(std::string name = f.Bs, int value = 10) :Figura(name, value)
	{
	}

	void going(int positionX, int positionY, tableColor* tc = &tableColors, table tabls = tables) {
		int colorfigura = tabls.print(positionY, positionX) % 2;

		int q = 7;

		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1 - i, positionY + 1 + i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1 - i, positionY - 1 - i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1 + i, positionY + 1 + i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1 + i, positionY - 1 - i, colorfigura, tc)) {
				break;
			}
		}

		tc->perecrasF(positionY, positionX);
	}
};

class Qween : public Figura {
public:
	Qween(std::string name = f.Qw, int value = 300) :Figura(name, value)
	{
	}

	std::string nameFigura() {
		return name;
	};

	void going(int positionX, int positionY, tableColor* tc = &tableColors, table tabls = tables) {
		int colorfigura = tabls.print(positionY, positionX) % 2;

		int q = 7;

		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX, positionY - 1 - i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1 - i, positionY, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1 - i, positionY + 1 + i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1 - i, positionY - 1 - i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX, positionY + 1 + i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1 + i, positionY, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1 + i, positionY + 1 + i, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1 + i, positionY - 1 - i, colorfigura, tc)) {
				break;
			}
		}

		tc->perecrasF(positionY, positionX);
	}
};

class Knight : public Figura {
public:
	Knight(std::string name = f.Kt, int value = 15) :Figura(name, value)
	{
	}

	void going(int positionX, int positionY, tableColor* tc = &tableColors, table tabls = tables) {
		int colorfigura = tabls.print(positionY, positionX) % 2;

		int q = 1;

		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1, positionY - 2, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 2, positionY - 1, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1, positionY + 2, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 2, positionY + 1, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 1, positionY - 2, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX + 2, positionY - 1, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 1, positionY + 2, colorfigura, tc)) {
				break;
			}
		}
		for (int i = 0; i < q; i++)
		{
			if (!cong_hod(positionX - 2, positionY + 1, colorfigura, tc)) {
				break;
			}
		}

		tc->perecrasF(positionY, positionX);
	}
};

