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
#include"Player.h"
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

void stage_chapter_2(int speed, int& g_process, int& g_contact);

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

	stringFlicker("/* Press 'r' to continue ! */",'r', 0, 3, 2, 3);

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
		atXY(45 + i, 5);//(45 -105, 5)
		cout << '-';
	};
	for (int i = 1; i <= lengthLine; i++)
	{
		atXY(45, 5 + i); cout << '|';//(45, 6 - 50)
		atXY(45 + widthLine, 5 + i); cout << '|';
	};
	for (int i = 0; i <= widthLine; i++)
	{
		atXY(45 + i, 5 + lengthLine); cout << '-';
	};
}
void drawNoticePlayer() {
	atXY(125, 5);
	setColor(0, 12);
	cout << "--- <<< [---] >>> NOTICE <<< [---] >>> ---";
	setColor(0, 6);
	for (int i = 1; i <= 12; i++)
	{
		atXY(125, 5 + i);
		cout << '|';
		atXY(167, 5 + i);
		cout << '|';
	}
	for (int i = 0; i <= 42; i++)
	{
		atXY(125 + i, 17); cout << '-';
	};
}
void drawInfoNotice() {
	setColor(0, 4);
	atXY(127, 6);
	cout << "Nhiem vu:";
	atXY(127, 7);
	setColor(0, 3);
	cout << "[ Tranh hoac ban pha cac vat can. ]";
	atXY(127, 8);
	setColor(0, 3);
	cout << "Luu y:";
	atXY(127, 9);
	setColor(0, 3);
	cout << "(toi thieu can vuot qua 120 / 120)";

	atXY(127, 12);
	setColor(0, 2);
	cout << "Tien trinh: 0";
	atXY(127, 13);
	setColor(0, 2);
	cout << "So va cham: ";

	atXY(127, 15);
	cout << "[ Press 'p' to pause ]";
}
#pragma endregion

#pragma region main
void stage_chapter_2(int speed, int& g_process, int& g_contact) {
	int countDown = 10;
	PlayerPos = { 0,0,0,0 };
	noticeStart();

	drawPlayArea();
	drawNoticePlayer();
	drawInfoNotice();

	//drawPlayer(PlayerWeak.getObjectP());
	drawObject(PlayerWeak->getObjectP(), PlayerPos, 50, 51, 40, 41, 2);

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

			atXY(139, 12);
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
				atXY(139, 13);
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
			PlayerPos.nextPosX = PlayerPos.prevPosX;
			PlayerPos.nextPosY = PlayerPos.prevPosY;
		}
		else
		{
			//Player was showed, but its place is not right
			//fileDataP << "PlayerPos.prevPosX: " << PlayerPos.prevPosX << endl;
			//fileDataP << "PlayerPos.prevPosY: " << PlayerPos.prevPosY << endl;
			//fileDataP << "PlayerPos.nextPosX: " << PlayerPos.nextPosX << endl;
			//fileDataP << "PlayerPos.nextPosY: " << PlayerPos.nextPosY << endl;
			//fileDataP << " " << endl;

			controlWithoutEvent(activities, PlayerPos, *g_step);
			movePlayer(PlayerWeak->getObjectP());
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
	g_process = *amount;
	g_contact = *impact;
	delete Ba_th;
	delete pos;
	delete amount;
	delete sign;
	delete impact;
	delete isProduct;

	noticeFinish();
	stringFlicker("/* Press 'r' to continue */",'r', 0, 3, 2, 4);
};
#pragma endregion

