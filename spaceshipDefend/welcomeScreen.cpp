#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<WinUser.h>

#include"effects.h"
#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"struct.cpp"
#include"variable.h"

string str = "";


#pragma region functions
void effectText_char(string str, int printSpeed);
void drawBorder(int posX, int posY, int height, int width, int color_code);
void printTitle(int posX, int posY, int color_code);
void screenInfo(int printSpeed, string name);
int welcomeScreen(int printSpeed, string name);
#pragma endregion

#pragma region decorationFuncs
void screenInfo(int printSpeed, string name) {
	setColor(0, 2);

	atXY(84, 2 + *addPosY);
	setColor(0, 12);
	str = "WELCOME TO SPACESHIP DEFENDER GAME!";
	effectText_char(str, printSpeed);

	atXY(68, 3 + *addPosY);
	setColor(0, 14);
	str = "[ The loai: Ban sung || Do hoa: Console || Moi Truong: Window]";
	effectText_char(str, printSpeed);

	drawBorder(50, 5 + *addPosY, 15, 100, 2);

	atXY(85 - name.size(), 6 + *addPosY);
	setColor(0, 8);
	string* temp = new string("");
	uppercaseString(*temp);
	str = "Chuc ban co trai nghiem vui ve :) " + *temp;
	effectText_char(str, printSpeed);

	atXY(85, 8 + *addPosY);
	setColor(0, 11);
	cout << "<< -==- >> MOI CHON << -==- >>";

	Sleep(500);
	atXY(88, 10 + *addPosY);
	cout << "1. Choi ngay va luon.";

	Sleep(500);
	atXY(88, 12 + *addPosY);
	cout << "2. Dang nhap hoac dang ky";

	Sleep(500);
	atXY(88, 14 + *addPosY);
	cout << "3. Danh sach nguoi choi";

	Sleep(500);
	atXY(88, 16 + *addPosY);
	cout << "4. Thong tin ve game.";

	Sleep(500);
	atXY(88, 18 + *addPosY);
	cout << "5. Ve tac gia.";
	delete temp;
}
#pragma endregion

#pragma region mainFuncs
int welcomeScreen(int printSpeed, string name) {
	screenInfo(printSpeed, name);
	printTitle(52, 25 + *addPosY, 2);

	cursorPos.prevPosX = 84;
	cursorPos.prevPosY = 10 + *addPosY;

	atXY(cursorPos.prevPosX, cursorPos.prevPosY);
	setColor(0, 6);
	cout << ">>";
	cin.clear();

	while (true) {
		if (_kbhit()) {
			*c = _getch();
			if (*c != ' ') {
				if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN)) {
					controlCursor(cursorPos);
					moveCursor(10 + *addPosY, 18 + *addPosY, cursorPos);
				}
				else if (GetAsyncKeyState(VK_RETURN)) {
					if (cursorPos.prevPosY == 10 + *addPosY) {
						*g_choice = 1;
						break;
					}
					else if (cursorPos.prevPosY == 12 + *addPosY) {
						*g_choice = 2;
						break;
					}
					else if (cursorPos.prevPosY == 14 + *addPosY) {
						*g_choice = 3;
						break;
					}
					else if (cursorPos.prevPosY == 16 + *addPosY) {
						*g_choice = 4;
						break;
					}
					else if (cursorPos.prevPosY == 18 + *addPosY) {
						*g_choice = 5;
						break;
					};
				};
			}
			*c = ' ';
		};
	}
	int ans = *g_choice;
	return ans;
};
#pragma endregion