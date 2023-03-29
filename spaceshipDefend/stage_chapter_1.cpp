#include<iostream>
#include<conio.h>
#include<time.h>
#include<iomanip>
#include<cstring>
#include<string>

#include"struct.cpp"
#include"Activities.cpp"

#include"functions_control_console.h"
#include"effects_text.h"
#include"Player.h"
#include"variable.h"

using namespace std;

struct Position;

#pragma region generalVariable
int info_sign = 0;
int task_completed = 0;
int power = 0;
int r = 0;

Activities ac = Activities::stop;

PLAYER P(5, 100, ".-A-.", '.');

Position p;
#pragma endregion

#pragma region functions
void noticePlayer(int widthLine);
void airPort(int lengthLine, int widthLine);
void stage_chapter_1(int speed);

void draw(string object);
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
		gotoXY(widthLine * 2 + 5 + 15 + 15, 10 + i);
		cout << '|';
	};
	for (size_t i = 0; i <= 16; i++)
	{
		gotoXY(widthLine * 2 + 5 + 15 + 15 + i, 10);
		cout << '-';
	};
	for (int i = 1; i <= 5; i++)
	{
		gotoXY(widthLine * 2 + 5 + 15 + 31, 10 + i);
		cout << '|';
	};
	for (size_t i = 0; i <= 16; i++)
	{
		gotoXY(widthLine * 2 + 5 + 15 + 15 + i, 16);
		cout << '-';
	};

	setColor(0, 3);
	gotoXY(widthLine * 2 + 5 + 15 + 15 + 1, 10 + 1);
	cout << "25/08/2506";
	gotoXY(widthLine * 2 + 5 + 15 + 15 + 1, 10 + 3);
	cout << "VN - 34U25 - 8A";
	gotoXY(widthLine * 2 + 5 + 15 + 15 + 1, 10 + 5);
	cout << "CRF - 8U";
}
void airPort(int lengthLine, int widthLine) {
	//line1
	setColor(0, 6);
	for (int i = 6; i < widthLine + 5; i++)
	{
		gotoXY(i, 0);
		if (i % 2 == 0)
		{
			cout << 1;
		};
	}
	for (int i = 0; i < lengthLine - 5; i++)
	{
		gotoXY(5, i); //5,39
		cout << '|';
	}
	for (int i = 0; i < lengthLine - 5; i++)
	{
		gotoXY(widthLine + 5, i); //25,39
		cout << '|';
	}

	setColor(0, 4);
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			gotoXY(widthLine + 5 + 1, 25 + i); //widthLine=20
			cout << "==============";
		}
	};

	//line2
	setColor(0, 6);
	for (int i = widthLine + 5 + 15 + 1; i < widthLine * 2 + 5 + 15; i++)
	{
		gotoXY(i, 0);
		if (i % 2 == 0) {
			cout << 2;
		};
	}
	for (int i = 0; i < lengthLine - 5; i++) //lengthLine=40
	{
		gotoXY(widthLine + 5 + 15, i);
		cout << '|';
	}
	for (int i = 0; i < lengthLine - 5; i++)
	{
		gotoXY(widthLine * 2 + 5 + 15, i);
		cout << '|';
	}

	//garage
	setColor(0, 2);
	for (int i = 2; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			gotoXY(widthLine * 2 + 5 + 15 + 15, 25 + i); //75,25+i
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
		gotoXY(widthLine * 2 + 5 + 15 + 15 + 16 + 5 + i, 10);
		cout << '-';
	}
	for (int i = 1; i <= 25; i++)
	{
		gotoXY(widthLine * 2 + 5 + 15 + 31 + 5, 10 + i);
		cout << '|';
	}
	for (int i = 1; i <= 25; i++)
	{
		gotoXY(widthLine * 2 + 5 + 15 + 31 + 5 + 35, 10 + i);
		cout << '|';
	}
	for (int i = 0; i <= 35; i++)
	{
		gotoXY(widthLine * 2 + 5 + 15 + 15 + 16 + 5 + i, 35);
		cout << '-';
	}

	setColor(0, 1);
	gotoXY(97, 11);
	cout << "Thong so ki thuat VN - 34U25 - 8A:";
	gotoXY(97, 13);
	cout << "> Sai canh: 56,39 m";
	gotoXY(97, 15);
	cout << "> Dai: 40,05 m";
	gotoXY(97, 17);
	cout << "> Rong: 34,05 m ";
	gotoXY(97, 19);
	cout << "> Cao: 13,5 m";
	gotoXY(97, 21);
	cout << "> So kip lai: 4 nguoi";
	gotoXY(97, 23);
	cout << "> So dong co: 8 dong co DK-2";
	gotoXY(97, 25);
	cout << "> Khoi luong bay toi da: 221,35t";
	gotoXY(97, 27);
	cout << "> Tam hoat dong: 4 thang";
	gotoXY(97, 27);
	cout << "> Nang luong hien tai: ";
	power = power + r;
	if (power < 10)
	{
		cout << '0' + r << '%';
	}
	else cout << power << '%';
	gotoXY(97, 29);
	cout << "> Vu khi: phao Lazer 40 mm";
	/*
	gotoXY(97, 31); //tinh nang chua phat trien
	cout << "> Vu khi: 4x6 ten lua SDK - 2U";
	*/
}
void drawTaskBoard() {
	//size: 40*25
	setColor(0, 7);
	for (int i = 0; i <= 40 ; i++)
	{
		gotoXY(136 + i, 10); cout << '-';
	}
	for (int i = 1; i <= 25 ; i++)
	{
		gotoXY(136, 10 + i); cout << '|';
	}
	for (int i = 1; i <= 25; i++)
	{
		gotoXY(136 + 40, 10 + i); cout << '|';
	}
	for (int i = 0; i <= 40; i++)
	{
		gotoXY(136 + i, 35);
		cout << '-';
	}
}
#pragma endregion

