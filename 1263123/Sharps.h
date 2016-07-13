#pragma once
const char obstacle = 219;
const char clear = ' ';
const char money = '$';
class CSharp
{
private:
	char sharp[25][25];
	int r, c;
	int rEnemy, cEnemy;
	int rMoney, cMoney;
public:
	CSharp();
	~CSharp();

	void runEnemy();
	void resetEnemy();

	void runMoney();
	void resetMoney();

	void drawMap();

	void getCar();
	void drawCar();
	void clearCar();

	void getEnemy();
	void drawEnemy();
	void clearEnemy();

	void getMoney();
	void drawMoney();
	void clearMoney();

	bool isOK();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	bool collisionCar();
	bool collisionMoney();
	void printScreen();
};

