#include<iostream>
#include<conio.h>
#include<time.h>
#include<vector>

#include"effects.h"
#include"functions_control_console.h"
#include"variable.h"

using namespace std;
void endGame(int g_score, int g_destroyed, int printSpeed) {
	system("cls");
	printTitle(60, 6, 2);

	vector<string>text={ 
		"<< == >> [ TONG KET THANH TICH NGUOI CHOI ] << == >>" ,
		"[ Cam on vi ban da danh thoi gian de trai nghiem game ]",
		"[ Tong ket game ]"
	};

	for (int i = 0; i < text.size(); i++) {
		atXY(58 + 50 - text[i].size() / 2, 16 + i * 2);
		setColor(0, 5);
		cout << text[i];
	}

	drawBorder(58, 23, 10, 100, 4);

	atXY(91, 24);
	setColor(0, 2);
	cout << "Ban da dat duoc: ";
	setColor(0, 4);
	cout << g_score;
	setColor(0, 2);
	cout << " diem, chuc mung!" << endl;

	atXY(93, 26);
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

	stringFlicker("Press 'b' to return", 'b', 99, 35, 5, 7);
};