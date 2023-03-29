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
		if (name==dataUsers[i].name)
		{
			A.isSucess = true;
			A.posUsers = i;
			return A;
		}
	}
	return A;
}
void drawLoginScreen() {
	system("cls");
	gotoXY(105, 1);
	cout << "LOGIN";
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
int loginScreen(vector<infoPlayer>dataUsers) {
	isLogSuccess A;
	while (true)
	{
		drawLoginScreen();

		gotoXY(85, 5);
		cout << "1. Ten dang nhap:";
		string name;
		cin >> name;

		if (_kbhit())
		{
			c = _getch();
			if (GetAsyncKeyState(VK_RETURN))
			{
				A = checkAccountExist(dataUsers, name);
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
				}
			}
			else if (c == 'r')
			{
				return -1;
			}
			c = ' ';
		};
	}
}
int main() {
	drawLoginScreen();
	return 0;
}