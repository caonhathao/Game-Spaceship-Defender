#include<iostream>
#include<time.h>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<vector>

#include"struct.cpp"
#include"functions_control_console.h"
#include"functions_control_object.h"
#include"Enemy.h"
#include"Player.h"
#include"variable.h"

using namespace std;

constexpr auto widthWindow = 150;
constexpr auto heightWindow = 60;
constexpr auto widthPlayArea = 45;
constexpr auto heightPlayArea = 45;

#define _WIN32_WINNT 0x0502

//struct
struct Postion;
struct result;

#pragma region gameClass
//PLAYER playerWeak(5, 100, "|-[O]-|", '.');
//ENEMY enemyWeak(70, 1, 1, "|-x-|");
#pragma endregion

//general values;
#pragma region generalVariablesAndSetting
int* g_speed = new int(200); //toc do lam moi
int* g_bulletSpeed = new int(30); //toc do dan

int* g_score = new int(0);
int* g_destroyed = new int(0);
int* g_life = new int(playerWeak.getLife());

int* E_th = new int(0);
int* B_th = new int(0);

int fire_sign = 0;

int* tempPosBulletX = new int(0);
int* tempPosBulletY = new int(0);

vector<Position>teamE = {};
vector<Position>teamB = {};
#pragma endregion

#pragma region fileDataTest
//ofstream fileDataEven("./logEven.txt");
//ofstream fileDataP("./logP.txt");
//ofstream fileDataE("./logE.txt");
#pragma endregion

#pragma region generalFunctions
void drawPlayArea(int width, int height);
void drawScoreBoard();
void drawTurtorial();

void stage_chapter_game(int& score, int& destroyed);

//void drawSpaceship(string object);
//void drawEnemy(string object);
//void drawBullet();

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

int main();
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


	gotoXY(widthPlayArea + 13 + 8, 10);
	cout << *g_speed + (200 - *g_speed);
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
	cout << "Press 'j' to fire the enemy.";
	gotoXY(widthPlayArea + 53, 6);
	cout << "Press 'space' to stop your spaceship.";
	gotoXY(widthPlayArea + 53, 8);
	cout << "Press 'p' to pause game.";
	gotoXY(widthPlayArea + 53, 10);
	cout << "Press 'r' to back the menu";
}
#pragma endregion

