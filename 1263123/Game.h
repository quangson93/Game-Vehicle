#pragma once
#include "Sharps.h"
#include <iostream>;
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class CGame
{
private:
	int Point;
	CSharp sharp;
	int Highscore;
	string sHighscore;
	vector <int> listScore;
	
public:
	CGame();
	~CGame();
	void Process();
	void Sort();
	void ProcessReadFile();
	void ProcessGame();
	void ProcessMoveCar();
	void ProcessCollision();
	void ProcessMoney();
	void ProcessEnemy();
	void ShowInfoGame();
	void ShowHighScore();
	void ShowList();
	void Input();
	void Output();
	static ifstream FileIn;
	static ofstream FileOut;

	
};

