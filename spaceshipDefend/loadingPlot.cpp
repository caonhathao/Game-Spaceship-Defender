#include<iostream>
#include<conio.h>

#include"functions_control_console.h"
#include"variable.h"

using namespace std;
void stringFlicker(string str, int posX, int posY, int colorCode_1, int colorCode_2);
void loadingPlot() {
	system("cls");

	atXY(90, 13);
	setColor(0, 4);
	cout << "<<< --- >>> LOADING PLOT <<< --- >>>>";

	setColor(0, 7);
	atXY(55, 16);
	cout << '|';

	for (int i = 0; i <= 101; i++)
	{
		atXY(55 + i, 15);
		cout << '-';
		atXY(55 + i, 17);
		cout << '-';
		Sleep(10);
	}

	atXY(156, 16);
	cout << '|';
	atXY(158, 16);
	cout << ">>>";

	setColor(0, 14);
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			atXY(54 + i, 16);
			cout << "//";
			Sleep(20);
		};
		atXY(162, 16);
		cout << i << '%';
	}
	stringFlicker("Press 'r' to continue", 95, 19, 2, 3);
}