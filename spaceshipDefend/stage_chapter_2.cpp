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

#pragma region fileDataTest
ofstream fileDataEven("./logEven.txt");
ofstream fileDataP("./logP.txt");
ofstream fileDataE("./logE.txt");
#pragma endregion

#pragma region generalVariableAndSetting
int lengthLine = 45;
int widthLine = 60;

int* Ba_th = new int(0); //serial of barrier

int* pos = new int(0);

int* amount = new int(0);
int* impact = new int(0);

bool* sign = new bool(false); //signal to break the loop
bool* isProduct = new bool(true);

PosAndLength BARRIER;

vector<PosAndLength>barriers= {};
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

void drawBarrier(bool& isProduct);
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
}
void drawPlayArea() {
	setColor(0, 7);
	for (int i = 0; i <= widthLine; i++)
	{
		go_to_xy(45 + i, 5);//(45 -105, 5)
		cout << '-';
	};
	for (int i = 1; i <= lengthLine; i++)
	{
		go_to_xy(45, 5 + i); cout << '|';//(45, 6 - 50)
		go_to_xy(45 + widthLine, 5 + i); cout << '|';
	};
	for (int i = 0; i <= widthLine; i++)
	{
		go_to_xy(45 + i, 5 + lengthLine); cout << '-';
	};
}
void drawNoticePlayer() {
	go_to_xy(125, 5);
	setColor(0, 12);
	cout << "--- <<< [---] >>> NOTICE <<< [---] >>> ---";
	setColor(0, 6);
	for (int i = 1; i <= 12; i++)
	{
		go_to_xy(125, 5 + i);
		cout << '|';
		go_to_xy(167, 5 + i);
		cout << '|';
	}
	for (int i = 0; i <= 42; i++)
	{
		go_to_xy(125 + i, 17); cout << '-';
	};
}
void drawInfoNotice() {
	setColor(0, 4);
	go_to_xy(127, 6);
	cout << "Nhiem vu:";
	go_to_xy(127, 7);
	setColor(0, 3);
	cout << "[ Tranh hoac ban pha cac vat can. ]";
	go_to_xy(127, 8);
	setColor(0, 3);
	cout << "Luu y:";
	go_to_xy(127, 9);
	setColor(0, 3);
	cout << "(toi thieu can vuot qua 120 / 120)";

	go_to_xy(127, 12);
	setColor(0, 2);
	cout << "Tien trinh: 0";
	go_to_xy(127, 13);
	setColor(0, 2);
	cout << "So va cham: ";

	go_to_xy(127, 15);
	cout << "[ Press 'p' to pause ]";
}
#pragma endregion

