#include<iostream>
#include<conio.h>
#include<time.h>
#include<iomanip>
#include<cstring>
#include<string>
#include<vector>
#include<fstream>

#include"struct.cpp"
#include"Activities.cpp"

#include"functions_control_console.h"
#include"functions_control_object.h"
#include"player.h"
#include"variable.h"
#include"effects_text.h"

using namespace std;

struct Position;
struct result;
struct PosAndLength {
	int prevPosX = 0 ;
	int prevPosY = 0;

	int nextPosX = 0;
	int nextPosY = 0;

	int length = 0;
	string line = "";
};

//#pragma region fileDataTest
//ofstream fileDataEven("./logEven.txt");
//ofstream fileDataP("./logP.txt");
//ofstream fileDataE("./logE.txt");
//#pragma endregion

#pragma region generalVariableAndSetting
int lengthLine = 45;
int widthLine = 60;

int* Ba_th = new int(0);
int* pos = new int(0);
int* amount = new int(0);
int* impact = new int(0);
bool* sign = new bool(false);

PosAndLength BARRIER;

vector<PosAndLength>barrier = {};
#pragma endregion

#pragma region functions
void loadingScreen();

void noticeStart();
void noticeFinish();

void drawPlayArea();
void drawNoticePlayer();
void drawInfoNotice();;

void stage_chapter_2(int speed, int& process, int& contact);

//void drawPlayer(string object);
//void controlPlayer();
void movePlayer(string object);

void drawBarrier();
void controlBarrier();
void moveBarrier();

bool isPlayerHitWall();
bool isPlayerImpactBarrier();
bool isBarrierHitWall();

int random(int minN, int maxN);
#pragma endregion

#pragma region funcsDecoration
void noticeStart() {
	system("cls");
	string para = "[ Nhiem vu: tranh cac chuong ngai vat ]";
	effectText_char(para, 20);
	cout << endl;

	stringFlicker("/* Press 'r' to continue ! */", 0, 3, 2, 3);

	//setColor(0, 2);
	//cout << ;
	//*c = ' ';
	//while (*c != 'r')
	//{
	//	if (_kbhit()) {
	//		*c = _getch();
	//		*c = tolower(*c);
	//	}
	//};
	system("cls");
}
void noticeFinish() {
	system("cls");
	setColor(0, 12);
	string para = "[ Chuc mung ban da hoan thanh thu thach ! ]";
	effectText_char(para, 20);
	cout << endl;
	system("cls");
}
void drawPlayArea() {
	setColor(0, 7);
	for (int i = 0; i <= widthLine; i++)
	{
		gotoXY(45 + i, 5);//(45 -105, 5)
		cout << '-';
	};
	for (int i = 1; i <= lengthLine; i++)
	{
		gotoXY(45, 5 + i); cout << '|';//(45, 6 - 50)
		gotoXY(45 + widthLine, 5 + i); cout << '|';
	};
	for (int i = 0; i <= widthLine; i++)
	{
		gotoXY(45 + i, 5 + lengthLine); cout << '-';
	};
}
void drawNoticePlayer() {
	gotoXY(125, 5);
	setColor(0, 12);
	cout << "--- <<< [---] >>> NOTICE <<< [---] >>> ---";
	setColor(0, 6);
	for (int i = 1; i <= 12; i++)
	{
		gotoXY(125, 5 + i);
		cout << '|';
		gotoXY(167, 5 + i);
		cout << '|';
	}
	for (int i = 0; i <= 42; i++)
	{
		gotoXY(125 + i, 17); cout << '-';
	};
}
void drawInfoNotice() {
	setColor(0, 4);
	gotoXY(127, 6);
	cout << "Nhiem vu:";
	gotoXY(127, 7);
	setColor(0, 3);
	cout << "[ Tranh hoac ban pha cac vat can. ]";
	gotoXY(127, 8);
	setColor(0, 3);
	cout << "Luu y:";
	gotoXY(127, 9);
	setColor(0, 3);
	cout << "(toi thieu can vuot qua 120 / 120)";

	gotoXY(127, 12);
	setColor(0, 2);
	cout << "Tien trinh: 0";
	gotoXY(127, 13);
	setColor(0, 2);
	cout << "So va cham: ";

	gotoXY(127, 15);
	cout << "[ Press 'p' to pause ]";
}
#pragma endregion