#pragma region Player
//void drawPlayer(string object) {
//	PlayerPos.prevPosX = random(50, 90);
//	PlayerPos.prevPosY = random(40, 49);
//	atXY(PlayerPos.prevPosX,PlayerPos.prevPosY);
//	setColor(0, 2);
//	cout << PlayerWeak.getObjectP();
//}
//void controlPlayer() {
//	if (activities == Activities::top)
//	{
//		PlayerPos.nextPosX = PlayerPos.prevPosX;
//		PlayerPos.nextPosY = PlayerPos.prevPosY - 1;
//	}
//	else if (activities == Activities::bottom)
//	{
//		PlayerPos.nextPosX = PlayerPos.prevPosX;
//		PlayerPos.nextPosY = PlayerPos.prevPosY + 1;
//	}
//	else if (activities == Activities::left)
//	{
//		PlayerPos.nextPosX = PlayerPos.prevPosX - 1;
//		PlayerPos.prevPosY = PlayerPos.prevPosY;
//	}
//	else if (activities == Activities::right)
//	{
//		PlayerPos.nextPosX = PlayerPos.prevPosX + 1;
//		PlayerPos.nextPosY = PlayerPos.prevPosY;
//	}
//	else if (activities == Activities::stop || isPlayerHitWall())
//	{
//		PlayerPos.nextPosX = PlayerPos.prevPosX;
//		PlayerPos.nextPosY = PlayerPos.prevPosY;
//	};
//}
void movePlayer(string object) {
	if (!isPlayerHitWall() && !isPlayerImpactBarrier())
	{
		atXY(PlayerPos.prevPosX, PlayerPos.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		atXY(PlayerPos.nextPosX, PlayerPos.nextPosY);
		setColor(0, 2);
		cout << object;
		PlayerPos.prevPosX = PlayerPos.nextPosX;
		PlayerPos.prevPosY = PlayerPos.nextPosY;

		//fileDataP << "PlayerWeak.prevPosX: " << PlayerPos.prevPosX << endl;
		//fileDataP << "PlayerWeak.prevPosY: " << PlayerPos.prevPosY << endl;
		//fileDataP << "PlayerWeak.nextPosX: " << PlayerPos.nextPosX << endl;
		//fileDataP << "PlayerWeak.nextPosY: " << PlayerPos.nextPosY << endl;
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
		atXY(BARRIER.prevPosX, BARRIER.prevPosY);
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
		atXY(BARRIER.prevPosX, BARRIER.prevPosY);
		cout << setfill(' ');
		cout << setw(BARRIER.length) << right << ' ';

		atXY(BARRIER.nextPosX, BARRIER.nextPosY);
		setColor(0, 5);
		cout << BARRIER.line;
		BARRIER.prevPosX = BARRIER.nextPosX;
		BARRIER.prevPosY = BARRIER.nextPosY;
	}
	else if (isP_Impact_B)
	{
		*impact = *impact + 1;

		cout << setfill(' ');

		atXY(BARRIER.prevPosX, BARRIER.prevPosY);
		cout << setw(BARRIER.length) << right << ' ';

		atXY(BARRIER.nextPosX, BARRIER.nextPosY);
		cout << setw(BARRIER.length) << right << ' ';

		barriers.erase(barriers.begin() + *Ba_th);
	}
	else {
		atXY(BARRIER.prevPosX, BARRIER.prevPosY);
		cout << setfill(' ');
		cout << setw(BARRIER.length) << right << ' ';
		barriers.erase(barriers.begin() + *Ba_th);
	};
}
#pragma endregion

#pragma region checkingEvents
bool isPlayerHitWall() {
	if (PlayerPos.nextPosX <= 45 || PlayerPos.nextPosX >= 99) //left - right
	{
		if (PlayerPos.nextPosY >= 5 && PlayerPos.nextPosY <= 50)
		{
			return true;
		}
	};
	if (PlayerPos.nextPosX >= 45 && PlayerPos.nextPosX <= 99) //up - down
	{
		if (PlayerPos.nextPosY >= 50 || PlayerPos.nextPosY <= 5)
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
	int endPosX_P = PlayerPos.nextPosX + PlayerWeak->getObjectP().size();
	int endPosX_B = BARRIER.nextPosX + BARRIER.length;
	if (BARRIER.nextPosX >= PlayerPos.nextPosX && BARRIER.nextPosX <= endPosX_P || endPosX_B >= PlayerPos.nextPosX && endPosX_B <= endPosX_P)
	{
		if (BARRIER.nextPosY == PlayerPos.nextPosY)
		{
			return true;
		}
		else if (BARRIER.nextPosY == PlayerPos.prevPosY)
		{
			return true;
		}
		else if (BARRIER.prevPosY == PlayerPos.nextPosY)
		{
			return true;
		};
	};
	return false;
};
#pragma endregion
