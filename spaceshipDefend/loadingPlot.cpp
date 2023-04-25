#include<iostream>
#include<conio.h>

#include"functions_control_console.h"
#include"variable.h"

using namespace std;
void loadingPlot() {
	system("cls");

	gotoXY(90, 13);
	setColor(0, 4);
	cout << "<<< --- >>> LOADING PLOT <<< --- >>>>";

	setColor(0, 7);
	gotoXY(55, 16);
	cout << '|';

	for (int i = 0; i <= 101; i++)
	{
		gotoXY(55 + i, 15);
		cout << '-';
		gotoXY(55 + i, 17);
		cout << '-';
		Sleep(10);
	}

	gotoXY(156, 16);
	cout << '|';
	gotoXY(158, 16);
	cout << ">>>";

	setColor(0, 14);
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			gotoXY(54 + i, 16);
			cout << "//";
			Sleep(20);
		};
		gotoXY(162, 16);
		cout << i << '%';
	}

	gotoXY(95, 19);
	setColor(0, 2);
	cout << "Press 'r' to continue!";

	*c = ' ';
	*g_count_down = 3000;

	while (*c != 'r')
	{
		if (_kbhit())
		{
			*c = _getch();
			*c = tolower(*c);
		}
		if (*c == 'r')
		{
			break;
		};

		if (*g_count_down == 0 || *g_count_down == 3000)
		{
			gotoXY(95, 19);
			setColor(0, 3);
			cout << "Press 'r' to continue!";
			if (*g_count_down == 0)
			{
				*g_count_down = 3000;
			}
		}
		else if (*g_count_down == 1500)
		{
			gotoXY(95, 19);
			setColor(0, 2);
			cout << "Press 'r' to continue!";
		};
		(*g_count_down)--;
	};
}