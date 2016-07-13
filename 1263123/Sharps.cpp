#include "Sharps.h"
#include "CslFunc.h"

CSharp::CSharp()
{
}


CSharp::~CSharp()
{
}


void CSharp::drawMap()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			sharp[i][0] = '|'; //Cột 0
			sharp[i][18] = '|'; //Cột cuối cùng 
			sharp[i][j] = ' '; //Khoảng trắng
		}
	}
}

void CSharp::getCar()
{
	r = 17, c = 9;
	sharp[r][c] = 'X';
	sharp[r][c + 1] = '|';
	sharp[r][c - 1] = '|';
	sharp[r + 1][c - 1] = 'o';
	sharp[r + 1][c + 1] = 'o';
	sharp[r - 1][c - 1] = 'o';
	sharp[r - 1][c + 1] = 'o';
}

void CSharp::drawCar()
{
	sharp[r][c] = 'X';
	sharp[r][c + 1] = '|';
	sharp[r][c - 1] = '|';
	sharp[r + 1][c - 1] = 'o';
	sharp[r + 1][c + 1] = 'o';
	sharp[r - 1][c - 1] = 'o';
	sharp[r - 1][c + 1] = 'o';
}

void CSharp::clearCar()
{
	sharp[r][c] = clear;
	sharp[r][c + 1] = clear;
	sharp[r][c - 1] = clear;
	sharp[r + 1][c - 1] = clear;
	sharp[r + 1][c + 1] = clear;
	sharp[r - 1][c - 1] = clear;
	sharp[r - 1][c + 1] = clear;
}

bool CSharp::isOK()
{
	if (sharp[r][c + 3] != '|' || sharp[r][c - 3] != '|')
		return false;
	return true;
}

void CSharp::moveLeft()
{
	if (sharp[r][c - 2] != '|')
	{
		clearCar();
		c--;
		drawCar();
	}
}

void CSharp::moveRight()
{
	if (sharp[r][c + 3] != '|')
	{
		clearCar();
		c++;
		drawCar();
	}
}

void CSharp::moveUp()
{
	if (r != 0)
	{
		clearCar();
		r--;
		drawCar();
	}
}

void CSharp::moveDown()
{
	if (r != 17)
	{
		clearCar();
		r++;
		drawCar();
	}
}

void CSharp::printScreen()
{
	CslFunc::gotoxy(0, 0);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{

			cout << sharp[i][j];
			if (j >= 19)
				cout << endl;
		}
	}
}

void CSharp::getEnemy()
{
	rEnemy = 0;
	cEnemy = 11;
	sharp[rEnemy][cEnemy] = obstacle;
	sharp[rEnemy][cEnemy + 1] = obstacle;
	sharp[rEnemy][cEnemy - 1] = obstacle;
	sharp[rEnemy + 1][cEnemy - 1] = obstacle;
	sharp[rEnemy + 1][cEnemy + 1] = obstacle;
	sharp[rEnemy - 1][cEnemy - 1] = obstacle;
	sharp[rEnemy - 1][cEnemy + 1] = obstacle;
}

void CSharp::drawEnemy()
{
	sharp[rEnemy][cEnemy] = obstacle;
	sharp[rEnemy][cEnemy + 1] = obstacle;
	sharp[rEnemy][cEnemy - 1] = obstacle;
	sharp[rEnemy + 1][cEnemy - 1] = obstacle;
	sharp[rEnemy + 1][cEnemy + 1] = obstacle;
	sharp[rEnemy - 1][cEnemy - 1] = obstacle;
	sharp[rEnemy - 1][cEnemy + 1] = obstacle;
}

void CSharp::clearEnemy()
{
	sharp[rEnemy][cEnemy] = clear;
	sharp[rEnemy][cEnemy + 1] = clear;
	sharp[rEnemy][cEnemy - 1] = clear;
	sharp[rEnemy + 1][cEnemy - 1] = clear;
	sharp[rEnemy + 1][cEnemy + 1] = clear;
	sharp[rEnemy - 1][cEnemy - 1] = clear;
	sharp[rEnemy - 1][cEnemy + 1] = clear;
}

void CSharp::getMoney()
{
	this->rMoney = 0;
	this->cMoney = 1;
	sharp[rMoney][cMoney] = money;
}

void CSharp::drawMoney()
{
	sharp[rMoney][cMoney] = money;
}

void CSharp::clearMoney()
{
	sharp[rMoney][cMoney] = clear;
}

void CSharp::runMoney()
{
	this->rMoney+=1;
}

void CSharp::resetMoney()
{
	if (this->rMoney > 20)
	{
		this->rMoney = 0;
		this->cMoney = rand() % 15 + 2;
	}
}



void CSharp::runEnemy()
{
	this->rEnemy++;
//	this->rMoney += 2;
}

void CSharp::resetEnemy()
{
	if (this->rEnemy > 20) // Đặt điều kiện để reset vị trí 
	{
		this->rEnemy = 0;
		this->cEnemy = rand() % 15 + 2;
	}
}

bool CSharp::collisionCar()
{
	if (sharp[r - 1][c - 1] != 'o' || sharp[r - 1][c + 1] != 'o' || sharp[r][c] != 'X')
		return true;
	else 
		return false;
}

bool CSharp::collisionMoney()
{
	if (sharp[r - 1][c - 1] == money || sharp[r - 1][c + 1] == money || sharp[r][c] == money)
	{
		sharp[r - 1][c - 1] = 'o';
		sharp[r - 1][c + 1] = 'o';
		sharp[r][c] = 'X';
		getMoney();
		
		return true;
	}
	return false;
}