#include<iostream>
#include<conio.h>
#include<vector>
#include<thread>

#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"effects.h"
#include"variable.h"
#include"struct.cpp"

#pragma region functions
void guide();
void info_about_game(int printSpeed);
void drawBorder(int posX, int posY, int height, int width, int color_code);
void printTitle(int posX, int posY, int colorCode);
void stringFlicker(string str, char k, int posX, int posY, int colorCode_1, int colorCode_2);
#pragma endregion

void guide() {
	*addPosY = 5;
	system("cls");
	printTitle(60, 2 + *addPosY, 3);

	int temp = 7 + *addPosY + 2;
	drawBorder(60, temp, 15, 100, 4);

	setColor(0, 5);
	atXY(92, temp + 2);
	cout << "<<--->> T.U.R.T.O.R.I.A.L <<--->>";

	setColor(0, 2);
	atXY(92, temp + 4);
	cout << ">> Press WASD to control your spaceship.";
	atXY(92, temp + 6);
	cout << ">> Press 'j' to fire the Enemy.";
	atXY(92, temp + 8);
	cout << ">> Press 'space' to stop your spaceship.";
	atXY(92, temp + 10);
	cout << ">> Press 'p' to pause game.";
	atXY(92, temp + 12);
	cout << ">> Press 'r' to continue.";
	atXY(92, temp + 14);
	cout << ">> Press 'b' to return the previous";

	stringFlicker("Press 'r' to back the previous", 'r', 92, 18 + temp, 3, 5);
}
void aboutGame(int printSpeed) {
	vector<string>para1 = { "[ Ten Game: SPACESHIP_DEFENDER ]",
	"[ Tac Gia: CAO NHAT HAO ]",
	"[ Nam Du An: 2022 ]" };

	for (int i = 0; i < para1.size(); i++) {
		atXY(15, 5 + i);
		effectText_word(para1[i], printSpeed);
	}

	Sleep(1200);
	stringFlicker("Press 'b' to back the previous", 'b', 15, 8, 2, 4);
}
void drawInfo(int posX, int posY, int color_code) {
	*addPosY = 5;
	*g_choice = 0;
	setColor(0, color_code);

	atXY(posX, posY);
	cout << "Ban muon thong tin nao ?";
	atXY(posX + 3, posY + 2);
	cout << "1. Huong dan choi.";
	atXY(posX + 3, posY + 4);
	cout << "2. Ve cac doi tuong.";
	atXY(posX + 3, posY + 6);
	cout << "3. Ve tro choi.";
	atXY(posX + 3, posY + 8);
	cout << "4. Thoat";

	setColor(0, 5);
	cursorPos.prevPosX = posX;
	cursorPos.prevPosY = posY + 2;
	atXY(cursorPos.prevPosX, cursorPos.prevPosY);
	setColor(0, 6);
	cout << ">>";
}
void info_about_game(int printSpeed) {

again:
	system("cls");
	*addPosY = 10;
	printTitle(60, 2 + *addPosY, 3);
	*addPosY = 5;
	drawBorder(58, 15 + *addPosY, 10, 100, 2);
	drawInfo(58 + 30, 16 + *addPosY, 3);

	int startPosY = cursorPos.prevPosY;
	int endPosY = cursorPos.prevPosY + 6;

	while (true) {
		if (_kbhit()) {
			*c = _getch();
			if (*c != ' ') {
				if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN)) {
					setColor(0, 5);
					controlCursor(cursorPos);
					moveCursor(startPosY, endPosY, cursorPos);
				}
				else if (GetAsyncKeyState(VK_RETURN)) {
					if (cursorPos.prevPosY == startPosY) {
						*c = 'r';
						system("cls");
						guide();
						goto again;
					}
					else if (cursorPos.prevPosY == startPosY + 2) {
						*c = 'r';
						system("cls");
					}
					else if (cursorPos.prevPosY == startPosY + 4) {
						*c = 'r';
						system("cls");
						aboutGame(printSpeed);
					}
					else if (cursorPos.prevPosY == startPosY + 6) {

						return;
					}
				}
			}
		};
	};
}


