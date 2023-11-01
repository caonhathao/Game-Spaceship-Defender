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

infoPlayer dataInput;

std::vector<infoPlayer> inputDataAccount();
//void startPlot();

void drawListPlayers() {
	system("cls");

	go_to_xy(91, 3);
	cout << "<<< [===] >>> List << [===] >>>" << endl;

	go_to_xy(56, 4);
	for (int i = 0; i < 100; i++)
	{
		go_to_xy(56 + i, 4); cout << '-';
		Sleep(10);
	}

	cout << setfill(' ');

	go_to_xy(56, 5);
	cout << setw(11) << left << "Serial";
	Sleep(10);
	cout << setw(10) << left << "Name";
	Sleep(10);
	cout << setw(14) << left << "Chapter_1";
	Sleep(10);
	cout << setw(14) << left << "Chapter_2";
	Sleep(10);
	cout << setw(13) << left<< "Chapter_game" << endl;
	Sleep(10);

	//go_to_xy(127, 5);
	//cout << setw(9) << left << "Total" << endl;
	//go_to_xy(127 + 9, 5);
	//cout << setw(8) << right << "Rank" << endl;

	for (size_t i = 0; i < 100; i++)
	{
		go_to_xy(56 + i, 6);
		cout << '.';
		Sleep(10);
	}

	cout << setfill(' ');

	vector<infoPlayer>Data = inputDataAccount();

	if (Data.size() != 0)
	{
		for (int i = 0; i < Data.size(); i++)
		{
			dataInput = Data[i];

			go_to_xy(56, 7 + i);

			if (dataInput.serial <= 9)
			{
				cout << setw(11) << left << "0" + to_string(dataInput.serial);
			}
			else {
				cout << setw(11) << left << dataInput.serial;
			};

			cout << setw(10) << left << dataInput.name;
			cout << setw(14) << left << dataInput.scoreChapter1;
			cout << setw(14) << left << to_string(dataInput.process) + "/" + to_string(dataInput.contact);
			cout << setw(13) << left << dataInput.scoreChapterGame << endl;
		}
	}
		
	cout << endl;
	go_to_xy(56, 7 + Data.size());
	cout << setfill('-');
	cout << setw(100) << "-" << endl;

	go_to_xy(55, 7 + Data.size() + 1);
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