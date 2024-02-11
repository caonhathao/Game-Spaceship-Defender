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
isLogSuccess checkAccountExist(vector<infoPlayer>dataUsers, string name) {
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
int isLogin() {
	atXY(90, 5);
	cout << "1. Dang nhap";
	atXY(90, 7);
	cout << "2. Dang ky";

	cursorPos.prevPosX = 85;
	cursorPos.prevPosY = 5;
	atXY(cursorPos.prevPosX, cursorPos.prevPosY);
	cout << ">>";

	while (true) {
		if (_kbhit()) {
			*c = _getch();
			if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN)) {
				controlCursor(cursorPos);
				moveCursor(5, 7, cursorPos);
			}
			else if (GetAsyncKeyState(VK_RETURN)) {
				if (cursorPos.prevPosY == 5) {
					*g_choice = 1; break;
				}
				else if (cursorPos.prevPosY == 7) {
					*g_choice = 2; break;
				}
			}
		}
	}
	return *g_choice;
};
void drawLog_ResScreen(string title) {
	system("cls");
	drawBorder(83, 4, 5, 50, 6);
	atXY(105, 1);
	cout << title;
};
infoPlayer login_register(vector<infoPlayer>dataUsers) {
	isLogSuccess res;

register_again:
	drawLog_ResScreen("[<<<--->>>]");

	*g_choice = isLogin();

	string name;

	if (*g_choice == 1) // choice login
	{
		drawLog_ResScreen("LOGIN");
		atXY(85 + 25 - 20, 5);
		cout << "<*> Ten dang nhap [type 'ESC' for exit]: " << endl;

		//if user wants to back
		atXY(85 + 25, 7);
		cin >> name;
		string* temp = &name;
		lowercaseString(*temp);
		if (*temp == "esc") {
			goto register_again;
		}
		delete temp;

		atXY(85, 7);
		cout << "Press ENTER again";
	}
	else if (*g_choice == 2) //choice resgister
	{
		res.User.name = "";
		return res.User;//default-condition
	};

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