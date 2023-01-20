#include<iostream>
#include<time.h>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include"functions_control_console.h"
#include"Enemy.h"
#include"Player.h"
#include"Activities.cpp""

using namespace std;

constexpr auto widthWindow = 150;
constexpr auto heightWindow = 60;
constexpr auto widthPlayArea = 45;
constexpr auto heightPlayArea = 45;

#define _WIN32_WINNT 0x0502

//struct
struct Position {
	int prevPosX = 0;
	int prevPosY = 0;
	int nextPosX = 0;
	int nextPosY = 0;
};

#pragma region gameClass
PLAYER playerWeak(5, 100, ".-A-.", '.');
ENEMY enemyWeak(70, 1, 1, "|-o-|");
#pragma endregion

//general values;
#pragma region generalVariablesAndSetting
int* g_speed = new int(200); //toc do lam moi
int* g_bulletSpeed = new int(30); //toc do dan
int* g_score = new int(0);
int* g_destroyed = new int(0);
int* g_life = new int(playerWeak.getLife());
char c = ' ';

Activities activities = Activities::stop;
Position player;
Position enemy;
Position bullet;
#pragma endregion

#pragma region fileDataTest
//ofstream fileDataEven("logEven.txt");
//ofstream fileDataP("logP.txt");
//ofstream fileDataE("logE.txt");
#pragma endregion

#pragma region generalFunctions
void drawPlayArea(int width, int height);
void drawScoreBoard();
void drawTurtorial();

void story_chapter_1(int speed);

void stage_chapter_1(int speed);
void stage_chapter_game();

void drawSpaceship(string object);
void drawEnemy(string object);
void drawBullet();

void controlSpaceship();
void controlEnemy();
void controlBullet();

void moveSpaceship(string object);
void moveEnemy(string object);
void moveBullet();

void destroyObject(string object, int prevX, int prevY);

bool isPlayerHitWall(int nextPosX, int nextPosY, string object);
bool isEnemyHitWall(int nextPosY);
bool isPlayerHitEnemy(string objectP, string objectE);
bool isBulletHitEnemy(string objectE);
bool isBulletHitWall(int prevPosY);

bool calDistanceBetweenPE(int prevPosYP, int prevPosYE);

int random(int minN, int maxN);
#pragma endregion

