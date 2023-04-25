#include<iostream>
#include<conio.h>

#include"effects_text.h"
#include"functions_control_console.h"
#include"variable.h"

using namespace std;
void endGame(int score, int destroyed, int printSpeed) {
	system("cls");
	string para1 = "[ Cam on vi ban da danh thoi gian de trai nghiem game ]";
	string para2 = "[ Tong ket game: ]";

	effectText_word(para1, printSpeed);
	Sleep(20);
	effectText_word(para2, printSpeed);
	Sleep(20);

	setColor(0, 2);
	cout << "Ban da dat duoc: ";
	setColor(0, 4);
	cout << score;
	setColor(0, 2);
	cout << " diem, chuc mung!" << endl;


	cout << "Tieu diet tong cong ";
	setColor(0, 4);
	cout << destroyed;
	setColor(0, 2);
	cout << " ke dich.";
	cout << endl;
	cout << "/* Press 'r' to back the menu */";

	*c = ' ';
	while (*c == ' ')
	{
		if (_kbhit())
		{
			*c = _getch();
			*c = tolower(*c);
		}
	};
}