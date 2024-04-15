#include<iostream>
#include<vector>
#include<conio.h>
#include<iomanip>

#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"variable.h"
#include"effects.h"

using namespace std;

struct isLogSuccess {
	bool isSucess = false;
	infoPlayer User;
};
isLogSuccess res;

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

	cin.clear();

	while (true) {
		if (_kbhit()) {
			*c = _getch();
			if (*c != ' ') {
				if (GetKeyState(VK_UP) & 0x8000) {
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
					Sleep(200);
				}
				else if (GetKeyState(VK_DOWN)&0x8000) {
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
					Sleep(200);
				}
				else if (GetKeyState(VK_RETURN) & 0x8000) {
					//system("pause");
					if (cursorPos.prevPosY == startPosY) {
						*g_choice = 1;
						break;
					}
					else if (cursorPos.prevPosY == startPosY + 2) {
						*g_choice = 2;
						break;
					}
					else {
						*g_choice = 3;
						break;
					}
				}
			}
			*c = ' ';
		}
	};
};
static void loginUI(vector<infoPlayer>& dataUsers, string& name) {
	system("cls");

	maskPoint();

	setColor(0, 14);
	effectText_char("[<>] * LOGIN * [<>]", 20, 95, 13);
	drawBorder(78, 15, 5, 52, 13);
	printTitle(57, 29, 12);

	atXY(84, 17);
	cout << ">> Ten dang nhap [type 'esc' for exit] <<";
	do {
		atXY(94, 19);
		cout << "[>>] ";
		cout << setw(name.size()) << ' ';
		atXY(99, 19);
		cin >> name;
		if (name == "esc") {
			cin.clear();
			return;
		}
		else {
			res = checkAccountExist(dataUsers, name);
			if (res.isSucess == false) {
				atXY(80, 22);
				cout << "LOGIN FAILD: Please check account name again.";
			}
			else {
				atXY(80, 22);
				cout << setw(46) << ' ';
				atXY(90, 22);
				cout << "LOGIN SUCCESS: Returning.";
				Sleep(3000);
			}
		}
	} while (res.isSucess == false);

};
static  void registerUI(vector<infoPlayer>& dataUsers) {
	system("cls");
	maskPoint();

	setColor(0, 14);
	effectText_char("[<>] * REGISTER * [<>]", 20, 95, 13);
	drawBorder(73, 15, 5, 62, 13);
	printTitle(57, 29, 12);

	string name = "";
	atXY(75, 17);
	cout << ">> Ten dang nhap toi da 10 ki tu [type 'esc' for exit] <<";
	atXY(94, 19);
	cout << "[>>] ";
	do {
		atXY(99, 19);
		cout << setw(name.size()) << ' ';
		atXY(99, 19);
		cin >> name;
		if (name.size() > 10) {
			atXY(94, 20);
			cout << "ERROR: Name is too long.";
		}
		else {
			atXY(94, 20);
			cout << setw(25) << ' ';
			atXY(94, 20);
			cout << "REGISTER SUCCESSFUL";
			Sleep(3000);
		}
	} while (name.size() > 10);

	infoPlayer tmp;
	tmp.name = name;
	tmp.hadLogin = true;
	tmp.serial = dataUsers.size() + 1;
	dataUsers.push_back(tmp);
}
infoPlayer login_register(vector<infoPlayer>&dataUsers) {
	res.User.name = "";
register_again:
	*g_choice = 0;
	isLogin();

	if (*g_choice == 1) // choice login
	{
		loginUI(dataUsers, res.User.name);
		goto register_again;
	}
	else if (*g_choice == 2) //choice resgister
	{
		registerUI(dataUsers);
		goto register_again;
	}
	else {
		return res.User;
	};
};