#include<iostream>
#include<conio.h>

#include"functions_control_console.h"
#include"effects.h"
void printTitle(int posX, int posY, int colorCode);
void loadingScreen() {
	system("cls");
	atXY(89, 13);
	setColor(0, 4);
	cout << "<<< --- >>> LOADING <<< --- >>>>";

	setColor(0, 7);
	atXY(52, 16);
	cout << '|';

	for (int i = 0; i <= 101; i++) {
		atXY(52 + i, 15);
		cout << '-';
		atXY(52 + i, 17);
		cout << '-';
		Sleep(10);
	}

	atXY(153, 16);
	cout << '|';

	setColor(0, 14);
	int tmpCount = 1;
	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0) {
			atXY(51 + i, 16);
			cout << "//";
			if (i <= 30) {
				Sleep(20);
			}
			else if (i <= 55) {
				Sleep(400);
			}
			else if (i <= 75) {
				Sleep(350);
			}
			else Sleep(100);
		};

		if (tmpCount == 1) {
			atXY(100, 19);
			cout << ">  ";
		}
		else if (tmpCount == 20) {
			atXY(100, 19);
			cout << " > ";
		}
		else if (tmpCount == 40) {
			atXY(100, 19);
			cout << "  >";
			tmpCount = 1;
		}
		tmpCount++;
		atXY(105, 19);
		cout << i << '%';
	}
	atXY(100, 19); cout << "          ";
	atXY(103, 19); cout << "100%";

	printTitle(55, 25, 2);

	stringFlicker("Press 'r' to continue", 'r', 94, 21, 2, 3);
}