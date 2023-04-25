#include<iostream>
#include<vector>
#include<conio.h>

#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"variable.h"

using namespace std;
struct isLogSuccess {
	bool isSucess = false;
	int posUsers = -1;
};
isLogSuccess checkAccountExist(vector<infoPlayer>dataUsers, string name) {
	isLogSuccess A;
	for (int i = 0; i < dataUsers.size(); i++)
	{
		if (name == dataUsers[i].name)
		{
			A.isSucess = true;
			A.posUsers = i;
			return A;
		}
	}
	return A;
};
int isLogin() {
	gotoXY(90, 5);
	cout << "1. Dang nhap";
	gotoXY(90, 7);
	cout << "2. Dang ky";
	
	cursorPos.prevPosX = 85;
	cursorPos.prevPosY = 5;
	gotoXY(cursorPos.prevPosX, cursorPos.prevPosY);
	cout << ">>";

	while (true)
	{
		if (_kbhit())
		{
			*c = _getch();
			if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
			{
				controlCursor(cursorPos);
				moveCursor(5, 7, cursorPos);
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
				if (cursorPos.prevPosY == 5)
				{
					*choice = 1; break;
				}
				else if (cursorPos.prevPosY == 7)
				{
					*choice = 2; break;
				}
			}
		}
	}
	return *choice;
};
void drawLog_ResScreen(string title) {
	system("cls");
	gotoXY(105, 1);
	cout << title;
	for (int i = 0; i < 50; i++)
	{
		gotoXY(83 + i, 3);
		cout << '-';
		gotoXY(83 + i, 9);
		cout << '-';
	}
	for (int i = 0; i < 5; i++)
	{
		gotoXY(83, 4 + i);
		cout << '|';
		gotoXY(83 + 49, 4 + i);
		cout << '|';
	};
}
int login_register(vector<infoPlayer>dataUsers) {
	isLogSuccess A;

	register_again:
	drawLog_ResScreen("[<<<--->>>]");

	*choice = isLogin();

	string name;

	if (*choice == 1) // choice login
	{
		drawLog_ResScreen("LOGIN");
		gotoXY(85, 5);
		cout << "1. Ten dang nhap: ";
		cin >> name;
		gotoXY(85, 7);
		cout << "Press ENTER again";
	}
	else if (*choice == 2) //choice resgister
	{
		return -2;
	};

	while (true)
	{
		if (_kbhit()) {
			*c = _getch();

			if (*c != 'r')
			{
				A = checkAccountExist(dataUsers, name); //is user's account exist?
				if (A.isSucess)
				{
					gotoXY(85, 7);
					cout << "Login Success! Turning to the home after 3s";
					Sleep(3000);
					return A.posUsers;
				}
				else
				{
					gotoXY(85, 7);
					cout << "Login FAIL! Please check name or register";
					
					gotoXY(85, 8);
					cout << "Press 'b' to back the menu";
					while (*c != ' ')
					{
						if (_kbhit())
						{
							*c = _getch();
							if (*c == 'r')
							{
								*c = ' ';
								goto register_again;
							}
						}
					};
				}
			}

			if (*c == 'r')
			{
				return -1;
			}
			*c = ' ';
		};
	};
};