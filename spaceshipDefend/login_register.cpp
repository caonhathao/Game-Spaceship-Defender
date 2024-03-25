#include<iostream>
#include<vector>
#include<conio.h>

#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"variable.h"
#include"effects.h"

using namespace std;

struct isLogSuccess {
	bool isSucess = false;
	infoPlayer User;
};
static isLogSuccess checkAccountExist(vector<infoPlayer>dataUsers, string name) {
	isLogSuccess res;

	auto it = find_if(dataUsers.begin(), dataUsers.end(), [&](const infoPlayer& a)
		{
			return a.name == name;
		});
	if (it != dataUsers.end()) {
		res.isSucess = true;
		res.User = *it;
	}
	return res;
};
static void isLogin() {
	system("cls");
	drawBorder(83, 10, 7, 50, 6);
	atXY(102, 8);
	std::cout << "[<<<-LOGIN->>>]";

	vector<string>text = {
		"DANG NHAP",
		"DANG KI",
		"THOAT"
	};
	vector<pair<int, int>>posText{};

	for (int i = 0; i < text.size(); i++) {
		pair<int, int>tmp = make_pair(83 + 25 - text[i].size() / 2, 12 + i * 2);
		posText.push_back(tmp);
		atXY(tmp.first, tmp.second);
		setColor(0, 12);
		cout << text[i];
	}

	printTitle(60, 25, 13);

	cursorPos.prevPosX = posText[0].first - 3;
	cursorPos.prevPosY = posText[0].second;
	atXY(cursorPos.prevPosX, cursorPos.prevPosY);
	cout << ">>";

	int startPosY = 12;
	int endPosY = 16;

	int index = 0;
	atXY(posText[0].first, posText[0].second);
	setColor(0, 15);
	cout << text[index];

	while (true) {
		if (_kbhit()) {
			*c = _getch();
			if (*c != ' ') {
				if (GetAsyncKeyState(VK_UP)) {
					setColor(0, 12);
					atXY(posText[index].first, posText[index].second);
					cout << text[index];
					if (index > 0) {
						index--;
					}
					controlCursor(cursorPos, 2, "UP");
					moveCursor(startPosY, endPosY, cursorPos);

					setColor(0, 15);
					atXY(posText[index].first, posText[index].second);
					cout << text[index];
					cin.clear();
					Sleep(200);
				}
				else if (GetAsyncKeyState(VK_DOWN)) {
					setColor(0, 12);
					atXY(posText[index].first, posText[index].second);
					cout << text[index];
					if (index < 2) {
						index++;
					}
					controlCursor(cursorPos, 2, "DOWN");
					moveCursor(startPosY, endPosY, cursorPos);

					setColor(0, 15);
					atXY(posText[index].first, posText[index].second);
					cout << text[index];
					cin.clear();
					Sleep(200);
				}
				else if (GetAsyncKeyState(VK_RETURN)) {
					if (cursorPos.prevPosY == startPosY) {
						*g_choice = 1; break;
					}
					else if (cursorPos.prevPosY == startPosY + 2) {
						*g_choice = 2; break;
					}
					else *g_choice = 3; break;
				}
			}
			*c = ' ';
		}
	};
};
static void loginInterface(string& name) {
	system("cls");
	effectText_char("[<>] * LOGIN * [<>]",20, 0, 0);
	drawBorder(58, 15, 5, 100, 13);
	printTitle(58, 23, 12);

	atXY(62, 16);
	cout << ">> Ten dang nhap [type 'esc' for exit] <<";
	atXY(64, 18);
	cout << "[>>] "; cin >> name;
}
infoPlayer login_register(vector<infoPlayer>dataUsers) {
	isLogSuccess res;

register_again:
	isLogin();

	string name;

	if (*g_choice == 1) // choice login
	{
		loginInterface(name);
		lowercaseString(name);
		if (name == "esc") {
			goto register_again;
		}
	}
	else if (*g_choice == 2) //choice resgister
	{
		res.User.name = "";
		return res.User;//default-condition
	}
	else {
		res.User.name = "_";
		return res.User;
	}

	while (true)//check account
	{
		if (_kbhit()) {
			*c = _getch();

			if (*c != 'b') {
				res = checkAccountExist(dataUsers, name); //is user's account exist?
				if (res.isSucess)//yes
				{
					atXY(85, 7);
					cout << "Login Success! Turning to the home after 3s";
					Sleep(3000);
					return res.User;
				}
				else//no
				{
					atXY(85, 7);
					cout << "Login FAIL! Please check name or register";

					atXY(85, 8);
					cout << "Press 'b' to back the menu";
					while (*c != ' ') {
						if (_kbhit()) {
							*c = _getch();
							if (*c == 'b') {
								*c = ' ';
								goto register_again;
							}
						}
					};
				}
			}

			if (*c == 'b') {
				return res.User;
			}
			*c = ' ';
		};
	};
};