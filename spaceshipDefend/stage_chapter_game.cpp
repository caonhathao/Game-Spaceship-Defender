#include<iostream>
#include<time.h>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<winsdkver.h>

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

#define _WIN32_WINNT_WIN10 0x0A00

//struct
struct Postion;
struct result;

#pragma region gameClass
//Player PlayerWeak(5, 100, "|-[O]-|", '.');
//Enemy EnemyWeak(70, 1, 1, "|-x-|");
#pragma endregion

//general values;
#pragma region generalVariablesAndSetting
int* g_bulletSpeed = new int(30); //toc do dan

int* g_g_score = new int(0);
int* g_g_destroyed = new int(0);
static int* g_life = new int(PlayerWeak->getLife());

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
void drawg_scoreBoard();
void drawTurtorial();

void stage_chapter_game(int& speed, int& g_score, int& g_destroyed);

//void drawSpaceship(string object);
//void drawEnemy(string object);
//void drawBullet();

//void controlSpaceship();
void controlEnemy();
void controlBullet();

void moveSpaceship(string object);
void moveEnemy(string object);
void moveBullet();

void g_destroyObject(string object, int prevX, int prevY);

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
	setColor(0, 14); //Light Yellow
	atXY(0, 0);
	for (int i = 0; i < widthPlayArea + 1; i++)
	{
		atXY(i, 0);
		cout << '-';
		Sleep(2);
	}
	atXY(0, 1);
	for (int i = 1; i < heightPlayArea + 1; i++)
	{
		atXY(0, i);
		cout << '|';
		Sleep(2);
	}
	atXY(widthPlayArea, 1);
	for (int i = 1; i < heightPlayArea + 1; i++)
	{
		atXY(widthPlayArea, i);
		cout << '|';
		Sleep(2);
	};
	atXY(0, heightPlayArea);
	for (int i = 1; i < widthPlayArea; i++)
	{
		atXY(i, heightPlayArea);
		cout << '_';
		Sleep(2);
	}
}
void drawg_scoreBoard() {
	//widthPlayArea = 45 (y)
	//heightPlayArea = 45 (x)

	setColor(0, 8);//Gray
	atXY(widthPlayArea + 13, 0);
	cout << "<<--->> R.E.C.O.R.D <<--->>";

	//cao:11,rong:31
	//13 hang 
	setColor(0, 14);//Light Yellow
	atXY(widthPlayArea + 10, 1);
	for (int i = 1; i < 12; i++)
	{
		atXY(widthPlayArea + 10, i);
		cout << '|';
		Sleep(2);
	};
	atXY(widthPlayArea + 11, 11);
	for (int i = widthPlayArea + 11; i < widthPlayArea + 42; i++)
	{
		atXY(i, 11);
		cout << '_';
		Sleep(2);
	};
	atXY(widthPlayArea + 42, 15);
	for (int i = 11; i >= 1; i--)
	{
		atXY(widthPlayArea + 42, i);
		cout << '|';
		Sleep(2);
	};

	//life
	atXY(widthPlayArea + 13, 2);
	cout << "LIFE: ";
	//detroy
	atXY(widthPlayArea + 13, 4);
	cout << "g_destroy: ";
	//g_score
	atXY(widthPlayArea + 13, 6);
	cout << "g_score: ";
	//energy
	atXY(widthPlayArea + 13, 8);
	cout << "ENERGY: ";
	//speed
	atXY(widthPlayArea + 13, 10);
	cout << "SPEED: ";
}
void showg_score() {
	setColor(0, 11);//Light Aqua
	atXY(widthPlayArea + 13 + 7, 2);
	cout << *g_life;
	atXY(widthPlayArea + 13 + 9, 4);
	cout << *g_g_destroyed;
	atXY(widthPlayArea + 13 + 7, 6);
	cout << *g_g_score;

	atXY(widthPlayArea + 13 + 8, 10);
	cout << *g_speed + (200 - *g_speed);
}
void drawTurtorial() {
	setColor(0, 8);
	atXY(widthPlayArea + 58, 0);
	cout << "<<--->> T.U.R.T.O.R.I.A.L <<--->>";

	setColor(0, 14);
	atXY(widthPlayArea + 51, 1);
	for (int i = 1; i < 12; i++)
	{
		atXY(widthPlayArea + 51, i);
		cout << '|';
		Sleep(2);
	}
	atXY(widthPlayArea + 52, 11);
	for (int i = widthPlayArea + 52; i < widthPlayArea + 96; i++)
	{
		atXY(i, 11);
		cout << '_';
		Sleep(2);
	};
	atXY(widthPlayArea + 96, 13);
	for (int i = 11; i >= 1; i--)
	{
		atXY(widthPlayArea + 96, i);
		cout << '|';
		Sleep(2);
	};

	atXY(widthPlayArea + 53, 2);
	cout << "Press ";
	setColor(0, 12);//Light Red
	cout << "'WASD'";
	setColor(0, 14);//Light Yellow
	cout << " to control your spaceship.";

	atXY(widthPlayArea + 53, 4);
	cout << "Press ";
	setColor(0, 12);
	cout << "'j'";
	setColor(0, 14);
	cout << " to fire the Enemy.";

	atXY(widthPlayArea + 53, 6);
	cout << "Press ";
	setColor(0, 12);
	cout << "'space'";
	setColor(0, 14);
	cout << " to stop your spaceship.";

	atXY(widthPlayArea + 53, 8);
	cout << "Press ";
	setColor(0, 12);;
	cout << "'p'";
	setColor(0, 14);
	cout << " to pause game.";

	atXY(widthPlayArea + 53, 10);
	cout << "Press ";
	setColor(0, 12);
	cout << "'r'";
	setColor(0, 14);
	cout << " to back the menu";
}
#pragma endregion

