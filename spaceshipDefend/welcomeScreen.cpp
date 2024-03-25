#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>

#include"effects.h"
#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"struct.cpp"
#include"variable.h"

string str = "";

#pragma region functions
void screenInfo(int printSpeed, string name);
int welcomeScreen(int printSpeed, string name);
#pragma endregion

#pragma region decorationFuncs
void screenInfo(int printSpeed, string name) {
	setColor(0, 2);

	atXY(84, 6);
	setColor(0, 12);
	str = "WELCOME TO SPACESHIP DEFENDER GAME!";
	effectText_char(str, printSpeed, 84, 6);

	atXY(68, 8);
	setColor(0, 14);
	str = "[ The loai: Ban sung || Do hoa: Console || Moi Truong: Window]";
	effectText_char(str, printSpeed, 68, 8);

	drawBorder(50, 10, 15, 100, 2);

	setColor(0, 8);
	string* temp = new string("");
	uppercaseString(*temp);
	str = "Chuc ban co trai nghiem vui ve :) " + *temp;
	effectText_char(str, printSpeed, 85 - name.size(), 11);

	atXY(85, 13);
	setColor(0, 11);
	cout << "<< -==- >> MOI CHON << -==- >>";

	Sleep(500);
	atXY(88, 15);
	cout << "1. Choi ngay va luon.";

	Sleep(500);
	atXY(88, 17);
	cout << "2. Dang nhap hoac dang ky";

	Sleep(500);
	atXY(88, 19);
	cout << "3. Danh sach nguoi choi";

	Sleep(500);
	atXY(88, 21);
	cout << "4. Thong tin ve game.";

	Sleep(500);
	atXY(88, 23);
	cout << "5. Ve tac gia.";
	delete temp;
}
#pragma endregion

#pragma region mainFuncs
int welcomeScreen(int printSpeed, string name) {
	screenInfo(printSpeed, name);
	printTitle(52, 25 + 5, 2);

	cursorPos.prevPosX = 84;
	cursorPos.prevPosY = 15;

	atXY(cursorPos.prevPosX, cursorPos.prevPosY);
	setColor(0, 6);
	cout << ">>";
	cin.clear();

	while (true) {
		if (_kbhit()) {
			*c = _getch();
			if (*c != ' ') {
				if (GetAsyncKeyState(VK_UP)) {
					controlCursor(cursorPos, 1, "UP");
					moveCursor(15, 23, cursorPos);
				}
				else if (GetAsyncKeyState(VK_DOWN)) {
					controlCursor(cursorPos, 1, "DOWN");
					moveCursor(15, 23, cursorPos);
				}
				else if (GetAsyncKeyState(VK_RETURN)) {
					if (cursorPos.prevPosY == 15) {
						*g_choice = 1;
						break;
					}
					else if (cursorPos.prevPosY == 17) {
						*g_choice = 2;
						break;
					}
					else if (cursorPos.prevPosY == 19) {
						*g_choice = 3;
						break;
					}
					else if (cursorPos.prevPosY == 21) {
						*g_choice = 4;
						break;
					}
					else if (cursorPos.prevPosY == 23) {
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