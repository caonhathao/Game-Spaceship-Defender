#include<iostream>
#include<vector>
#include<conio.h>

#include"functions_control_console.h"
#include"functions_control_cursor_game.h"
#include"variable.h"

using namespace std;
struct isLogSuccess {
	bool isSucess = false;
	infoPlayer Users;
};
isLogSuccess checkAccountExist(vector<infoPlayer>dataUsers, string name) {
	isLogSuccess res;

	auto it = find_if(dataUsers.begin(), dataUsers.end(), [&](const infoPlayer& a) {
		return a.name == name;
		});
	if (it!=dataUsers.end())
	{
		res.isSucess = true;
		res.Users =*it;
	}
	//for (int i = 0; i < dataUsers.size(); i++)
	//{
	//	if (name == dataUsers[i].name)
	//	{
	//		res.isSucess = true;
	//		res.posUsers = i;
	//		return res;
	//	}
	//}
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
					*g_choice = 1; break;
				}
				else if (cursorPos.prevPosY == 7)
				{
					*g_choice = 2; break;
				}
			}
		}
	}
	return *g_choice;
};
void drawLog_ResScreen(string title) {
	system("cls");
	atXY(105, 1);
	cout << title;
	for (int i = 0; i < 50; i++)
	{
		atXY(83 + i, 3);
		cout << '-';
		atXY(83 + i, 9);
		cout << '-';
	}
	for (int i = 0; i < 5; i++)
	{
		atXY(83, 4 + i);
		cout << '|';
		atXY(83 + 49, 4 + i);
		cout << '|';
	};
}
int login_register(vector<infoPlayer>dataUsers) {
	isLogSuccess A;

	register_again:
	drawLog_ResScreen("[<<<--->>>]");

	*g_choice = isLogin();

	string name;

	if (*g_choice == 1) // choice login
	{
		drawLog_ResScreen("LOGIN");
		atXY(85, 5);
		cout << "1. Ten dang nhap: ";
		cin >> name;
		atXY(85, 7);
		cout << "Press ENTER again";
	}
	else if (*g_choice == 2) //choice resgister
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
					atXY(85, 7);
					cout << "Login Success! Turning to the home after 3s";
					Sleep(3000);
					return A.posUsers;
				}
				else
				{
					atXY(85, 7);
					cout << "Login FAIL! Please check name or register";
					
					atXY(85, 8);
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