#pragma region main
void stage_chapter_game(int& speed, int& g_score, int& g_destroyed) {
	srand(time(NULL));

	system("cls");

	drawPlayArea(widthPlayArea, heightPlayArea);
	drawg_scoreBoard();
	drawTurtorial();
	//drawSpaceship(PlayerWeak.getObjectP());
	drawObject(PlayerWeak->getObjectP(), PlayerPos, 10, 30, 35, 39, 3);

	for (int i = 0; i < 3; i++)
	{
		//drawEnemy(EnemyWeak.getObjectE());
		drawObject(EnemyWeak->getObjectE(), EnemyPos, 11, 31, 1, 5, 4);
		teamE.push_back(EnemyPos);
	};

	*g_count_down = 3000;
	*g_PlayerSize = PlayerWeak->getObjectP().size();

	*c = ' ';
	while (true)
	{
		*tempPosBulletX = PlayerPos.prevPosX + int(*g_PlayerSize / 2);
		*tempPosBulletY = PlayerPos.prevPosY - 1;

		if (*g_life != 0)
		{
			if (_kbhit())
			{
				*c = _getch();
				*c = tolower(*c);
				controlSignal(activities, *c, *g_speed, *g_step);
				if (*c == 'j')
				{
					activities = Activities::fire;
					fire_sign++;
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
				controlWithoutEvent(activities, PlayerPos, *g_step);
				moveSpaceship(PlayerWeak->getObjectP());
				for (int i = 0; i < teamE.size(); i++)
				{
					EnemyPos = teamE[i];
					*E_th = i;
					controlEnemy();
					teamE[i] = EnemyPos;
				}
				if (*c == 'j')
				{
					drawObject(PlayerWeak->getBullet(), bulletPos, *tempPosBulletX, *tempPosBulletX, *tempPosBulletY, *tempPosBulletY, 6);//Yellow
					teamB.push_back(bulletPos);
					*c = ' ';
				};
				if (teamB.size() > 0)
				{
				replay:

					/* DESCRIPTION: attention on this
					* - doan code nay giup kiem tra xem lieu co bullet[i] nao danh trung Enemy[j] khong.
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
				showg_score();
				if (*g_count_down == 0)
				{
					(*g_speed)--;
					*g_count_down = 3000;
				}
				(*g_count_down) -= 200;
				Sleep(*g_speed);
			};
		}
		else {
			g_destroyed = *g_g_destroyed;
			g_score = *g_g_score;

			delete g_life;
			delete g_g_score;
			delete g_g_destroyed;
			delete g_bulletSpeed;
			delete g_speed;

			delete B_th;
			delete E_th;

			delete g_PlayerSize;

			delete tempPosBulletX;
			delete tempPosBulletY;
			break;
		}
	}
};
#pragma endregion

#pragma region Player
void moveSpaceship(string object) {
	//if (*c == 'j')
	//{
	//	//drawBullet();
	//	controlBullet();
	//	moveBullet();
	//	*c = ' ';
	//	//fileDataEven << c << ' ' << "yes" << endl;
	//}
	if (!isPlayerHitWall(PlayerPos.nextPosX, PlayerPos.nextPosY, PlayerWeak->getObjectP()))
	{
		atXY(PlayerPos.prevPosX, PlayerPos.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		atXY(PlayerPos.nextPosX, PlayerPos.nextPosY);
		PlayerPos.prevPosX = PlayerPos.nextPosX;
		PlayerPos.prevPosY = PlayerPos.nextPosY;
		setColor(0, 3);
		cout << object;

		//fileDataP << "PlayerPos.prevPosX: " << PlayerPos.prevPosX << endl;
		//fileDataP << "PlayerPos.prevPosY: " << PlayerPos.prevPosY << endl;
		//fileDataP << "PlayerPos.nextPosX: " << PlayerPos.nextPosX << endl;
		//fileDataP << "PlayerPos.nextPosY: " << PlayerPos.nextPosY << endl;
		//fileDataP << " " << endl;

	};
}
#pragma endregion

#pragma region EnemyControl
void controlEnemy() {
	EnemyPos.nextPosX = EnemyPos.prevPosX;
	EnemyPos.nextPosY = EnemyPos.prevPosY + 1;
	if (isPlayerHitEnemy(PlayerWeak->getObjectP(), EnemyWeak->getObjectE())) //true
	{
		*g_g_score = *g_g_score + EnemyWeak->getRewardPoint();
		*g_g_destroyed = *g_g_destroyed + EnemyWeak->getRewardPoint();
		*g_life = *g_life - EnemyWeak->getMinusPoint();
		g_destroyObject(EnemyWeak->getObjectE(), EnemyPos.prevPosX, EnemyPos.prevPosY);
	}
	else if (isEnemyHitWall(EnemyPos.nextPosY))
	{
		*g_life = *g_life - 1;
		g_destroyObject(EnemyWeak->getObjectE(), EnemyPos.prevPosX, EnemyPos.prevPosY);
	}
	else //false
	{
		moveEnemy(EnemyWeak->getObjectE());
	};
}
void moveEnemy(string object) {
	if (!isEnemyHitWall(EnemyPos.nextPosY))
	{
		atXY(EnemyPos.prevPosX, EnemyPos.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		atXY(EnemyPos.nextPosX, EnemyPos.nextPosY);
		EnemyPos.prevPosX = EnemyPos.nextPosX;
		EnemyPos.prevPosY = EnemyPos.nextPosY;
		setColor(0, 4);
		cout << object;

		//fileDataE << "EnemyPos.prevPosX: " << EnemyPos.prevPosX << endl;
		//fileDataE << "EnemyPos.prevPosY: " << EnemyPos.prevPosY << endl;
		//fileDataE << "EnemyPos.nextPosX: " << EnemyPos.nextPosX << endl;
		//fileDataE << "EnemyPos.nextPosY: " << Enemy.nextPosY << endl;
		//fileDataE << " " << endl;	
	}
	else {
		*g_life = *g_life - EnemyWeak->getMinusPoint();
	}
}
void g_destroyObject(string object, int prevX, int prevY) { //done
	atXY(prevX, prevY);
	cout << setfill(' ');
	cout << setw(object.size()) << right << ' ';
	//drawEnemy(EnemyWeak.getObjectE());
	drawObject(EnemyWeak->getObjectE(), EnemyPos, 11, 31, 1, 5, 2);
	teamE[*E_th] = EnemyPos;
}
#pragma endregion

#pragma region bullet
//void drawBullet() {
//	bulletPos.prevPosX = (PlayerPos.prevPosX + *PlayerSize / 2); //vi tri trung tam
//	bulletPos.prevPosY = PlayerPos.prevPosY - 1;
//	atXY(bulletPos.prevPosX, bulletPos.prevPosY);
//	cout << PlayerWeak.getBullet();
//}
void controlBullet() {
	bulletPos.nextPosX = bulletPos.prevPosX;
	bulletPos.nextPosY = bulletPos.prevPosY - 1;
	teamB[*B_th] = bulletPos;
	moveBullet();
}
void moveBullet() {
	bulletPos = teamB[*B_th];
	if (!isBulletHitEnemy(EnemyWeak->getObjectE()) && !isBulletHitWall(bulletPos.nextPosY))
	{
		atXY(bulletPos.prevPosX, bulletPos.prevPosY);
		cout << ' ';

		atXY(bulletPos.nextPosX, bulletPos.nextPosY);
		setColor(0, 6);
		cout << PlayerWeak->getBullet();

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
		atXY(bulletPos.prevPosX, bulletPos.prevPosY);
		cout << ' ';
		//bulletPos.nextPosX = 0;
		//bulletPos.prevPosX = 0;
		//bulletPos.nextPosY = 0;
		//bulletPos.prevPosY = 0;
		teamB.erase(teamB.begin() + *B_th);
	}
	else {
		*g_g_score = *g_g_score + EnemyWeak->getRewardPoint();
		*g_g_destroyed = *g_g_destroyed + EnemyWeak->getMinusPoint();
		g_destroyObject(EnemyWeak->getObjectE(), EnemyPos.prevPosX, EnemyPos.prevPosY);
		atXY(bulletPos.prevPosX, bulletPos.prevPosY);
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
		EnemyPos.nextPosX = 0;
		EnemyPos.nextPosY = 0;
		return true;
	}return false;
};
bool isPlayerHitEnemy(string objectP, string objectE) { //done
	//objectP: PlayerWeak.getObjectP()
	//objectE: EnemyWeak.getObject()
	int openLimitX = static_cast<int>(PlayerPos.prevPosX - objectE.size() + 1);
	size_t endLimitX = PlayerPos.prevPosX + objectP.size();
	bool isEven = calDistanceBetweenPE(PlayerPos.prevPosY, EnemyPos.prevPosY);
	if (isEven == true) //number is even
	{

		{if (EnemyPos.prevPosX >= openLimitX && EnemyPos.prevPosX <= endLimitX)

			if (EnemyPos.nextPosY == PlayerPos.prevPosY || EnemyPos.prevPosY == PlayerPos.nextPosY)
				return true;
		}
	}
	else if (isEven == false)
	{
		if (EnemyPos.prevPosX >= openLimitX && EnemyPos.prevPosX <= endLimitX)
		{
			if (PlayerPos.nextPosY == EnemyPos.nextPosY || PlayerPos.prevPosY == EnemyPos.prevPosY)
				return true;
		};
	};
	return false;
}
bool isBulletHitEnemy(string objectE) {

	bulletPos = teamB[*B_th];
	for (int j = 0; j < teamE.size(); j++)
	{
		EnemyPos = teamE[j];
		*E_th = j;
		if (bulletPos.nextPosY == EnemyPos.prevPosY || bulletPos.nextPosY == EnemyPos.prevPosY - 1 || bulletPos.prevPosY == EnemyPos.prevPosY)
		{
			if (bulletPos.nextPosX >= EnemyPos.prevPosX && bulletPos.nextPosX <= EnemyPos.prevPosX + EnemyWeak->getObjectE().size())
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
