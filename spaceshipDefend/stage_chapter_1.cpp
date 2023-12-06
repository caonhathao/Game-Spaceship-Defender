#include<iostream>
#include<conio.h>
#include<time.h>
#include<iomanip>
#include<cstring>
#include<string>

#include"struct.cpp"
#include"Activities.cpp"

#include"functions_control_console.h"
#include"functions_control_object.h"
#include"effects_text.h"
#include"Player.h"
#include"variable.h"

using namespace std;

struct Position;

#pragma region generalVariableAndSetting
int *info_sign = new int(0);
int *task_completed = new int(0);
int* task_point = new int(0);
int *powerAdd = new int(0);
int *powerCurrent = new int(0);

#pragma endregion

#pragma region functions
void noticePlayer(int widthLine);
void airPort(int lengthLine, int widthLine);
void stage_chapter_1(int speed, int& res);

void control();
void move(string object);

void drawInfoBoard(int widthLine);
void drawTaskBoard();
void task();

bool isPlayerTouchWall();
bool isPlayerTouchGarage();
bool isPlayerTouchTask();

int random(int minN, int maxN);
#pragma endregion

#pragma region funcsDecoration
void noticePlayer(int widthLine) {
	//notice
	//int lengthLine = 45;
	//int widthLine = 20;
	setColor(0, 7);
	for (int i = 1; i <= 5; i++)
	{
		atXY(widthLine * 2 + 5 + 15 + 15, 10 + i);
		cout << '|';
	};
	for (int i = 0; i <= 16; i++)
	{
		atXY(widthLine * 2 + 5 + 15 + 15 + i, 10);
		cout << '-';
	};
	for (int i = 1; i <= 5; i++)
	{
		atXY(widthLine * 2 + 5 + 15 + 31, 10 + i);
		cout << '|';
	};
	for (int i = 0; i <= 16; i++)
	{
		atXY(widthLine * 2 + 5 + 15 + 15 + i, 16);
		cout << '-';
	};

	setColor(0, 3);
	atXY(widthLine * 2 + 5 + 15 + 15 + 1, 10 + 1);
	cout << "25/08/2506";
	atXY(widthLine * 2 + 5 + 15 + 15 + 1, 10 + 3);
	cout << "VN - 34U25 - 8A";
	atXY(widthLine * 2 + 5 + 15 + 15 + 1, 10 + 5);
	cout << "CRF - 8U";
}
void airPort(int lengthLine, int widthLine) {
	//line1
	setColor(0, 6);
	for (int i = 6; i < widthLine + 5; i++)
	{
		atXY(i, 0);
		if (i % 2 == 0)
		{
			cout << 1;
		};
	}
	for (int i = 0; i < lengthLine - 5; i++)
	{
		atXY(5, i); //5,39
		cout << '|';
	}
	for (int i = 0; i < lengthLine - 5; i++)
	{
		atXY(widthLine + 5, i); //25,39
		cout << '|';
	}

	setColor(0, 4);
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			atXY(widthLine + 5 + 1, 25 + i); //widthLine=20
			cout << "==============";
		}
	};

	//line2
	setColor(0, 6);
	for (int i = widthLine + 5 + 15 + 1; i < widthLine * 2 + 5 + 15; i++)
	{
		atXY(i, 0);
		if (i % 2 == 0) {
			cout << 2;
		};
	}
	for (int i = 0; i < lengthLine - 5; i++) //lengthLine=40
	{
		atXY(widthLine + 5 + 15, i);
		cout << '|';
	}
	for (int i = 0; i < lengthLine - 5; i++)
	{
		atXY(widthLine * 2 + 5 + 15, i);
		cout << '|';
	}

	//garage
	setColor(0, 2);
	for (int i = 2; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			atXY(widthLine * 2 + 5 + 15 + 15, 25 + i); //75,25+i
			cout << "[-----=====-----]";
		};
	}

}
void drawInfoBoard(int widthLine) {
	//area: 36x25
	//posX: 96
	//posY: 10
	setColor(0, 2);
	for (int i = 0; i <= 35; i++)
	{
		atXY(widthLine * 2 + 5 + 15 + 15 + 16 + 5 + i, 10);
		cout << '-';
	}
	for (int i = 1; i <= 25; i++)
	{
		atXY(widthLine * 2 + 5 + 15 + 31 + 5, 10 + i);
		cout << '|';
	}
	for (int i = 1; i <= 25; i++)
	{
		atXY(widthLine * 2 + 5 + 15 + 31 + 5 + 35, 10 + i);
		cout << '|';
	}
	for (int i = 0; i <= 35; i++)
	{
		atXY(widthLine * 2 + 5 + 15 + 15 + 16 + 5 + i, 35);
		cout << '-';
	}

	setColor(0, 1);
	atXY(97, 11);
	cout << "Thong so ki thuat VN - 34U25 - 8A:";
	atXY(97, 13);
	cout << "> Sai canh: 56,39 m";
	atXY(97, 15);
	cout << "> Dai: 40,05 m";
	atXY(97, 17);
	cout << "> Rong: 34,05 m ";
	atXY(97, 19);
	cout << "> Cao: 13,5 m";
	atXY(97, 21);
	cout << "> So kip lai: 4 nguoi";
	atXY(97, 23);
	cout << "> So dong co: 8 dong co DK-2";
	atXY(97, 25);
	cout << "> Khoi luong bay toi da: 221,35t";
	atXY(97, 27);
	cout << "> Tam hoat dong: 4 thang";
	atXY(97, 27);
	cout << "> Nang luong hien tai: ";

	int* powerNow = new int(0);
	*powerNow = *powerAdd + *powerCurrent;
	if (*powerNow < 10)
	{
		cout << '0' << *powerNow << '%';
	}
	else cout << *powerNow << '%';
	delete powerNow;

	atXY(97, 29);
	cout << "> Vu khi: phao Lazer 40 mm";
	/*
	atXY(97, 31); //tinh nang chua phat trien
	cout << "> Vu khi: 4x6 ten lua SDK - 2U";
	*/
}
void drawTaskBoard() {
	//size: 40*25
	setColor(0, 7);
	for (int i = 0; i <= 40 ; i++)
	{
		atXY(136 + i, 10); cout << '-';
	}
	for (int i = 1; i <= 25 ; i++)
	{
		atXY(136, 10 + i); cout << '|';
	}
	for (int i = 1; i <= 25; i++)
	{
		atXY(136 + 40, 10 + i); cout << '|';
	}
	for (int i = 0; i <= 40; i++)
	{
		atXY(136 + i, 35);
		cout << '-';
	}
}
#pragma endregion

