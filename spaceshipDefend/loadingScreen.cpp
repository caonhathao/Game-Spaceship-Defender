#include<iostream>
#include<conio.h>

#include"functions_control_console.h"
using std::cout;
void stringFlicker(string str, int posX, int posY, int colorCode_1, int colorCode_2);
void printTitle(int posX, int posY, int colorCode);
void loadingScreen() {
	system("cls");
	atXY(91, 13);
	setColor(0, 4);
	cout << "<<< --- >>> LOADING <<< --- >>>>";

	setColor(0, 7);
	atXY(54, 16);
	cout << '|';

	for (int i = 0; i <= 101; i++)
	{
		atXY(54 + i, 15);
		cout << '-';
		atXY(54 + i, 17);
		cout << '-';
		Sleep(10);
	}

	atXY(155, 16);
	cout << '|';

	setColor(0, 14);
	int tmpCount = 1;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			atXY(53 + i, 16);
			cout << "//";
			Sleep(20);
		};

		if (tmpCount == 1) {
			atXY(157, 16);
			cout << ">  ";
		}
		else if (tmpCount == 20)
		{
			atXY(157, 16);
			cout << " > ";
		}
		else if (tmpCount == 40)
		{
			atXY(157, 16);
			cout << "  >";
			tmpCount = 1;
		}
		tmpCount++;
		atXY(162, 16);
		cout << i << '%';
	}
	atXY(157, 16); cout << ">>>";

	printTitle(60, 25, 2);

	stringFlicker("Press 'r' to continue", 96, 19, 2, 3);
}