#pragma region UI
void drawPlayArea(int width, int height) { //done
	gotoXY(0, 0);
	for (int i = 0; i < widthPlayArea + 1; i++)
	{
		gotoXY(i, 0);
		cout << '-';
		Sleep(2);
	}
	gotoXY(0, 1);
	for (int i = 1; i < heightPlayArea + 1; i++)
	{
		gotoXY(0, i);
		cout << '|';
		Sleep(2);
	}
	gotoXY(widthPlayArea, 1);
	for (int i = 1; i < heightPlayArea + 1; i++)
	{
		gotoXY(widthPlayArea, i);
		cout << '|';
		Sleep(2);
	};
	gotoXY(0, heightPlayArea);
	for (int i = 1; i < widthPlayArea; i++)
	{
		gotoXY(i, heightPlayArea);
		cout << '_';
		Sleep(2);
	}
}
void drawScoreBoard() {
	//widthPlayArea = 45 (y)
	//heightPlayArea = 45 (x)
	gotoXY(widthPlayArea + 13, 0);
	cout << "<<--->> R.E.C.O.R.D <<--->>";

	//cao:11,rong:31
	//13 hang 
	gotoXY(widthPlayArea + 10, 1);
	for (int i = 1; i < 12; i++)
	{
		gotoXY(widthPlayArea + 10, i);
		cout << '|';
		Sleep(2);
	};
	gotoXY(widthPlayArea + 11, 11);
	for (int i = widthPlayArea + 11; i < widthPlayArea + 42; i++)
	{
		gotoXY(i, 11);
		cout << '_';
		Sleep(2);
	};
	gotoXY(widthPlayArea + 42, 15);
	for (int i = 11; i >= 1; i--)
	{
		gotoXY(widthPlayArea + 42, i);
		cout << '|';
		Sleep(2);
	};

	//life
	gotoXY(widthPlayArea + 13, 2);
	cout << "LIFE: ";
	//detroy
	gotoXY(widthPlayArea + 13, 4);
	cout << "DESTROY: ";
	//score
	gotoXY(widthPlayArea + 13, 6);
	cout << "SCORE: ";
	//energy
	gotoXY(widthPlayArea + 13, 8);
	cout << "ENERGY: ";
	//speed
	gotoXY(widthPlayArea + 13, 10);
	cout << "SPEED: ";
}
void showScore() {
	gotoXY(widthPlayArea + 13 + 7, 2);
	cout << *g_life;
	gotoXY(widthPlayArea + 13 + 9, 4);
	cout << *g_destroyed;
	gotoXY(widthPlayArea + 13 + 7, 6);
	cout << *g_score;
}
void drawTurtorial() {
	gotoXY(widthPlayArea + 58, 0);
	cout << "<<--->> T.U.R.T.O.R.I.A.L <<--->>";

	gotoXY(widthPlayArea + 51, 1);
	for (int i = 1; i < 12; i++)
	{
		gotoXY(widthPlayArea + 51, i);
		cout << '|';
		Sleep(2);
	}
	gotoXY(widthPlayArea + 52, 11);
	for (int i = widthPlayArea + 52; i < widthPlayArea + 96; i++)
	{
		gotoXY(i, 11);
		cout << '_';
		Sleep(2);
	};
	gotoXY(widthPlayArea + 96, 13);
	for (int i = 11; i >= 1; i--)
	{
		gotoXY(widthPlayArea + 96, i);
		cout << '|';
		Sleep(2);
	};

	gotoXY(widthPlayArea + 53, 2);
	cout << "Press WASD to control your spaceship.";
	gotoXY(widthPlayArea + 53, 4);
	cout << "Press 'f' to fire the enemy.";
	gotoXY(widthPlayArea + 53, 6);
	cout << "Press 'space' to stop your spaceship.";
	gotoXY(widthPlayArea + 53, 8);
	cout << "Press 'p' to pause game.";
}
#pragma endregion

#pragma region main
void stage_chapter_game(){
	srand(time(NULL));

	stage_chapter_1(*g_speed);
	drawPlayArea(widthPlayArea, heightPlayArea);
	drawScoreBoard();
	drawTurtorial();
	drawSpaceship(playerWeak.getObjectP());
	drawEnemy(enemyWeak.getObjectE());

	while (true)
	{

		if (_kbhit())
		{
			c = _getch();
			c = tolower(c);
			if (c == 'w')
			{
				activities = Activities::top;
			}
			else if (c == 's')
			{
				activities = Activities::bottom;
			}
			else if (c == 'd') {
				activities = Activities::right;
			}
			else if (c == 'a')
			{
				activities = Activities::left;
			}
			else if (c == 'f')
			{
				activities = Activities::fire;
			}
			else if (c == ' ') {
				activities = Activities::stop;
			}
		}
		if (c != 'p')
		{
			controlSpaceship();
			controlEnemy();
			showScore();
		};
		Sleep(*g_speed);
	}
}
#pragma endregion