#pragma region main
void stage_chapter_1(int speed, int& res) {
	system("cls");
	airPort(45, 20);
	noticePlayer(20);
	drawTaskBoard();

	drawObject(PlayerWeak->getObjectP(), PlayerPos, 75, 75, 45, 45, 2);
	*powerCurrent = random(0, 35);

	while (true)
	{
		if (_kbhit())
		{
			*c = _getch();
			*c = tolower(*c);
			controlSignal(activities, *c, speed, *g_step);
		};
		if (*c == 'p')
		{
			while (*c == 'p')
			{
				if (_kbhit()) {
					*c = _getch();
					*c = tolower(*c);
				}
			};
		};
		if (*info_sign == 1)
		{
			drawInfoBoard(20);
		}
		if (PlayerPos.prevPosY == 5)
		{
			if (*task_completed >= 4)
			{
				system("cls");
				string para = "[ The Spaceship took off successful. ]";
				effectText_char(para, 20);
				cout << endl;
				cout << "You completed " << *task_point << " task(s)." << endl;
				cout << endl;

				stringFlicker("[ Press 'r' to continue ]", 0, 5, 2, 3);
				atXY(0, 5);
				break;
			};
		};
		control();
		Sleep(speed);
	}
	res = *task_point;
}
#pragma endregion

