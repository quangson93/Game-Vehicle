#pragma once
#include<windows.h>
#include<iostream>
using namespace std;
enum ColorType
{
	// foreground  
	FG_BLACK = 0x0000,
	FG_NAVY = 0x0001,
	FG_GREEN = 0x0002,
	FG_TEAL = 0x0003,
	FG_BROWN = 0x0004,
	FG_PURPLE = 0x0005,
	FG_OLIVE = 0x0006,
	FG_LIGHT_GRAY = 0x0007,
	FG_INTENSITY = 0x0008,
	FG_MEDIUM_BLUE = 0x0009,
	FG_GRAY = 0x0008 | 0x0000,
	FG_BLUE = 0x0008 | 0x0001,
	FG_LIME = 0x0008 | 0x0002,
	FG_CYAN = 0x0008 | 0x0003,
	FG_RED = 0x0008 | 0x0004,
	FG_FUCHSIA = 0x0008 | 0x0005,
	FG_YELLOW = 0x0008 | 0x0006,
	FG_WHITE = 0x0008 | 0x0007,
	FG_SILVER = 0x0008 | 0x0008,

	// background  
	BG_BLUE = 0x0010,
	BG_GREEN = 0x0020,
	BG_RED = 0x0040,
	BG_INTENSITY = 0x0080,
};


class CslFunc
{
public:
	
	CslFunc();
	~CslFunc();
	static void gotoxy(const int _x, const int _y);
	static void put_char(const char &_c);
	static void textcolor(const ColorType _color);

};

