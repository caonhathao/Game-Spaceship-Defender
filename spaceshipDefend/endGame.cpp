#include<iostream>
#include<conio.h>
#include<time.h>

#include"effects.h"
#include"functions_control_console.h"
#include"variable.h"

using namespace std;
void endGame(int g_score, int g_destroyed, int printSpeed) {
	system("cls");
	string para1 = "<<=>> [ TONG KET THANH TICH NGUOI CHOI ] <<==>>";
	string para2 = "[ Cam on vi ban da danh thoi gian de trai nghiem game ]";
	string para3 = "[ Tong ket game: ]";

	atXY(10, 0);
	effectText_word(para1, printSpeed);
	Sleep(20);

	atXY(5, 2);
	effectText_word(para2, printSpeed);
	Sleep(20);

	atXY(5,4);
	effectText_word(para3, printSpeed);
	Sleep(20);

	atXY(5, 6);
	setColor(0, 2);
	cout << "Ban da dat duoc: ";
	setColor(0, 4);
	cout << g_score;
	setColor(0, 2);
	cout << " diem, chuc mung!" << endl;

	atXY(5, 8);
	cout << "Tieu diet tong cong ";
	setColor(0, 4);
	cout << g_destroyed;
	setColor(0, 2);
	cout << " ke dich.";
	cout << endl;

	clock_t start, end;
	start = clock();
	do
	{
		end = clock();
	} while ((end - start) / CLOCKS_PER_SEC < 3);

	atXY(10, 10);
	setColor(0, 3);
	cout << "/* Press 'r' to back the menu */";

	*c = ' ';
	while (*c == ' ')
	{
		if (_kbhit())
		{
			*c = _getch();
			*c = tolower(*c);
			if (*c == 'r')
			{
				break;
			}
		}
	};
};