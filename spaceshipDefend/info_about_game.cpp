#include<iostream>
#include<conio.h>
#include<vector>

#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"effects_text.h"
#include"variable.h"
#include"struct.cpp"

using namespace std;

#pragma region functions
void effectText_word(string str, int printSpeed);
void guide();
void aboutGame(int printSpeed);
void info_about_game(int printSpeed);
void drawBorder(int posX, int posY, int height, int width, int color_code);
void printTitle(int posX, int posY, int colorCode);
#pragma endregion
void guide() {
	system("cls");
	gotoXY(25, 0);
	cout << "<<--->> T.U.R.T.O.R.I.A.L <<--->>";

	gotoXY(25, 3);
	for (int i = 1; i <= 11; i++)
	{
		gotoXY(25, 3 + i); cout << "||";
	};

	gotoXY(28, 5);
	cout << "Press WASD to control your spaceship.";
	gotoXY(28, 7);
	cout << "Press 'j' to fire the enemy.";
	gotoXY(28, 9);
	cout << "Press 'space' to stop your spaceship.";
	gotoXY(28, 11);
	cout << "Press 'p' to pause game.";
	gotoXY(28, 13);
	cout << "Press 'r' to exit game and return the menu.";
	*c = ' ';
	while (true)
	{
		if (_kbhit())
		{
			*c = _getch();
			*c = tolower(*c);
			if (*c == 'r')
			{
				break;
			}
		}
	};
}
void aboutGame(int printSpeed) {
	system("cls");
	vector<string>para1 = { "[ Ten Game: SPACESHIP_DEFENDER ]",
	"[ Tac Gia: CAO NHAT HAO ]",
	"[ Nam Du An: 2022 ]" };

	for (int i = 0; i < para1.size(); i++)
	{
		gotoXY(15, 5 + i);
		effectText_word(para1[i], printSpeed);
	}

	Sleep(1200);
	gotoXY(15, 8);

	cout << "Press 'r' to back the menu";
	*c = ' ';
	while (true)
	{
		if (_kbhit()) {
			*c = _getch();
			*c = tolower(*c);
			if (*c == 'r')
			{
				break;
			}
		}
	};
}
void drawInfo(int posX, int posY) {
	*g_choice = 0;

	gotoXY(posX + 5, posY - 3);
	cout << "Ban muon thong tin nao ?";
	gotoXY(posX, posY);
	cout << "1. Huong dan choi";
	gotoXY(posX, posY + 2);
	cout << "2. Ve tro choi";
	gotoXY(posX, posY + 4);
	cout << "Press 'r' to back the menu";

	cursorPos.prevPosX = 14;
	cursorPos.prevPosY = 7;
	gotoXY(cursorPos.prevPosX, cursorPos.prevPosY);
	setColor(0, 6);
	cout << ">>";
}
void info_about_game(int printSpeed) {
	system("cls");

	printTitle(60, 2, 3);
	drawBorder(58, 35, 15, 100, 2);
	drawInfo(70, 40);

	while (true)
	{
		if (_kbhit()) {
			*c = _getch();
			if (*c != ' ')
			{
				if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
				{
					controlCursor(cursorPos);
					moveCursor(7, 9, cursorPos);
				}
				else if (GetAsyncKeyState(VK_RETURN))
				{
					if (cursorPos.prevPosY == 7)
					{
						*g_choice = 1;
						system("cls");

					}
					else if (cursorPos.prevPosY = 9)
					{
						*g_choice = 2;
						aboutGame(printSpeed);					}
				}
				else if (*c == 'r')
				{
					break;
				}
			}
			*c = ' ';
		};
	};
}

