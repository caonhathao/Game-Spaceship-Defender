#include<iostream>
#include<iomanip>
#include<string>
#include<conio.h>
#include<vector>
#include<cstring>

#include"functions_control_console.h"
#include"variable.h"
#include"struct.cpp"

using namespace std;


void drawListPlayers(vector<infoPlayer>& data) {
	system("cls");

	infoPlayer dataInput;

	atXY(91, 3);
	cout << "<<< [===] >>> List <<< [===] >>>" << endl;

	atXY(56, 4);
	for (int i = 0; i < 100; i++)
	{
		atXY(56 + i, 4); cout << '-';
		Sleep(10);
	}

	cout << setfill(' ');

	atXY(56, 5);
	cout << setw(9) << left << "Serial";
	Sleep(10);
	cout << setw(20) << left << "Name";
	Sleep(10);
	cout << setw(11) << left << "Status";
	Sleep(10);
	cout << setw(14) << left << "Chapter_1";
	Sleep(10);
	cout << setw(14) << left << "Chapter_2";
	Sleep(10);
	cout << setw(16) << left << "Chapter_end";
	Sleep(10);
	cout << setw(10) << left << "Total";
	Sleep(10);
	cout << setw(9) << right << "Rank" << endl;

	for (size_t i = 0; i < 100; i++)
	{
		atXY(56 + i, 6);
		cout << '.';
		Sleep(10);
	}

	cout << setfill(' ');

	if (data.size() != 0)
	{
		for (int i = 0; i < data.size(); i++)
		{
			dataInput = data[i];

			atXY(56, 7 + i);

			if (dataInput.serial <= 9)
			{
				cout << setw(9) << left << "0" + to_string(dataInput.serial);
			}
			else {
				cout << setw(9) << left << dataInput.serial;
			};

			cout << setw(20) << left << dataInput.name;

			if (dataInput.hadLogin == true)
			{
				cout << setw(11) << left << "current";
			}
			else cout << setw(11) << left << "last";

			cout << setw(14) << left << dataInput.g_scoreChapter1;
			cout << setw(14) << left << to_string(dataInput.g_process) + "/" + to_string(dataInput.g_contact);
			cout << setw(16) << left << dataInput.g_scoreChapterGame << endl;
		}
	}

	cout << endl;
	atXY(56, 7 + data.size());
	cout << setfill('-');
	cout << setw(100) << "-" << endl;

	atXY(55, 7 + data.size() + 1);
	setColor(0, 3);

	cout << "Press 'r' back the menu";
	*c = ' ';
	while (true)
	{
		if (_kbhit()) {
			*c = _getch();
			*c = tolower(*c);
			if (*c == 'r')
			{
				break;
			}
		}
	}
}
//int main() {
//	vector<infoPlayer>Data = inputDataAccount();
//	drawListPlayers(Data);
//}