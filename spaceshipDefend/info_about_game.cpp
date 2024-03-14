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
void drawBorder(int posX, int posY, int height, int width, int color_code);
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
	*addPosY = 5;
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
	setColor(0, 6);
	cout << ">>";
}
static void guide() {
	*addPosY = 5;
	system("cls");
	printTitle(62, 2 + *addPosY, 3);

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
static void aboutObject() {
	*addPosY = 5;
	system("cls");
	printTitle(62, 2 + *addPosY, 4);

	int temp = 7 + *addPosY + 2;
	drawBorder(60, temp, 15, 100, 4);
	vector<string>tmp{
		">> |-[O]-|: Light's spaceship (control by player) <<",
		">> |-x-|: Dark;s spaceship (control by enemy) <<",
		">> [ooo]: barrier <<"
	};
	for (int i = 0; i < tmp.size(); i++) {
		setColor(0, 7);
		atXY(60 + 50 - tmp[i].size() / 2, 20 + i * 2);
		cout << tmp[i];
	};
	stringFlicker("Press 'r' to back the previous", 'r', 95, 18 + temp, 4, 6);
}
static void aboutGame(int printSpeed) {
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
void info_about_game(int printSpeed) {
again:
	system("cls");
	*addPosY = 10;
	printTitle(60, 2 + *addPosY, 3);
	*addPosY = 5;
	drawBorder(58, 15 + *addPosY, 10, 100, 2);
	drawInfo(58, 16 + *addPosY, 3);

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
						index = index + 1;
					}
					controlCursor(cursorPos, 2, "DOWN");
					moveCursor(startPosY, endPosY, cursorPos);
					//recolor new visit
					setColor(0, 5);
					atXY(posText[index].first, posText[index].second);
					cout << menuText[index];
					Sleep(100);
				}
				else if (GetAsyncKeyState(VK_UP)) {
					setColor(0, 3);
					atXY(posText[index].first, posText[index].second);
					cout << menuText[index];
					if (index > 1) {
						index = index - 1;
					}
					controlCursor(cursorPos, 2, "UP");
					moveCursor(startPosY, endPosY, cursorPos);

					setColor(0, 5);
					atXY(posText[index].first, posText[index].second);
					cout << menuText[index];
					Sleep(100);
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