void stage_chapter_1(int speed) {
	system("cls");
	airPort(45, 20);
	noticePlayer(20);
	drawTaskBoard();
	draw(P.getObjectP());

	while (true)
	{
		if (_kbhit())
		{
			c = _getch();
			c = tolower(c);
			if (c == 'w')
			{
				ac = Activities::top;
			}
			else if (c == 's')
			{
				ac = Activities::bottom;
			}
			else if (c == 'd') {
				ac = Activities::right;
			}
			else if (c == 'a')
			{
				ac = Activities::left;
			}
			else if (c == ' ') {
				ac = Activities::stop;
			}
		}
		if (c == 'p')
		{
			while (c == 'p')
			{
				if (_kbhit()) {
					c = _getch();
					c = tolower(c);
				}
			};
		};
		if (info_sign == 1)
		{
			drawInfoBoard(20);
		}
		if (p.prevPosY == 5)
		{
			if (task_completed >= 4)
			{
				system("cls");
				string para = "[ The Spaceship took off successful. ]";
				effectText_char(para, 20);
				cout << endl;
				cout << "You completed " << task_point << " task(s)." << endl;
				cout << endl;
				gotoXY(0, 5);

				cout << "[ Press 'r' to continue ! ]";
				c = ' ';
				while (c != 'r')
				{
					if (_kbhit()) {
						c = _getch();
						c = tolower(c);
					}
				};
				break;
			};
		};
		control();
		Sleep(speed);
	}
	system("cls");
	cout << "Waiting for next chapter...";
	Sleep(1500);
}