#pragma region main
void stage_chapter_2(int speed, int& process, int& contact) {
	int countDown = 10;
	playerPos = { 0,0,0,0 };
	noticeStart();

	drawPlayArea();
	drawNoticePlayer();
	drawInfoNotice();

	//drawPlayer(playerWeak.getObjectP());
	drawObject(playerWeak->getObjectP(), playerPos, 50, 51, 40, 41, 2);

	*g_count_down = 2000;

	*c = ' ';
	cin.ignore();
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

			controlSignal(activities, *c, speed, *g_step);
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

		if (*pos % countDown == 0 && *isProduct == true)
		{
			drawBarrier(*isProduct);
			barriers.push_back(BARRIER);
			*pos = 1;

			if (countDown != 4) countDown--;

			(*amount)++;

			//testing event [error here]
			//fileDataE << "True" << endl;

			go_to_xy(139, 12);
			cout << *amount;
		};
		*pos = *pos + 1;

		replay:
		size_t length = barriers.size();
		if (length > 0)
		{
			for (int i = 0; i < barriers.size(); i++)
			{
				*Ba_th = i;
				BARRIER = barriers[i];
				controlBarrier();
				setColor(0, 2);
				go_to_xy(139, 13);
				cout << *impact;
				if (length == barriers.size())
				{
					barriers[i] = BARRIER;
				}
				else goto replay;

				if (*amount == 120)
				{
					*isProduct = false;
					if (!barriers.empty()) {
						*sign = true;
						break;
					};
				};

			}
		};

		if (*sign == true) {
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
			//player was showed, but its place is not right
			//fileDataP << "playerPos.prevPosX: " << playerPos.prevPosX << endl;
			//fileDataP << "playerPos.prevPosY: " << playerPos.prevPosY << endl;
			//fileDataP << "playerPos.nextPosX: " << playerPos.nextPosX << endl;
			//fileDataP << "playerPos.nextPosY: " << playerPos.nextPosY << endl;
			//fileDataP << " " << endl;

			controlWithoutEvent(activities, playerPos, *g_step);
			movePlayer(playerWeak->getObjectP());
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
	delete isProduct;

	noticeFinish();
	stringFlicker("/* Press 'r' to continue */", 0, 3, 2, 4);
};
#pragma endregion

#pragma region player
//void drawPlayer(string object) {
//	playerPos.prevPosX = random(50, 90);
//	playerPos.prevPosY = random(40, 49);
//	go_to_xy(playerPos.prevPosX,playerPos.prevPosY);
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
	if (!isPlayerHitWall() && !isPlayerImpactBarrier())
	{
		go_to_xy(playerPos.prevPosX, playerPos.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		go_to_xy(playerPos.nextPosX, playerPos.nextPosY);
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
void drawBarrier(bool& isProduct) {
	if (isProduct)
	{
		BARRIER.line = "";
		BARRIER.length = random(3, 4);
		for (int i = 0; i < BARRIER.length; i++)
		{
			BARRIER.line = BARRIER.line + 'O';
		}
		BARRIER.prevPosX = random(46, 101);
		BARRIER.prevPosY = random(6, 10);
		go_to_xy(BARRIER.prevPosX, BARRIER.prevPosY);
		setColor(0, 5);
		cout << BARRIER.line;
	}
};
void controlBarrier() {
	BARRIER.nextPosX = BARRIER.prevPosX;
	BARRIER.nextPosY = BARRIER.prevPosY + 1;
	moveBarrier();
}
void moveBarrier() {
	bool isP_Impact_B = isPlayerImpactBarrier();
	if (!isBarrierHitWall() && !isP_Impact_B)
	{
		go_to_xy(BARRIER.prevPosX, BARRIER.prevPosY);
		cout << setfill(' ');
		cout << setw(BARRIER.length) << right << ' ';

		go_to_xy(BARRIER.nextPosX, BARRIER.nextPosY);
		setColor(0, 5);
		cout << BARRIER.line;
		BARRIER.prevPosX = BARRIER.nextPosX;
		BARRIER.prevPosY = BARRIER.nextPosY;
	}
	else if (isP_Impact_B)
	{
		*impact = *impact + 1;

		cout << setfill(' ');

		go_to_xy(BARRIER.prevPosX, BARRIER.prevPosY);
		cout << setw(BARRIER.length) << right << ' ';

		go_to_xy(BARRIER.nextPosX, BARRIER.nextPosY);
		cout << setw(BARRIER.length) << right << ' ';

		barriers.erase(barriers.begin() + *Ba_th);
	}
	else {
		go_to_xy(BARRIER.prevPosX, BARRIER.prevPosY);
		cout << setfill(' ');
		cout << setw(BARRIER.length) << right << ' ';
		barriers.erase(barriers.begin() + *Ba_th);
	};
}
#pragma endregion

#pragma region checkingEvents
bool isPlayerHitWall() {
	if (playerPos.nextPosX <= 45 || playerPos.nextPosX >= 99) //left - right
	{
		if (playerPos.nextPosY >= 5 && playerPos.nextPosY <= 50)
		{
			return true;
		}
	};
	if (playerPos.nextPosX >= 45 && playerPos.nextPosX <= 99) //up - down
	{
		if (playerPos.nextPosY >= 50 || playerPos.nextPosY <= 5)
		{
			return true;
		}
	};
	return false;
}
bool isBarrierHitWall() {
	if (BARRIER.nextPosY == 49)
	{
		return true;
	};
	return false;
}
bool isPlayerImpactBarrier() {
	int endPosX_P = playerPos.nextPosX + playerWeak->getObjectP().size();
	int endPosX_B = BARRIER.nextPosX + BARRIER.length;
	if (BARRIER.nextPosX >= playerPos.nextPosX && BARRIER.nextPosX <= endPosX_P || endPosX_B >= playerPos.nextPosX && endPosX_B <= endPosX_P)
	{
		if (BARRIER.nextPosY == playerPos.nextPosY)
		{
			return true;
		}
		else if (BARRIER.nextPosY == playerPos.prevPosY)
		{
			return true;
		}
		else if (BARRIER.prevPosY == playerPos.nextPosY)
		{
			return true;
		};
	};
	return false;
};
#pragma endregion