#pragma region main
void stage_chapter_2(int speed, int& process, int& contact) {
	noticeStart();

	drawPlayArea();
	drawNoticePlayer();
	drawInfoNotice();

	//drawPlayer(playerWeak.getObjectP());
	drawObject(playerWeak.getObjectP(), playerPos, 50, 90, 40, 49, 2);

	*g_count_down = 2000;

	*c = ' ';

	while (true)
	{
		if (_kbhit())
		{
			*c = _getch();
			*c = tolower(*c);
			//if (*c == 'w')
			//{
			//	activities = Activities::top;
			//}
			//else if (*c == 's')
			//{
			//	activities = Activities::bottom;
			//}
			//else if (*c == 'a')
			//{
			//	activities = Activities::left;
			//}
			//else if (*c == 'd') {
			//	activities = Activities::right;
			//}
			//else if (*c == ' ')
			//{
			//	activities = Activities::stop;
			//};
			controlSignal(activities, *c, speed, 200);
		}
		if (*c == 'p')
		{
			while (*c == 'p')
			{
				if (_kbhit()) {
					*c = _getch();
					*c = tolower(*c);
				}
			}
		};
		if (*pos % 4 == 0)
		{
			drawBarrier();
			barrier.push_back(BARRIER);
		};
		*pos = *pos + 1;

		replay:
		int length = barrier.size();
		if (length > 0)
		{
			for (int i = 0; i < barrier.size(); i++)
			{
				*Ba_th = i;
				BARRIER = barrier[i];
				controlBarrier();
				setColor(0, 2);
				gotoXY(139, 13);
				cout << *impact;
				if (length == barrier.size())
				{
					barrier[i] = BARRIER;
				}
				else {;
					goto replay;
				}
				if (isBarrierHitWall())
				{
					*amount = *amount + 1;
					gotoXY(139, 12);
					cout << *amount;
					if (*amount >= 120)
					{
						*sign = true;
						break;
					};
				}
			}
		};
		if (*sign == true)
		{
			break;
		};
		//controlPlayer();
		if (isPlayerHitWall())
		{
			playerPos.nextPosX = playerPos.prevPosX;
			playerPos.nextPosY = playerPos.prevPosY;
		}
		else
		{
			controlWithoutEvent(activities, playerPos);
			movePlayer(playerWeak.getObjectP());
		};
		if (*g_count_down == 0)
		{
			speed -= 10;
			*g_count_down = 2000;
		}
		else {
			(*g_count_down)--;
		};
		Sleep(speed);
	}
	process = *amount;
	contact = *impact;
	delete Ba_th;
	delete pos;
	delete amount;
	delete sign;
	delete impact;
	noticeFinish();

	stringFlicker("/* Press 'r' to continue ! */", 0, 3, 2, 4);
}
#pragma endregion