#pragma region control
void draw(string object) {
	p.prevPosX = 75;
	p.prevPosY = 45;
	gotoXY(p.prevPosX, p.prevPosY);
	setColor(0, 2);
	cout << object;
}
void control() {
	if (ac == Activities::top)
	{
		p.nextPosX = p.prevPosX;
		p.nextPosY = p.prevPosY - 1;
	}
	else if (ac == Activities::bottom)
	{
		p.nextPosX = p.prevPosX;
		p.nextPosY = p.prevPosY + 1;
	}
	else if (ac == Activities::left)
	{
		p.nextPosX = p.prevPosX - 1;
		p.nextPosY = p.prevPosY;
	}
	else if (ac == Activities::right)
	{
		p.nextPosX = p.prevPosX + 1;
		p.nextPosY = p.prevPosY;
	}
	else if (ac == Activities::stop)
	{
		p.nextPosX = p.prevPosX;
		p.nextPosY = p.prevPosY;
	}

	if (isPlayerTouchWall())
	{
		p.nextPosX = p.prevPosX;
		p.nextPosY = p.prevPosY;
	}
	else if (info_sign == 0)
	{
		if (isPlayerTouchGarage())
		{
			info_sign = 1;
			p.nextPosX = p.prevPosX;
			p.nextPosY = p.prevPosY;
		}
	}
	else if (isPlayerTouchGarage())
	{
		info_sign = -1;
		p.nextPosX = p.prevPosX;
		p.nextPosY = p.prevPosY;
	};
	move(P.getObjectP());
}
void move(string object) {
	if (!isPlayerTouchTask() && !isPlayerTouchGarage())
	{
		gotoXY(p.prevPosX, p.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		gotoXY(p.nextPosX, p.nextPosY);
		p.prevPosX = p.nextPosX;
		p.prevPosY = p.nextPosY;
		setColor(0, 2);
		cout << object;
	}
	else
	{
		task();
		gotoXY(p.prevPosX, p.prevPosY);
		cout << setfill(' ');
		cout << setw(object.size()) << right << ' ';
		gotoXY(p.nextPosX, p.nextPosY);
		p.prevPosX = p.nextPosX;
		p.prevPosY = p.nextPosY;
		cout << object;
	}

};
#pragma endregion

void task() {
	//fill the fuel tank
	string str;
	if (p.prevPosY == 35)
	{
		gotoXY(137, 11);
		cout << "Yeu cau lap phao co nong:";
		gotoXY(137, 12);
		cin.ignore();
		getline(cin, str);
		if (str == "Lazer 40 mm" || str == "40 mm" || str == "lazer 40mm" || str == "40mm")
		{
			gotoXY(148, 12);
			cout << " - DA LAP!";
			task_point = task_point + 1;
			task_completed = task_completed + 1;
		}
		else {
			gotoXY(148, 12);
			cout << " - KHONG THE LAP!";
			task_completed = task_completed + 1;
		}
	};
	if (p.prevPosY == 33)
	{
		gotoXY(137, 14);
		cout << "Yeu cau dong co:";
		gotoXY(137, 15);
		getline(cin, str);
		if (str == "DK-2" || str == "DK - 2" || str == "dk-2" || str == "dk - 2")
		{
			gotoXY(148, 15);
			cout << " - XAC NHAN!";
			task_point = task_point + 1;
			task_completed = task_completed + 1;
		}
		else
		{
			gotoXY(148, 15);
			cout << " - KHONG PHU HOP!";
			task_completed = task_completed + 1;
		}
	};
	if (p.prevPosY == 31)
	{
		gotoXY(137, 17);
		cout << "Yeu cau so dong co:";
		gotoXY(137, 18);
		getline(cin, str);
		if (str == "8")
		{
			gotoXY(148, 18);
			cout << " - DA LAP!";
			task_point = task_point + 1;
			task_completed = task_completed + 1;
		}
		else
		{
			gotoXY(148, 18);
			cout << " - KHONG THE LAP";
			task_completed = task_completed + 1;
		}
	};
	if (p.prevPosY == 29)
	{
		gotoXY(137, 20);
		cout << "Muc nang luong can nap:";
		gotoXY(137, 21);
		getline(cin, str);
		power = stoi(str);
		gotoXY(148, 21);
		cout << "HOAN THANH ! CAT CANH !";
		r = random(0, 35);
		drawInfoBoard(20);
		task_completed = task_completed + 1;
	};
}

#pragma region checkEvents
bool isPlayerTouchGarage() {
	if (p.nextPosX >= 70 && p.nextPosX <= 99)
	{
		if ( p.nextPosY == 35)
		{
			return true;
		}
	}return false;
};
bool isPlayerTouchWall() {
	if (p.nextPosX <= 0)
	{
		return true;
	}
	else if (p.nextPosY <= 1)
	{
		return true;
	};
	//for line 1
	if ((p.nextPosX >= 0 && p.nextPosX <= 5) || (p.nextPosX >= 21 && p.nextPosX <= 25))
	{
		if (p.nextPosY == 39)
		{
			return true;
		}
	}
	if (p.nextPosX == 5 || p.nextPosX == 21 || p.nextPosX == 25)
	{
		if (p.nextPosY <= 39)
		{
			return true;
		}
	};

	//for line 2
	if ((p.nextPosX >= 36 && p.nextPosX <= 40) || (p.nextPosX >= 56 && p.nextPosX <= 60))
	{
		if (p.nextPosY == 39)
		{
			return true;
		}
	};
	if (p.nextPosX == 36 || p.nextPosX == 40 || p.nextPosX == 56 || p.nextPosX == 60)
	{
		if (p.nextPosY <= 39)
		{
			return true;
		}
	};
	return false;
}
bool isPlayerTouchTask() {
	if (p.prevPosX >= 40 && p.prevPosX <= 56)
	{
		if (p.prevPosY == 35)
		{
			return true;
		}
		else if (p.prevPosY == 33)
		{
			return true;
		}
		else if (p.prevPosY == 31)
		{
			return true;
		}
		else if (p.prevPosY == 29)
		{
			return true;
		}
		else if (p.prevPosY == 27)
		{
			return true;
		}
	};
	return false;
};
#pragma endregion
//int main() {
//	showCursor(false);
//	stage_chapter_1(200);
//	return 0;
//}