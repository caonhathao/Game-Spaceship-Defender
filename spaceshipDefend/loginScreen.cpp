#include<iostream>
#include<conio.h>
#include"functions_control_console.h"

string* str = new string();

void effectText_char(int printSpeed, string str);
void drawScreen() {
	for (int i = 0; i < 100; i++)
	{
		gotoXY(15 + i, 5);
		cout << '-';
	}
	for (int i = 1; i <= 15; i++)
	{
		gotoXY(15, 5 + i);
		cout << '|';
	}
	for (int i = 0; i < 100; i++)
	{
		gotoXY(15 + i, 20);
		cout << '-';
	}
	for (size_t i = 1; i < 15; i++)
	{
		gotoXY(114, 5 + i);
		cout << '|';
	}
}
int loginScreen(int printSpeed) {
	system("cls");

	gotoXY(50, 2);
	*str = "WELCOME TO SPACESHIP_DEFENDER GAME!";
	effectText_char(printSpeed, *str);

	gotoXY(15, 3);
	*str = "[ NOTE: Game nay duoc lam ra chi co muc dich duy nhat la vui ve ma thoi, ngoai ra thi cha co gi khac! ]";
	effectText_char(printSpeed, *str);

	drawScreen();
	gotoXY(18, 6);
	*str = "Chuc ban co trai nghiem vui ve :)";
	effectText_char(printSpeed, *str);

	gotoXY(28, 8);
	cout << "< --- > MOI CHON < --- >";

	Sleep(500);
	gotoXY(28, 10);
	cout << "1. Choi ngay va luon.";

	Sleep(500);
	gotoXY(28, 12);
	cout << "2. Dang nhap";

	Sleep(500);
	gotoXY(28, 14);
	cout << "3. Thong tin ve game.";

	Sleep(500);
	gotoXY(28, 16);
	cout << "4. About me?";

	Sleep(500);
	gotoXY(28, 18);
	cout << ">> ";

	int res = 0;
	cin >> res;
	return res;
}
//int main() {
//	loginScreen(20);
//	return 0;
//}