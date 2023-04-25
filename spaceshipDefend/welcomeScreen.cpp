#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<WinUser.h>

#include"effects_text.h"
#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"struct.cpp"
#include"variable.h"

string str = "";

#pragma region functions
void effectText_char(string str, int printSpeed);

void drawScreen();
void screenInfo(int printSpeed, string name);
int welcomeScreen(int printSpeed, string name);

#pragma endregion

#pragma region decorationFuncs
void drawScreen() {
	setColor(0, 2);
	for (SHORT i = 0; i < 100; i++)
	{
		gotoXY(56 + i, 5);
		cout << '-';
	}
	for (SHORT i = 1; i <= 15; i++)
	{
		gotoXY(56, 5 + i);
		cout << '|';
	}
	for (SHORT i = 0; i < 100; i++)
	{
		gotoXY(56 + i, 20);
		cout << '-';
	}
	for (SHORT i = 1; i < 15; i++)
	{
		gotoXY(155, 5 + i);
		cout << '|';
	}
};
void screenInfo(int printSpeed, string name) {
	setColor(0, 2);

	gotoXY(90, 2);
	setColor(0, 12);
	str = "WELCOME TO SPACESHIP_DEFENDER GAME!";
	effectText_char(str, printSpeed);

	gotoXY(55, 3);
	setColor(0, 14);
	str = "[ NOTE: Game nay duoc lam ra chi co muc dich duy nhat la vui ve ma thoi, ngoai ra thi cha co gi khac! ]";
	effectText_char(str, printSpeed);

	drawScreen();

	gotoXY(90 - name.size(), 6);
	setColor(0, 8);
	string* temp = new string("");
	*temp = uppercaseLetter(name);
	str = "Chuc ban co trai nghiem vui ve :) " + *temp;
	effectText_char(str, printSpeed);

	gotoXY(94, 8); 
	setColor(0, 11);
	cout << "< --- > MOI CHON < --- >";

	Sleep(500);
	gotoXY(95, 10);
	cout << "1. Choi ngay va luon.";

	Sleep(500);
	gotoXY(95, 12);
	cout << "2. Dang nhap hoac dang ky";

	Sleep(500);
	gotoXY(95, 14);
	cout << "3. Danh sach nguoi choi";

	Sleep(500);
	gotoXY(95, 16);
	cout << "4. Thong tin ve game.";

	Sleep(500);
	gotoXY(95, 18);
	cout << "5. About me?";
	delete temp;
}
#pragma endregion

#pragma region mainFuncs
int welcomeScreen(int printSpeed,string name) {
	screenInfo(printSpeed, name);

	cursorPos.prevPosX = 92;
	cursorPos.prevPosY = 10;

	gotoXY(cursorPos.prevPosX, cursorPos.prevPosY);
	setColor(0, 6);
	cout << ">>";

	while (true){		
		if (_kbhit())
		{
			*c = _getch();
			if (*c != ' ')
			{
				if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
				{
					controlCursor(cursorPos);
					moveCursor(10, 18, cursorPos);
				}
				else if (GetAsyncKeyState(VK_RETURN))
				{
					if (cursorPos.prevPosY == 10)
					{
						*choice = 1;
						break;
					}
					else if (cursorPos.prevPosY == 12)
					{
						*choice = 2;
						break;
					}
					else if (cursorPos.prevPosY == 14)
					{
						*choice = 3;
						break;
					}
					else if (cursorPos.prevPosY == 16)
					{
						*choice = 4;
						break;
					}
					else if (cursorPos.prevPosY == 18)
					{
						*choice = 5;
						break;
					};
				};
			}
			*c = ' ';
		};
	}
	int ans = *choice;
	return ans;
};
#pragma endregion

/*
* #pragma region controlCursorFuncs
void controlCursor() {
	if (GetAsyncKeyState(VK_UP))
	{
		cursorPos.nextPosX = cursorPos.prevPosX;
		cursorPos.nextPosY = cursorPos.prevPosY - 1;
	}
	else if (GetAsyncKeyState(VK_DOWN)){

		cursorPos.nextPosX = cursorPos.prevPosX;
		cursorPos.nextPosY = cursorPos.prevPosY + 1;
	}
	moveCursor();
}
void moveCursor() {
	if (!isCursorTouchLimit())
	{
		gotoXY(cursorPos.prevPosX, cursorPos.prevPosY);
		cout << "  ";
		gotoXY(cursorPos.nextPosX, cursorPos.nextPosY);
		setColor(0, 6);
		cout << ">>";

		cursorPos.prevPosX = cursorPos.nextPosX;
		cursorPos.prevPosY = cursorPos.nextPosY;
	}
	else
	{
		setColor(0, 6);
		cursorPos.nextPosX = cursorPos.prevPosX;
		cursorPos.nextPosY = cursorPos.prevPosY;
	}
}
bool isCursorTouchLimit() {
	if (cursorPos.nextPosY < 10 || cursorPos.nextPosY > 18)
	{
		return true;
	}; return false;
};
#pragma endregion
*/
//int main() {
//	loginScreen(20);
//	return 0;
//}