#pragma region control
void control() {
	if (activities == Activities::top)
	{
		PlayerPos.nextPosX = PlayerPos.prevPosX;
		PlayerPos.nextPosY = PlayerPos.prevPosY - 1;
	}
	else if (activities == Activities::bottom)
	{
		PlayerPos.nextPosX = PlayerPos.prevPosX;
		PlayerPos.nextPosY = PlayerPos.prevPosY + 1;
	}
	else if (activities == Activities::left)
	{
		PlayerPos.nextPosX = PlayerPos.prevPosX - 1;
		PlayerPos.nextPosY = PlayerPos.prevPosY;
	}
	else if (activities == Activities::right)
	{
		PlayerPos.nextPosX = PlayerPos.prevPosX + 1;
		PlayerPos.nextPosY = PlayerPos.prevPosY;
	}
	else if (activities == Activities::stop)
	{
		PlayerPos.nextPosX = PlayerPos.prevPosX;
		PlayerPos.nextPosY = PlayerPos.prevPosY;
	}

	if (isPlayerTouchWall())
	{
		PlayerPos.nextPosX = PlayerPos.prevPosX;
		PlayerPos.nextPosY = PlayerPos.prevPosY;
	}
	else if (*info_sign == 0) // first touch to the garbage
	{
		if (isPlayerTouchGarage())
		{
			*info_sign = 1;//save the first touch signal
			(*task_point)++;
			PlayerPos.nextPosX = PlayerPos.prevPosX;
			PlayerPos.nextPosY = PlayerPos.prevPosY;
		}
	}
	else if (isPlayerTouchGarage())
	{
		*info_sign = -1;
		PlayerPos.nextPosX = PlayerPos.prevPosX;
		PlayerPos.nextPosY = PlayerPos.prevPosY;
	};
	move(PlayerWeak->getObjectP());
}
void move(string object) {
	if (!isPlayerTouchTask() && !isPlayerTouchGarage())
	{
		atXY(PlayerPos.prevPosX, PlayerPos.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		atXY(PlayerPos.nextPosX, PlayerPos.nextPosY);
		PlayerPos.prevPosX = PlayerPos.nextPosX;
		PlayerPos.prevPosY = PlayerPos.nextPosY;
		setColor(0, 2);
		cout << object;
	}
	else
	{
		task();
		atXY(PlayerPos.prevPosX, PlayerPos.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		atXY(PlayerPos.nextPosX, PlayerPos.nextPosY);
		PlayerPos.prevPosX = PlayerPos.nextPosX;
		PlayerPos.prevPosY = PlayerPos.nextPosY;
		cout << object;
	}

};
#pragma endregion

void task() {
	/*
	* we have 4 tasks in this:
	*	get type of canon (install)
	*	get type of engine (install)
	*	get amount of engine
	*	get power
	* two variables:
	*	task_point: will be recieved if set up success
	*	task_completed: will increated with every task (4 task -> task_completed = 4)
	*/
	string str;
	if (PlayerPos.prevPosY == 35)
	{
		atXY(137, 11);
		cout << "Yeu cau lap phao co nong:";
		atXY(137, 12);
		cin.ignore();
		getline(cin, str);
		if (str == "Lazer 40 mm" || str == "40 mm" || str == "lazer 40mm" || str == "40mm")
		{
			atXY(148, 12);
			cout << " - DA LAP!";
			(*task_point)++;
			(*task_completed)++; 
		}
		else {
			atXY(148, 12);
			cout << " - KHONG THE LAP!";
			(*task_completed)++;
		}
	};
	if (PlayerPos.prevPosY == 33)
	{
		atXY(137, 14);
		cout << "Yeu cau dong co:";
		atXY(137, 15);
		getline(cin, str);
		if (str == "DK-2" || str == "DK - 2" || str == "dk-2" || str == "dk - 2")
		{
			atXY(148, 15);
			cout << " - XAC NHAN!";
			(*task_point)++;
			(*task_completed)++;
		}
		else
		{
			atXY(148, 15);
			cout << " - KHONG PHU HOP!";
			(*task_completed)++;
		}
	};
	if (PlayerPos.prevPosY == 31)
	{
		atXY(137, 17);
		cout << "Yeu cau so dong co:";
		atXY(137, 18);
		getline(cin, str);
		if (str == "8")
		{
			atXY(148, 18);
			cout << " - DA LAP!";
			(*task_point)++;
			(*task_completed)++;
		}
		else
		{
			atXY(148, 18);
			cout << " - KHONG THE LAP";
			(*task_completed)++;
		}
	};
	if (PlayerPos.prevPosY == 29)
	{
		atXY(137, 20);
		cout << "Muc nang luong can nap:";
		atXY(137, 21);
		getline(cin, str);
		*powerAdd = stoi(str);
		atXY(148, 21);
		cout << "HOAN THANH ! CAT CANH !";
		drawInfoBoard(20);
		(*task_point)++;
		(*task_completed)++;
	};
}

#pragma region checkEvents
bool isPlayerTouchGarage() {
	if (PlayerPos.nextPosX >= 70 && PlayerPos.nextPosX <= 99)
	{
		if ( PlayerPos.nextPosY == 35)
		{
			return true;
		}
	}return false;
};
bool isPlayerTouchWall() {
	if (PlayerPos.nextPosX <= 0)
	{
		return true;
	}
	else if (PlayerPos.nextPosY <= 1)
	{
		return true;
	};
	//for line 1
	if ((PlayerPos.nextPosX >= 0 && PlayerPos.nextPosX <= 5) || (PlayerPos.nextPosX >= 21 && PlayerPos.nextPosX <= 25))
	{
		if (PlayerPos.nextPosY == 39)
		{
			return true;
		}
	}
	if (PlayerPos.nextPosX == 5 || PlayerPos.nextPosX == 21 || PlayerPos.nextPosX == 25)
	{
		if (PlayerPos.nextPosY <= 39)
		{
			return true;
		}
	};

	//for line 2
	if ((PlayerPos.nextPosX >= 36 && PlayerPos.nextPosX <= 40) || (PlayerPos.nextPosX >= 56 && PlayerPos.nextPosX <= 60))
	{
		if (PlayerPos.nextPosY == 39)
		{
			return true;
		}
	};
	if (PlayerPos.nextPosX == 36 || PlayerPos.nextPosX == 40 || PlayerPos.nextPosX == 56 || PlayerPos.nextPosX == 60)
	{
		if (PlayerPos.nextPosY <= 39)
		{
			return true;
		}
	};
	return false;
}
bool isPlayerTouchTask() {
	if (PlayerPos.prevPosX >= 40 && PlayerPos.prevPosX <= 56)
	{
		if (PlayerPos.prevPosY == 35)
		{
			return true;
		}
		else if (PlayerPos.prevPosY == 33)
		{
			return true;
		}
		else if (PlayerPos.prevPosY == 31)
		{
			return true;
		}
		else if (PlayerPos.prevPosY == 29)
		{
			return true;
		}
		else if (PlayerPos.prevPosY == 27)
		{
			return true;
		}
	};
	return false;
};
#pragma endregion