#include<iostream>
#include<conio.h>
#include<vector>

//import global variable
#include"variable.h"

//import control libraries
#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
//import effect library
#include"effects.h"

using namespace std;

bool isSkipPlotGame() {
	printTitle(60, 12, 4);
	drawBorder(59, 22, 15, 100, 3);

	vector<string>infoText = {
		"BAN CO MUON BO QUA COT TRUYEN KHONG ?",
		"CO <TUYET VOI>",
		"KHONG <TIEC QUA>"
	};
	vector<pair<int, int>>pos{};

	pair<int, int>tmp = make_pair(59 + 50 - infoText[0].size() / 2, 24 * 2);
	pos.push_back(tmp);
	atXY(pos[0].first, pos[0].second);
	setColor(0, 6);
	cout << infoText[0];

	for (int i = 1; i < infoText.size(); i++) {
		pair<int, int>tmp = make_pair(59 + 50 - infoText[i].size() / 2, 24 + i * 2);
		pos.push_back(tmp);
		atXY(pos[i].first, pos[i].second);
		setColor(0, 4);
		cout << infoText[i];
	}
	
	//create new position for cursor
	//create new limit of cursor
	cursorPos.prevPosX = pos[1].first - 5;
	cursorPos.prevPosY = pos[1].second;
	atXY(cursorPos.prevPosX, cursorPos.prevPosY);
	cout << ">>";

	int startPosY = 26;
	int endPosY = 28;

	//create motion
	int index = 1;
	atXY(pos[index].first, pos[index].second);
	setColor(0, 5);
	cout << infoText[index];
	while (true) {
		if (_kbhit()) {
			*c = _getch();
			if (*c != ' ') {
				if (GetAsyncKeyState(VK_DOWN)) {
					setColor(0, 6);
					atXY(pos[index].first, pos[index].second);
					cout << infoText[index];

					//go to the next position
					if (index < 2) {
						index++;
					};

					//move to new position
					controlCursor(cursorPos, 2, "DOWN");
					moveCursor(startPosY, endPosY, cursorPos);

					setColor(0, 7);
					atXY(pos[index].first, pos[index].second);
					cout << infoText[index];
					Sleep(100);
				}
				else if (GetAsyncKeyState(VK_UP)) {
					setColor(0, 6);
					atXY(pos[index].first, pos[index].second);
					cout << infoText[index];

					//go to the next position
					if (index > 1) {
						index--;
					};

					//move to new position
					controlCursor(cursorPos, 2, "UP");
					moveCursor(startPosY, endPosY, cursorPos);

					setColor(0, 7);
					atXY(pos[index].first, pos[index].second);
					cout << infoText[index];
					Sleep(100);
				}
				else if (GetAsyncKeyState(VK_RETURN)) {
					if (cursorPos.prevPosY == startPosY) {
						return true;
					}
					else return false;
				}
			}
		};
		*c = ' ';
	}
}