#pragma region main
void stage_chapter_game(int& score, int& destroyed){
	srand(time(NULL));

	system("cls");

	drawPlayArea(widthPlayArea, heightPlayArea);
	drawScoreBoard();
	drawTurtorial();
	//drawSpaceship(playerWeak.getObjectP());
	drawObject(playerWeak.getObjectP(), playerPos, 10, 30, 35, 39, 3);

	for (int i = 0; i < 3; i++)
	{
		//drawEnemy(enemyWeak.getObjectE());
		drawObject(enemyWeak.getObjectE(), enemyPos, 11, 31, 1, 5, 2);
		teamE.push_back(enemyPos);
	};

	*g_count_down = 3000;
	*g_playerSize = playerWeak.getObjectP().size();

	*c = ' ';
	while (true)
	{
		*tempPosBulletX = playerPos.prevPosX + int(*g_playerSize / 2);
		*tempPosBulletY = playerPos.prevPosY - 1;

		if (*g_life != 0)
		{
			if (_kbhit())
			{
				*c = _getch();
				*c = tolower(*c);
				if (*c == 'w')
				{
					activities = Activities::top;
				}
				else if (*c == 's')
				{
					activities = Activities::bottom;
				}
				else if (*c == 'd') {
					activities = Activities::right;
				}
				else if (*c == 'a')
				{
					activities = Activities::left;
				}
				else if (*c == 'j')
				{
					activities = Activities::fire;
					fire_sign++;
				}
				else if (*c == ' ') {
					activities = Activities::stop;
				}
			}
			if (*c == 'p')
			{
				while (*c == 'p')
				{
					if (_kbhit()) {
						*c = _getch();
					}
				}
			}
			else if (*c == 'r')
			{
				break;
			}
			else {
				//controlSpaceship();
				controlWithoutEvent(activities, playerPos);
				moveSpaceship(playerWeak.getObjectP());
				for (int i = 0; i < teamE.size(); i++)
				{
					enemyPos = teamE[i];
					*E_th = i;
					controlEnemy();
					teamE[i] = enemyPos;
				}
				if (*c == 'j')
				{
					drawObject(playerWeak.getBullet(), bulletPos, *tempPosBulletX, *tempPosBulletX, *tempPosBulletY, *tempPosBulletY, 3);
					teamB.push_back(bulletPos);
					*c = ' ';
				};
				if (teamB.size() > 0)
				{
				replay: 

					/* DESCRIPTION: attention on this
					* - doan code nay giup kiem tra xem lieu co bullet[i] nao danh trung enemy[j] khong.
					* - neu co, tien hanh pha huy bullet[i], luu vi tri bi xoa (xem them o ham controlBullet(), moveBullet()).
					* - khi dieu kien (kich thuoc bi thay doi) dung, thi tien hanh reset lai length, dong thoi tiep tuc kiem tra 
					* nhung bullet[i] con lai.
					* - neu dieu kien bi sai, tien hanh cap nhat toa do cua moi bullet[i]
					*/

					int length = teamB.size();
					for (int j = 0; j < length; j++)
					{
						bulletPos = teamB[j];
						*B_th = j;
						controlBullet();
						if (length != teamB.size())
						{
							goto replay;
						};
						teamB[j] = bulletPos;
					};
				};
				showScore();
				if (*g_count_down == 0)
				{
					(*g_speed)--;
					*g_count_down = 3000;
				}
				(*g_count_down)-=200;
				Sleep(*g_speed);
			};
		}
		else {
			destroyed = *g_destroyed;
			score = *g_score;

			delete g_life;
			delete g_score;
			delete g_destroyed;
			delete g_bulletSpeed;
			delete g_speed;

			delete B_th;
			delete E_th;

			delete g_playerSize;

			delete tempPosBulletX;
			delete tempPosBulletY;
			break;
		}
	}
};
#pragma endregion

