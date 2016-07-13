#include "Game.h"
#include "CslFunc.h"
#include <fcntl.h>
#include <io.h>
ifstream CGame::FileIn;
ofstream CGame::FileOut;

CGame::CGame()
{
	Point = 0;
}

CGame::~CGame()
{
}

void CGame::Input()
{
	getline(FileIn, sHighscore);
	Highscore = atoi(sHighscore.c_str());
}

void CGame::Sort()
{
	for (int i = 0; i < listScore.size() - 1; i++)
	{
		for (int j = i + 1; j < listScore.size(); j++)
		{
			if (listScore[i] <= listScore[j])
			{
				int temp = listScore[i];
				listScore[i] = listScore[j];
				listScore[j] = temp;
			}
		}
	}
}
void CGame::ProcessReadFile()
{
	CGame::FileIn.open("INPUT.TXT", ios_base::in);
	while (!CGame::FileIn.eof())
	{
		getline(FileIn, sHighscore);
		Highscore = atoi(sHighscore.c_str());
		listScore.push_back(Highscore);
	}
	CGame::FileIn.close();
}
void CGame::Output()
{
	CGame::FileOut.open("INPUT.TXT", ios_base::out | ios_base::app);
	FileOut << this->Point << endl;
	CGame::FileOut.close();
}

void CGame::ShowHighScore()
{
	ProcessReadFile();
	Sort();
	Highscore = listScore[0];
}

void CGame::ShowList()
{
	system("cls");
	ShowHighScore();
	CslFunc::textcolor(FG_GREEN);
	CslFunc::gotoxy(2, 3);
	cout << "Top 10 Highscore!!!" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " - " << listScore[i] << endl;
	}
}

void CGame::Process()
{
	int n;
	do
	{
		system("cls");
		CslFunc::textcolor(FG_BLUE);
		CslFunc::gotoxy(2, 15); cout << "===============================================" <<endl;
		CslFunc::gotoxy(3, 15); cout << "|                   MENU                      |" <<endl;
		CslFunc::gotoxy(4, 15); cout << "|                                             |" << endl;
		CslFunc::gotoxy(5, 15); cout << "|	     1 - START NEW GAME.             |" << endl;
		CslFunc::gotoxy(6, 15); cout << "|	     2 - HIGHSCORE.                  |" << endl;
		CslFunc::gotoxy(7, 15); cout << "|	     3 - HELP.                       |" << endl;
		CslFunc::gotoxy(8, 15); cout << "|	     4 - EXIT.                       |" << endl;
		CslFunc::gotoxy(10, 15); cout << "===============================================" <<endl;
		CslFunc::gotoxy(9, 15); cout << "| Please press number:	"; cin >> n;
		switch(n)
		{
		case 1:
			{
				ProcessGame();
				break;
			}
		case 2: 
			{
				ShowList();
				break;
			}
		case 3:
			{
				system("cls");
				CslFunc::gotoxy(2, 3);
				cout << "Press key "<< (char)24 << "\t" << (char)25 << "\t" << (char)26 << "\t"  << (char)27 << endl <<"move the car!!!" ;
				break;
			}
		}
		system("pause");
	}while(n != 4);
}

void CGame::ProcessGame()
{
	CslFunc::textcolor(FG_BLUE);
	system("cls");
	ShowHighScore();
	sharp.drawMap();
	sharp.getCar();
	sharp.getEnemy();
	sharp.getMoney();
	while (true)
	{
		Sleep(100);
		ProcessEnemy();
		ProcessMoney();
		ProcessMoveCar();
		ProcessCollision();
		Point++;
		//ShowScore();
		
		ShowInfoGame();
		if (sharp.collisionCar() == true)
		{
			CslFunc::gotoxy(0, 0);
			cout << endl << endl << endl << endl << endl << "     GAME OVER				";
			break;
		}
		sharp.printScreen();
	}
	Output();
	system("pause");
}

void CGame::ProcessMoveCar()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		sharp.moveLeft();
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		sharp.moveRight();
	}
	if (GetAsyncKeyState(VK_UP))
	{
		sharp.moveUp();
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		sharp.moveDown();
	}
}

void CGame::ProcessCollision()
{
	if (sharp.collisionMoney() == true)
	{
		this->Point += 500;
	}
}

void CGame::ProcessMoney()
{
	sharp.clearMoney();
	sharp.runMoney();
	sharp.resetMoney();
	sharp.drawMoney();

}

void CGame::ProcessEnemy()
{
	sharp.clearEnemy();
	sharp.runEnemy();
	sharp.resetEnemy();
	sharp.drawEnemy();
}



void CGame::ShowInfoGame()
{
	CslFunc::textcolor(FG_RED);
	CslFunc::gotoxy(7, 25); cout << "=========================" << endl;
	CslFunc::gotoxy(8, 25); cout <<	"|   CAR RACING - v1.1   |" << endl;
	CslFunc::gotoxy(9, 25); cout << "|     GROUP ID: 09      |" << endl;
	CslFunc::gotoxy(10, 25); cout << "|   Points: " << Point  << endl;
	CslFunc::gotoxy(11, 25); cout << "|   HighScore: " << Highscore << endl;
	CslFunc::gotoxy(12, 25); cout << "=========================" << endl;
	CslFunc::textcolor(FG_BLUE);
}

