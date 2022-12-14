#pragma once

//цвета
enum class color : unsigned short
{
	black, blue, green, cyan, red, magenta, brown, lightgray, darkgray,
	lightblue, lightgreen, lightcyan, lightred, lightmagenta, yellow, white
};
// Kn - король
// Qw - королева
// Rk - ладья
// Bs - слон
// Kt - конь 
// Pw - пешка
struct FiguraStruct // Фигуры
{
	std::string Kn, Qw, Rw, Rk, Bs, Kt, Pw;
	FiguraStruct()
		: Kn{ "Kn" }, Qw{ "Qw" }, Rk{ "Rk" }, Bs{ "Bs" }, Kt{ "Kt" }, Pw{ "Pw" }
	{

	}
};