#pragma region player
//void drawPlayer(string object) {
//	playerPos.prevPosX = random(50, 90);
//	playerPos.prevPosY = random(40, 49);
//	gotoXY(playerPos.prevPosX,playerPos.prevPosY);
//	setColor(0, 2);
//	cout << playerWeak.getObjectP();
//}
//void controlPlayer() {
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
//		playerPos.prevPosY = playerPos.prevPosY;
//	}
//	else if (activities == Activities::right)
//	{
//		playerPos.nextPosX = playerPos.prevPosX + 1;
//		playerPos.nextPosY = playerPos.prevPosY;
//	}
//	else if (activities == Activities::stop || isPlayerHitWall())
//	{
//		playerPos.nextPosX = playerPos.prevPosX;
//		playerPos.nextPosY = playerPos.prevPosY;
//	};
//}
void movePlayer(string object) {
	bool isHitWall = isPlayerHitWall();

	if (!isPlayerHitWall() && !isPlayerImpactBarrier())
	{
		gotoXY(playerPos.prevPosX, playerPos.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		gotoXY(playerPos.nextPosX, playerPos.nextPosY);
		setColor(0, 2);
		cout << object;
		playerPos.prevPosX = playerPos.nextPosX;
		playerPos.prevPosY = playerPos.nextPosY;

		//fileDataP << "playerWeak.prevPosX: " << playerPos.prevPosX << endl;
		//fileDataP << "playerWeak.prevPosY: " << playerPos.prevPosY << endl;
		//fileDataP << "playerWeak.nextPosX: " << playerPos.nextPosX << endl;
		//fileDataP << "playerWeak.nextPosY: " << playerPos.nextPosY << endl;
		//fileDataP << " " << endl;
	}
	else
	{
		*c = ' ';
	};
};
#pragma endregion

#pragma region barrier
void drawBarrier() {
	BARRIER.line = "";
	BARRIER.length = random(2, 4);
	for (int i = 0; i < BARRIER.length; i++)
	{
		BARRIER.line = BARRIER.line + 'O';
	}
	BARRIER.prevPosX = random(46, 101);
	BARRIER.prevPosY = random(6, 10);
	gotoXY(BARRIER.prevPosX, BARRIER.prevPosY);
	setColor(0, 5);
	cout << BARRIER.line;
};
void controlBarrier() {
	BARRIER.nextPosX = BARRIER.prevPosX;
	BARRIER.nextPosY = BARRIER.prevPosY + 1;
	moveBarrier();
}
void moveBarrier() {
	bool isImpactBarrier = isPlayerImpactBarrier();
	if (!isBarrierHitWall() && !isPlayerImpactBarrier())
	{
		gotoXY(BARRIER.prevPosX, BARRIER.prevPosY);
		cout << setfill(' ');
		cout << setw(BARRIER.length) << right << ' ';

		gotoXY(BARRIER.nextPosX, BARRIER.nextPosY);
		setColor(0, 5);
		cout << BARRIER.line;
		BARRIER.prevPosX = BARRIER.nextPosX;
		BARRIER.prevPosY = BARRIER.nextPosY;
	}
	else if (isImpactBarrier)
	{
		*impact = *impact + 1;
		gotoXY(BARRIER.prevPosX, BARRIER.prevPosY);
		cout << setfill(' ');
		cout << setw(BARRIER.length) << right << ' ';
		barrier.erase(barrier.begin() + *Ba_th);
	}
	else {
		gotoXY(BARRIER.prevPosX, BARRIER.prevPosY);
		cout << setfill(' ');
		cout << setw(BARRIER.length) << right << ' ';
		barrier.erase(barrier.begin() + *Ba_th);
	};
}
#pragma endregion

#pragma region checkingEvents
bool isPlayerHitWall() {
	if (playerPos.nextPosX <= 45 || playerPos.nextPosX >= 101)
	{
		if (playerPos.nextPosY >= 5 && playerPos.nextPosY <= 50)
		{
			return true;
		}
	};
	if (playerPos.nextPosX >= 45 && playerPos.nextPosX <= 101)
	{
		if (playerPos.nextPosY >= 50 || playerPos.nextPosY <= 5)
		{
			return true;
		}
	};
	return false;
}
bool isBarrierHitWall() {
	if (BARRIER.nextPosY == 50)
	{
		return true;
	};
	return false;
}
bool isPlayerImpactBarrier() {
	if (BARRIER.nextPosX >= playerPos.nextPosX && BARRIER.nextPosX + BARRIER.line.length() <= playerPos.nextPosX + playerWeak.getObjectP().length())
	{
		if (BARRIER.nextPosY == playerPos.nextPosY || BARRIER.prevPosY == playerPos.nextPosY || BARRIER.nextPosY == playerPos.prevPosY)
		{
			return true;
		}
	};
	return false;
};
#pragma endregion
