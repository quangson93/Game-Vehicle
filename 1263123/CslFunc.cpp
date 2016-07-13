#include "CslFunc.h"
#include <fcntl.h>
#include <io.h>

CslFunc::CslFunc()
{
}


CslFunc::~CslFunc()
{
}


void CslFunc::gotoxy(const int _x, const int _y)
{
	COORD coord;
	coord.X = _y;				// invert the axis to get consistency with the stored array
	coord.Y = _x;				//
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void CslFunc::put_char(const char &_c)
{
	cout << _c;
}

void CslFunc::textcolor(const ColorType _color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
}