#pragma region player
//void drawSpaceship(string object) {
//	playerPos.prevPosX = random(10, 30);
//	playerPos.prevPosY = random(35, 39);
//	playerPos.nextPosX = 0;
//	playerPos.nextPosY = 0;
//	gotoXY(playerPos.prevPosX, playerPos.prevPosY);
//	cout << object;
//}
//void controlSpaceship() {
//	if (activities == Activities::top)
//	{
//		playerPos.nextPosX = playerPos.prevPosX;
//		playerPos.nextPosY = playerPos.prevPosY - 1;
//	}
//	else if (activities == Activities::bottom)
//	{
//		playerPos.nextPosX = playerPos.prevPosX;
//		playerPos.nextPosY = playerPos.prevPosY + 1;
//	}
//	else if (activities == Activities::left)
//	{
//		playerPos.nextPosX = playerPos.prevPosX - 1;
//		playerPos.nextPosY = playerPos.prevPosY;
//	}
//	else if (activities == Activities::right)
//	{
//		playerPos.nextPosX = playerPos.prevPosX + 1;
//		playerPos.nextPosY = playerPos.prevPosY;
//	}
//	else if (activities == Activities::stop)
//	{
//		playerPos.nextPosX = playerPos.prevPosX;
//		playerPos.nextPosY = playerPos.prevPosY;
//	}
//	else if (activities == Activities::fire)
//	{
//		playerPos.nextPosX = playerPos.prevPosX;
//		playerPos.nextPosY = playerPos.prevPosY;
//	}
//
//}
void moveSpaceship(string object) {
	//if (*c == 'j')
	//{
	//	//drawBullet();
	//	controlBullet();
	//	moveBullet();
	//	*c = ' ';
	//	//fileDataEven << c << ' ' << "yes" << endl;
	//}
	if (!isPlayerHitWall(playerPos.nextPosX, playerPos.nextPosY, playerWeak.getObjectP()))
	{
		gotoXY(playerPos.prevPosX, playerPos.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		gotoXY(playerPos.nextPosX, playerPos.nextPosY);
		playerPos.prevPosX = playerPos.nextPosX;
		playerPos.prevPosY = playerPos.nextPosY;
		cout << object;

		//fileDataP << "playerPos.prevPosX: " << playerPos.prevPosX << endl;
		//fileDataP << "playerPos.prevPosY: " << playerPos.prevPosY << endl;
		//fileDataP << "playerPos.nextPosX: " << playerPos.nextPosX << endl;
		//fileDataP << "playerPos.nextPosY: " << playerPos.nextPosY << endl;
		//fileDataP << " " << endl;

	};
}
#pragma endregion

#pragma region enemyControl
//void drawEnemy(string object) {
//	enemyPos.nextPosX = 0;
//	enemyPos.nextPosY = 0;
//	enemyPos.prevPosX = random(11, 31);
//	enemyPos.prevPosY = random(1, 5);
//	gotoXY(enemyPos.prevPosX, enemyPos.prevPosY);
//	cout << object;
//}

void controlEnemy() {
	enemyPos.nextPosX = enemyPos.prevPosX;
	enemyPos.nextPosY = enemyPos.prevPosY + 1;
	if (isPlayerHitEnemy(playerWeak.getObjectP(), enemyWeak.getObjectE())) //true
	{
		*g_score = *g_score + enemyWeak.getRewardPoint();
		*g_destroyed = *g_destroyed + enemyWeak.getRewardPoint();
		*g_life = *g_life - enemyWeak.getMinusPoint();
		destroyObject(enemyWeak.getObjectE(), enemyPos.prevPosX, enemyPos.prevPosY);
	}
	else if (isEnemyHitWall(enemyPos.nextPosY))
	{
		*g_life = *g_life - 1;
		destroyObject(enemyWeak.getObjectE(), enemyPos.prevPosX, enemyPos.prevPosY);
	}
	else //false
	{
		moveEnemy(enemyWeak.getObjectE());
	};
}
void moveEnemy(string object) {
	if (!isEnemyHitWall(enemyPos.nextPosY))
	{
		gotoXY(enemyPos.prevPosX, enemyPos.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		gotoXY(enemyPos.nextPosX, enemyPos.nextPosY);
		enemyPos.prevPosX = enemyPos.nextPosX;
		enemyPos.prevPosY = enemyPos.nextPosY;
		cout << object;

		//fileDataE << "enemyPos.prevPosX: " << enemyPos.prevPosX << endl;
		//fileDataE << "enemyPos.prevPosY: " << enemyPos.prevPosY << endl;
		//fileDataE << "enemyPos.nextPosX: " << enemyPos.nextPosX << endl;
		//fileDataE << "enemyPos.nextPosY: " << enemy.nextPosY << endl;
		//fileDataE << " " << endl;	
	}
	else {
		*g_life = *g_life - enemyWeak.getMinusPoint();
	}
}
void destroyObject(string object, int prevX, int prevY) { //done
	gotoXY(prevX, prevY);
	cout << setfill(' ');
	cout << setw(object.size()) << right << ' ';
	//drawEnemy(enemyWeak.getObjectE());
	drawObject(enemyWeak.getObjectE(), enemyPos, 11, 31, 1, 5, 2);
	teamE[*E_th] = enemyPos;
}
#pragma endregion

#pragma region bullet
//void drawBullet() {
//	bulletPos.prevPosX = (playerPos.prevPosX + *playerSize / 2); //vi tri trung tam
//	bulletPos.prevPosY = playerPos.prevPosY - 1;
//	gotoXY(bulletPos.prevPosX, bulletPos.prevPosY);
//	cout << playerWeak.getBullet();
//}
void controlBullet() {
	bulletPos.nextPosX = bulletPos.prevPosX;
	bulletPos.nextPosY = bulletPos.prevPosY - 1;
	teamB[*B_th] = bulletPos;
	moveBullet();
}
void moveBullet() {
	bulletPos = teamB[*B_th];
	if (!isBulletHitEnemy(enemyWeak.getObjectE()) && !isBulletHitWall(bulletPos.nextPosY))
	{
		gotoXY(bulletPos.prevPosX, bulletPos.prevPosY);
		cout << ' ';

		gotoXY(bulletPos.nextPosX, bulletPos.nextPosY);
		cout << playerWeak.getBullet();

		bulletPos.prevPosX = bulletPos.nextPosX;
		bulletPos.prevPosY = bulletPos.nextPosY;

		//fileDataE << "bulletPos.prevPosX: " << bulletPos.prevPosX << endl;
		//fileDataE << "bulletPos.prevPosY: " << bulletPos.prevPosY << endl;
		//fileDataE << "bulletPos.nextPosX: " << bulletPos.nextPosX << endl;
		//fileDataE << "bulletPos.nextPosY: " << bulletPos.nextPosY << endl;
		//fileDataE << " " << endl;

	}
	else if (isBulletHitWall(bulletPos.nextPosY))
	{
		gotoXY(bulletPos.prevPosX, bulletPos.prevPosY);
		cout << ' ';
		//bulletPos.nextPosX = 0;
		//bulletPos.prevPosX = 0;
		//bulletPos.nextPosY = 0;
		//bulletPos.prevPosY = 0;
		teamB.erase(teamB.begin() + *B_th);
	}
	else {
		*g_score = *g_score + enemyWeak.getRewardPoint();
		*g_destroyed = *g_destroyed + enemyWeak.getMinusPoint();
		destroyObject(enemyWeak.getObjectE(), enemyPos.prevPosX, enemyPos.prevPosY);
		gotoXY(bulletPos.prevPosX, bulletPos.prevPosY);
		cout << ' ';
		//bullet.nextPosX = 0;
		//bulletPos.prevPosX = 0;
		//bulletPos.nextPosY = 0;
		//bulletPos.prevPosY = 0;
		teamB.erase(teamB.begin() + *B_th);
	};
};
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
		enemyPos.nextPosX = 0;
		enemyPos.nextPosY = 0;
		return true;
	}return false;
};
bool isPlayerHitEnemy(string objectP, string objectE) { //done
	//objectP: playerWeak.getObjectP()
	//objectE: enemyWeak.getObject()
	int openLimitX = playerPos.prevPosX - objectE.size() + 1;
	int endLimitX = playerPos.prevPosX + objectP.size();
	bool isEven = calDistanceBetweenPE(playerPos.prevPosY, enemyPos.prevPosY);
	if (isEven == true) //number is even
	{

		{if (enemyPos.prevPosX >= openLimitX && enemyPos.prevPosX <= endLimitX)

			if (enemyPos.nextPosY == playerPos.prevPosY || enemyPos.prevPosY == playerPos.nextPosY)
				return true;
		}
	}
	else if (isEven == false)
	{
		if (enemyPos.prevPosX >= openLimitX && enemyPos.prevPosX <= endLimitX)
		{
			if (playerPos.nextPosY == enemyPos.nextPosY || playerPos.prevPosY == enemyPos.prevPosY)
				return true;
		};
	};
	return false;
}
bool isBulletHitEnemy(string objectE) {

	bulletPos = teamB[*B_th];
	for (int j = 0; j < teamE.size(); j++)
	{
		enemyPos = teamE[j];
		*E_th = j;
		if (bulletPos.nextPosY == enemyPos.prevPosY || bulletPos.nextPosY == enemyPos.prevPosY - 1 || bulletPos.prevPosY == enemyPos.prevPosY)
		{
			if (bulletPos.nextPosX >= enemyPos.prevPosX && bulletPos.nextPosX <= enemyPos.prevPosX + enemyWeak.getObjectE().size())
			{
				return true;
			};
		};
	}
	return false;
};
bool isBulletHitWall(int nextPosY) {
	bulletPos = teamB[*B_th];
	if (nextPosY == 1)
	{
		return true;
	}
	return false;
};
#pragma endregion

#pragma region calculaor
bool calDistanceBetweenPE(int prevPosYP, int prevPosYE) { //done
	int temp = (prevPosYP - prevPosYE) % 2;
	if (temp == 0)
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
