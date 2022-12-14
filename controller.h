#pragma once
Pawn Pw;
Knight Kt;
King Kn;
Bishop Bs;
Qween Qw;
Rook Rk;

class Controller {
public:
	void goController(int nomber_f, int x, int y, tableColor* tableCs) {
		nomber_f = nomber_f >> 1;

		if (nomber_f == 1)
			Kn.going(x - 1, y - 1, tableCs);
		else if (nomber_f == 2)
			Rk.going(x - 1, y - 1, tableCs);
		else if (nomber_f == 3)
			Bs.going(x - 1, y - 1, tableCs);
		else if (nomber_f == 4)
			Qw.going(x - 1, y - 1, tableCs);
		else if (nomber_f == 5)
			Pw.going(x - 1, y - 1, tableCs);
		else if (nomber_f == 6)
			Kt.going(x - 1, y - 1, tableCs);
	}
};