#pragma region player
void drawSpaceship(string object) {
	player.prevPosX = random(10, 30);
	player.prevPosY = random(35, 39);
	gotoXY(player.prevPosX, player.prevPosY);
	cout << object;
}
void controlSpaceship() {
	if (activities == Activities::top)
	{
		player.nextPosX = player.prevPosX;
		player.nextPosY = player.prevPosY - 1;
	}
	else if (activities == Activities::bottom)
	{
		player.nextPosX = player.prevPosX;
		player.nextPosY = player.prevPosY + 1;
	}
	else if (activities == Activities::left)
	{
		player.nextPosX = player.prevPosX - 1;
		player.nextPosY = player.prevPosY;
	}
	else if (activities == Activities::right)
	{
		player.nextPosX = player.prevPosX + 1;
		player.nextPosY = player.prevPosY;
	}
	else if (activities == Activities::stop)
	{
		player.nextPosX = player.prevPosX;
		player.nextPosY = player.prevPosY;
	}
	else if (activities == Activities::fire)
	{
		player.nextPosX = player.prevPosX;
		player.nextPosY = player.prevPosY;
	}
	moveSpaceship(playerWeak.getObjectP());
}
void moveSpaceship(string object) {
	if (c == 'f')
	{
		drawBullet();
		controlBullet();
		moveBullet();
		c = ' ';
		//fileDataEven << c << ' ' << "yes" << endl;
	}
	else if (!isPlayerHitWall(player.nextPosX, player.nextPosY, playerWeak.getObjectP()))
	{
		gotoXY(player.prevPosX, player.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		gotoXY(player.nextPosX, player.nextPosY);
		player.prevPosX = player.nextPosX;
		player.prevPosY = player.nextPosY;
		cout << object;

		//fileDataP << "player.prevPosX: " << player.prevPosX << endl;
		//fileDataP << "player.prevPosY: " << player.prevPosY << endl;
		//fileDataP << "player.nextPosX: " << player.nextPosX << endl;
		//fileDataP << "player.nextPosY: " << player.nextPosY << endl;
		//fileDataP << " " << endl;

	};
}
#pragma endregion

#pragma region enemy
void drawEnemy(string object) {
	enemy.nextPosX = 0;
	enemy.nextPosY = 0;
	enemy.prevPosX = random(11, 31);
	enemy.prevPosY = random(1, 5);
	gotoXY(enemy.prevPosX, enemy.prevPosY);
	cout << object;
}
void controlEnemy() {
	enemy.nextPosX = enemy.prevPosX;
	enemy.nextPosY = enemy.prevPosY + 1;
	if (isPlayerHitEnemy(playerWeak.getObjectP(), enemyWeak.getObjectE())) //true
	{
		*g_score = *g_score + enemyWeak.getRewardPoint();
		*g_destroyed = *g_destroyed + enemyWeak.getRewardPoint();
		*g_life = *g_life - enemyWeak.getMinusPoint();
		destroyObject(enemyWeak.getObjectE(), enemy.prevPosX, enemy.prevPosY);
	}
	else //false
	{
		moveEnemy(enemyWeak.getObjectE());
	};
}
void moveEnemy(string object) {
	gotoXY(enemy.prevPosX, enemy.prevPosY);
	cout << setfill(' ');
	cout << setw(object.size()) << right << ' ';

	if (!isEnemyHitWall(enemy.nextPosY))
	{
		gotoXY(enemy.nextPosX, enemy.nextPosY);
		enemy.prevPosX = enemy.nextPosX;
		enemy.prevPosY = enemy.nextPosY;
		cout << object;

		//fileDataE << "enemy.prevPosX: " << enemy.prevPosX << endl;
		//fileDataE << "enemy.prevPosY: " << enemy.prevPosY << endl;
		//fileDataE << "enemy.nextPosX: " << enemy.nextPosX << endl;
		//fileDataE << "enemy.nextPosY: " << enemy.nextPosY << endl;
		//fileDataE << " " << endl;

	};
}
void destroyObject(string object, int prevX, int prevY) { //done
	gotoXY(prevX, prevY);
	cout << setfill(' ');
	cout << setw(object.size()) << right << ' ';
	drawEnemy(enemyWeak.getObjectE());
}
#pragma endregion

#pragma region bullet
void drawBullet() {
	bullet.prevPosX = (player.prevPosX + playerWeak.getObjectP().size() / 2); //vi tri trung tam
	bullet.prevPosY = player.prevPosY - 1;
	gotoXY(bullet.prevPosX, bullet.prevPosY);
	cout << playerWeak.getBullet();
}
void controlBullet() {
	bullet.nextPosX = bullet.prevPosX;
	bullet.nextPosY = bullet.prevPosY - 1;
}
void moveBullet() {
	int be = bullet.prevPosY;
	for (int i = be; i >= 1; i--)
	{
		if (!isBulletHitEnemy(enemyWeak.getObjectE()) && !isBulletHitWall(bullet.nextPosY))
		{
			gotoXY(bullet.prevPosX, bullet.prevPosY);
			cout << ' ';

			controlBullet();

			gotoXY(bullet.nextPosX, bullet.nextPosY);
			cout << playerWeak.getBullet();

			bullet.prevPosX = bullet.nextPosX;
			bullet.prevPosY = bullet.nextPosY;

			Sleep(*g_bulletSpeed);
		}
		else if (isBulletHitWall(bullet.nextPosY))
		{
			gotoXY(bullet.prevPosX, bullet.prevPosY);
			cout << ' ';
			break;
		}
		else {
			*g_score = *g_score + enemyWeak.getRewardPoint();
			*g_destroyed = *g_destroyed + enemyWeak.getMinusPoint();
			destroyObject(enemyWeak.getObjectE(), enemy.prevPosX, enemy.prevPosY);
			gotoXY(bullet.prevPosX, bullet.prevPosY);
			cout << ' ';
			break;
		};
	};
}
#pragma endregion

#pragma region checkingEvents
bool isPlayerHitWall(int nextPosX, int nextPosY, string object) {
	if (nextPosX == 0 || nextPosX == widthPlayArea - object.size())
	{
		return true;
	}
	else if (nextPosY == 0 || nextPosY == heightPlayArea)
	{
		return true;
	}
	return false;
}
bool isEnemyHitWall(int nextPosY) {
	if (nextPosY == heightPlayArea)
	{
		enemy.nextPosX = 0;
		enemy.nextPosY = 0;
		return true;
	}return false;
};
bool isPlayerHitEnemy(string objectP, string objectE) { //done
	//objectP: playerWeak.getObjectP()
	//objectE: enemyWeak.getObject()
	int openLimitX = player.prevPosX - objectE.size() + 1;
	int endLimitX = player.prevPosX + objectP.size();
	bool isEven = calDistanceBetweenPE(player.prevPosY, enemy.prevPosY);
	if (isEven == true) //number is even
	{

		{if (enemy.prevPosX >= openLimitX && enemy.prevPosX <= endLimitX)

			if (enemy.nextPosY == player.prevPosY || enemy.prevPosY == player.nextPosY)
				return true;
		}
	}
	else if (isEven == false)
	{
		if (enemy.prevPosX >= openLimitX && enemy.prevPosX <= endLimitX)
		{
			if (player.nextPosY == enemy.nextPosY || player.prevPosY == enemy.prevPosY)
				return true;
		};
	};
	return false;
}
bool isBulletHitEnemy(string objectE) {
	if (bullet.nextPosY == enemy.prevPosY)
	{
		if (bullet.nextPosX >= enemy.prevPosX && bullet.nextPosX <= enemy.prevPosX + enemyWeak.getObjectE().size())
		{
			return true;
		};
	}return false;
}
bool isBulletHitWall(int nextPosY) {
	if (nextPosY == 1)
	{
		return true;
	}return false;
};
#pragma endregion

#pragma region calculaor
bool calDistanceBetweenPE(int prevPosYP, int prevPosYE) { //done
	if ((prevPosYP - prevPosYE) % 2 == 0)
	{
		/*
		fileDataE << "distanceBetweenPE: even number" << endl;
		fileDataE << " " << endl;
		fileDataP << "distanceBetweenPE: even number" << endl;
		fileDataP << " " << endl;
		*/
		return true;
	};
	/*
	fileDataE << "distanceBetweenPE: odd number" << endl;
	fileDataE << " " << endl;
	fileDataP << "distanceBetweenPE: odd number" << endl;
	fileDataP << " " << endl;
	*/
	return false;
}
#pragma endregion

#pragma region toolFunction
//int random(int minN, int maxN) {
//	return minN + rand() % (maxN + 1 - minN);
//}
#pragma endregion