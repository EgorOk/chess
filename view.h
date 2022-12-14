#pragma once
char ary[STLB] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

class View {
public:
	void tableVies(tableColor tableCs) {
		for (int shet = 0; shet < STRK; shet++)
		{
			std::cout << shet + 1 << " ";

			for (int shet2 = 0; shet2 < STLB; shet2++)
			{
				color foreground = color::white;
				color background = color::black;
				 
				if (tableCs.print(shet, shet2) == 1) {
					background = color::red;
				}
				else if (tableCs.print(shet, shet2) == 2) {
					background = color::lightblue;
				}
				else if ((shet2 + shet) % 2 == 0) {
					background = color::brown;
				}
				else if ((shet2 + shet) % 2 == 1) {
					background = color::darkgray;
				}

				if (tables.print(shet, shet2) % 2 == 0) {
					foreground = color::black;
				}
				else if (tables.print(shet, shet2) % 2 == 1) {
					foreground = color::white;
				}

				set_col(foreground, background);

				if ((tables.print(shet, shet2) >> 1 == 5) && tables.print(shet, shet2) != NULL) {
					std::cout << Pw.nameFigura();
				}
				else if ((tables.print(shet, shet2) >> 1 == 2) && tables.print(shet, shet2) != NULL) {
					std::cout << Rk.nameFigura();
				}
				else if ((tables.print(shet, shet2) >> 1 == 1) && tables.print(shet, shet2) != NULL) {
					std::cout << Kn.nameFigura();
				}
				else if ((tables.print(shet, shet2) >> 1 == 3) && tables.print(shet, shet2) != NULL) {
					std::cout << Bs.nameFigura();
				}
				else if ((tables.print(shet, shet2) >> 1 == 4) && tables.print(shet, shet2) != NULL) {
					std::cout << Qw.nameFigura();
				}
				else if ((tables.print(shet, shet2) >> 1 == 6) && tables.print(shet, shet2) != NULL) {
					std::cout << Kt.nameFigura();
				}
				else {
					std::cout << "  ";
				}
			}
			set_col();
			std::cout << "\n";
		}

		std::cout << "  ";
		for (int shet = 0; shet < STLB; shet++)
		{
			std::cout << ary[shet] << " ";
		}
		std::cout << "\n";
		set_col();
	}

	void set_col(color foreground = color::white, color background = color::black) {
		SetConsoleTextAttribute(
			hout, ((short)background << 4) | (short)foreground);
	}
};
