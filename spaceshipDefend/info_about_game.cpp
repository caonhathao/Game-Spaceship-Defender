#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>

#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"effects.h"
#include"variable.h"
#include"struct.cpp"

#pragma region functions
void guide();
void info_about_game(int printSpeed);
void printTitle(int posX, int posY, int colorCode);
void stringFlicker(string str, char k, int posX, int posY, int colorCode_1, int colorCode_2);
#pragma endregion

vector<string>menuText{
	"[ Ban muon thong tin nao ? ]",
	"[> Huong dan choi <]",
	"[> Ve cac doi tuong <]",
	"[> Ve tro choi <]",
	"[> Thoat <]"
};
vector<pair<int, int>>posText{};

static void drawInfo(int posX, int posY, int color_code) {
	//*addPosY = 5;
	*g_choice = 0;
	setColor(0, color_code);

	for (int i = 0; i < menuText.size(); i++) {
		pair<int, int>tmp = make_pair(posX + 50 - menuText[i].size() / 2, posY + i * 2);
		atXY(tmp.first, tmp.second);
		cout << menuText[i] << endl;
		posText.push_back(tmp);
	}

	setColor(0, 5);
	cursorPos.prevPosX = posX + 30;
	cursorPos.prevPosY = posY + 2;
	atXY(cursorPos.prevPosX, cursorPos.prevPosY);
	cout << ">>";
}
static void guide() {
	system("cls");
	printTitle(62, 7, 3);

	drawBorder(60, 14, 15, 100, 4);

	setColor(0, 5);
	atXY(92, 14 + 2);
	cout << "<<--->> T.U.R.T.O.R.I.A.L <<--->>";

	setColor(0, 2);
	atXY(92, 14 + 4);
	cout << ">> Press WASD to control your spaceship.";
	atXY(92, 14 + 6);
	cout << ">> Press 'j' to fire the Enemy.";
	atXY(92, 14 + 8);
	cout << ">> Press 'space' to stop your spaceship.";
	atXY(92, 14 + 10);
	cout << ">> Press 'p' to pause game.";
	atXY(92, 14 + 12);
	cout << ">> Press 'r' to continue.";
	atXY(92, 14 + 14);
	cout << ">> Press 'b' to return the previous";

	stringFlicker("Press 'r' to back the previous", 'r', 92, 32, 3, 5);
}
static void aboutObject() {
	system("cls");
	printTitle(62, 7, 4);

	drawBorder(60, 14, 15, 100, 4);
	vector<string>para{
		">> |-[O]-|: Light's spaceship (control by player) <<",
		">> |-x-|: Dark's spaceship (control by enemy) <<",
		">> [ooo]: barrier <<"
	};
	for (int i = 0; i < para.size(); i++) {
		setColor(0, 7);
		atXY(60 + 50 - para[i].size() / 2, 20 + i * 2);
		cout << para[i];
	};
	stringFlicker("Press 'r' to back the previous", 'r', 95, 32 ,4, 6);
}
static void aboutGame(int printSpeed) {
	vector<string>para = { "[ Ten Game: SPACESHIP_DEFENDER ]",
	"[ Tac Gia: CAO NHAT HAO ]",
	"[ Nam Du An: 2022 ]" };

	printTitle(60, 5, 5);
	drawBorder(59, 12, 10, 100, 14);

	for (int i = 0; i < para.size(); i++) {
		effectText_char(para[i], 20, 59 + 50 - para[i].size() / 2, 16 + i * 2);
	};
	stringFlicker("Press 'b' to return", 'b', 100, 26, 13, 14);
}
void info_about_game(int printSpeed) {
again:
	system("cls");
	printTitle(60, 12, 3);
	drawBorder(58, 22, 11, 100, 2);
	drawInfo(58, 24, 3);

	int startPosY = cursorPos.prevPosY;
	int endPosY = cursorPos.prevPosY + 6;

	int index = 1;
	atXY(posText[index].first, posText[index].second);
	setColor(0, 5);
	cout << menuText[index];

	while (true) {
		if (_kbhit()) {
			*c = _getch();
			if (*c != ' ') {
				if (GetAsyncKeyState(VK_DOWN)) {
					//recolor visited
					setColor(0, 3);
					atXY(posText[index].first, posText[index].second);
					cout << menuText[index];

					//go to the next place
					if (index < 4) {
						index++;
					}
					controlCursor(cursorPos, 2, "DOWN");
					moveCursor(startPosY, endPosY, cursorPos);
					//recolor new visit
					setColor(0, 5);
					atXY(posText[index].first, posText[index].second);
					cout << menuText[index];
					Sleep(500);
				}
				else if (GetAsyncKeyState(VK_UP)) {
					setColor(0, 3);
					atXY(posText[index].first, posText[index].second);
					cout << menuText[index];
					if (index > 1) {
						index--;
					}
					controlCursor(cursorPos, 2, "UP");
					moveCursor(startPosY, endPosY, cursorPos);

					setColor(0, 5);
					atXY(posText[index].first, posText[index].second);
					cout << menuText[index];
					Sleep(500);
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
						aboutObject();
						system("cls");
						goto again;
					}
					else if (cursorPos.prevPosY == startPosY + 4) {
						*c = 'r';
						system("cls");
						aboutGame(printSpeed);
						goto again;
					}
					else if (cursorPos.prevPosY == startPosY + 6) {

						return;
					}
				}
			}
			*c = ' ';
		}
	};
};



