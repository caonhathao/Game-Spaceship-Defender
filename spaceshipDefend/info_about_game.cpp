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
void aboutGame(int printSpeed);
void info_about_game(int printSpeed);
void drawBorder(int posX, int posY, int height, int width, int color_code);
void printTitle(int posX, int posY, int colorCode);
void stringFlicker(string str, char k, int posX, int posY, int colorCode_1, int colorCode_2);
void show(int printSpeed);
#pragma endregion
void guide() {
	system("cls");
	printTitle(60, 2, 3);
	atXY(25, 0);
	cout << "<<--->> T.U.R.T.O.R.I.A.L <<--->>";

	atXY(25, 3);
	for (int i = 1; i <= 13; i++) {
		atXY(25, 3 + i); cout << "||";
	};

	atXY(28, 5);
	cout << "Press WASD to control your spaceship.";
	atXY(28, 7);
	cout << "Press 'j' to fire the Enemy.";
	atXY(28, 9);
	cout << "Press 'space' to stop your spaceship.";
	atXY(28, 11);
	cout << "Press 'p' to pause game.";
	atXY(28, 13);
	cout << "Press 'r' to continue.";
	atXY(28, 15);
	cout << "Press 'b' to return the previous";

	stringFlicker("Press 'r' to back the previous", 'r', 50, 20, 3, 5);
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
void show(int printSpeed) {
	int startPosY = 17;
	int endPosY = 23;
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
						*c = ' ';
					}
					else if (cursorPos.prevPosY == startPosY + 2) {
						*c = 'r';
						system("cls");
						aboutGame(printSpeed);
						*c = ' ';
					}
					else if (cursorPos.prevPosY == startPosY + 4) {
						*c = ' ';
						break;
					}
					else if (cursorPos.prevPosX == startPosY + 6) {
						break;
					}
				}
			}
			*c = ' ';
		};
	};
}
void info_about_game(int printSpeed) {
	system("cls");

	//added 5 units for Y position
	printTitle(60, 7, 3);
	drawBorder(58, 15, 15, 100, 2);
	drawInfo(58 + 30, 20, 3);

	show(printSpeed);
	//stringFlicker("Press 'r' to bach the previous", 'r', 50, 30, 3, 4);
}


