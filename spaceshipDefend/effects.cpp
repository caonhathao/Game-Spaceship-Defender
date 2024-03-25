#include<conio.h>
#include<time.h>

#include"effects.h"
#include"functions_control_console.h"
#include"variable.h"

void effectText_char(string str, int printSpeed, int X, int Y) {
	atXY(X, Y);
	for (int i = 0; i < str.length(); i++) {
		cout << str[i];
		Sleep(printSpeed);
	}
	cout << endl;
}
void effectText_word(string str, int printSpeed, int X, int Y) {
	string* word = new string("");
	str = str + ' ';
	atXY(X, Y);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			*word = *word + str[i];
		}
		else {
			cout << *word << ' ';
			*word = "";
			Sleep(printSpeed);
		}
	}
	delete word;
	cout << endl;
}

void uppercaseString(string& str) {
	if (str == "" || str == "_") {
		str = "";
	}
	else {
		string res = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				res += (str[i] - 32);
			}
		}
	}
}
void lowercaseString(string& str) {
	if (str == "" || str == "_") {
		str = "";
	}
	else {
		string res = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				res += (str[i] + 32);
			}
		}
	}
}

void stringFlicker(string str, char k, int posX, int posY, int colorCode_1, int colorCode_2) {
	//set color and change 
	clock_t start, end;
	start = clock();
	do {
		end = clock();
	} while ((end - start) / CLOCKS_PER_SEC < 2);
	atXY(posX, posY);
	setColor(0, colorCode_1);
	cout << str;

	*c = ' ';
	*g_count_down = 8000;

	while (*c != k) {
		if (_kbhit()) {
			*c = _getch();
			*c = tolower(*c);
		}
		if (*c == k) {
			break;
		}

		if (*g_count_down == 0 || *g_count_down == 8000) {
			atXY(posX, posY);
			setColor(0, colorCode_2);
			cout << str;
			if (*g_count_down == 0) {
				*g_count_down = 8000;
			}
		}
		else if (*g_count_down == 4000) {
			atXY(posX, posY);
			setColor(0, colorCode_1);
			cout << str;
		};
		(*g_count_down)--;
	};
};

void maskPoint() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 200; j++) {
			if (j % 9 == 0 && i % 2 == 0) {
				atXY(j, i); setColor(0, 3);
				cout << 'x';
			}
		}
	}
}

void drawBorder(int posX, int posY, int height, int width, int colorCode) {
	setColor(0, colorCode);
	for (int i = 0; i < width; i++) {
		atXY(posX + i, posY); cout << "-";
	};
	for (int i = 1; i <= height; i++) {
		atXY(posX, posY + i); cout << "|";
	};
	for (int i = 0; i < width; i++) {
		atXY(posX + i, posY + height + 1); cout << "-";
	};
	for (int i = 1; i <= height; i++) {
		atXY(posX + width - 1, posY + i); cout << "|";
	}
};

void printTitle(int posX, int posY, int colorCode) {

	//posX=60, posY=25: default value
	setColor(0, colorCode);

	//print 'S' :posX=60, posY=25
	{
		atXY(posX, posY); cout << "V";


		atXY(posX - 1, posY - 1); cout << "M";
		atXY(posX - 2, posY - 1); cout << "M";


		atXY(posX - 3, posY); cout << "M";
		atXY(posX - 3, posY + 1); cout << "M";


		atXY(posX - 2, posY + 2); cout << "M";
		atXY(posX - 1, posY + 2); cout << "M";


		atXY(posX, posY + 3); cout << "M";
		atXY(posX, posY + 4); cout << "M";


		atXY(posX - 1, posY + 5); cout << "M";
		atXY(posX - 2, posY + 5); cout << "M";


		atXY(posX - 3, posY + 4); cout << "A";
	}
	Sleep(20);

	//print 'P' :posX=64, posY=27
	{
		atXY(posX + 4, posY + 2); cout << "M";
		atXY(posX + 5, posY + 2); cout << "M";
		//atXY(posX + 6, posY + 2); cout << "M";

		atXY(posX + 6, posY + 1); cout << "M";
		atXY(posX + 6, posY); cout << "M";
		//atXY(posX + 6, posY - 1); cout << "M";

		atXY(posX + 5, posY - 1); cout << "M";
		atXY(posX + 4, posY - 1); cout << "M";
		//atXY(posX + 3, posY - 1); cout << "M";

		atXY(posX + 3, posY); cout << "M";
		atXY(posX + 3, posY + 1); cout << "M";
		atXY(posX + 3, posY + 2); cout << "M";
		atXY(posX + 3, posY + 3); cout << "M";
		atXY(posX + 3, posY + 4); cout << "M";
		atXY(posX + 3, posY + 5); cout << "V";
	}

	Sleep(20);
	//print 'A' :posX=69, posY=30
	{
		atXY(posX + 9, posY + 5); cout << "V";
		atXY(posX + 9, posY + 4); cout << "M";
		atXY(posX + 9, posY + 3); cout << "M";
		atXY(posX + 9, posY + 2); cout << "M";
		atXY(posX + 9, posY + 1); cout << "M";
		atXY(posX + 9, posY); cout << "M";

		atXY(posX + 10, posY - 1); cout << "M";
		atXY(posX + 11, posY - 1); cout << "M";

		atXY(posX + 12, posY); cout << "M";
		atXY(posX + 12, posY + 1); cout << "M";
		atXY(posX + 12, posY + 2); cout << "M";
		atXY(posX + 12, posY + 3); cout << "M";
		atXY(posX + 12, posY + 4); cout << "M";
		atXY(posX + 12, posY + 5); cout << "V";

		atXY(posX + 10, posY + 2); cout << "M";
		atXY(posX + 11, posY + 2); cout << "M";
	};

	Sleep(20);
	//print 'C' :posX=78, posY=26
	{
		atXY(posX + 18, posY + 1); cout << "V";
		atXY(posX + 18, posY); cout << "M";

		atXY(posX + 17, posY - 1); cout << "M";
		atXY(posX + 16, posY - 1); cout << "M";

		atXY(posX + 15, posY); cout << "M";
		atXY(posX + 15, posY + 1); cout << "M";
		atXY(posX + 15, posY + 2); cout << "M";
		atXY(posX + 15, posY + 3); cout << "M";
		atXY(posX + 15, posY + 4); cout << "M";

		atXY(posX + 16, posY + 5); cout << "M";
		atXY(posX + 17, posY + 5); cout << "M";

		atXY(posX + 18, posY + 4); cout << "M";
		atXY(posX + 18, posY + 3); cout << "A";
	}

	Sleep(20);
	//print 'E' :posX=84, posY=24
	{
		atXY(posX + 24, posY - 1); cout << ">";
		atXY(posX + 23, posY - 1); cout << "M";
		atXY(posX + 22, posY - 1); cout << "M";
		//atXY(posX + 21, posY - 1); cout << "M";

		atXY(posX + 21, posY); cout << "M";
		atXY(posX + 21, posY + 1); cout << "M";
		atXY(posX + 21, posY + 2); cout << "M";
		atXY(posX + 21, posY + 3); cout << "M";
		atXY(posX + 21, posY + 4); cout << "M";
		//atXY(posX + 21, posY + 5); cout << "M";

		atXY(posX + 22, posY + 5); cout << "M";
		atXY(posX + 23, posY + 5); cout << "M";
		atXY(posX + 24, posY + 5); cout << ">";

		atXY(posX + 22, posY + 2); cout << "M";
		atXY(posX + 23, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'S' :posX=90; posY=25
	{
		atXY(posX + 30, posY); cout << "V";
		//atXY(posX + 30, posY - 1); cout << "M";

		atXY(posX + 29, posY - 1); cout << "M";
		atXY(posX + 28, posY - 1); cout << "M";
		//atXY(posX + 27, posY - 1); cout << "M";

		atXY(posX + 27, posY); cout << "M";
		atXY(posX + 27, posY + 1); cout << "M";
		//atXY(posX + 27, posY + 2); cout << "M";

		atXY(posX + 28, posY + 2); cout << "M";
		atXY(posX + 29, posY + 2); cout << "M";
		//atXY(posX + 30, posY + 2); cout << "M";

		atXY(posX + 30, posY + 3); cout << "M";
		atXY(posX + 30, posY + 4); cout << "M";
		//atXY(posX + 30, posY + 5); cout << "M";

		atXY(posX + 29, posY + 5); cout << "M";
		atXY(posX + 28, posY + 5); cout << "M";
		//atXY(posX + 27, posY + 5); cout << "M";

		atXY(posX + 27, posY + 4); cout << "A";
	}

	Sleep(20);
	//print 'H': posX=93, posY=24;
	{
		atXY(posX + 33, posY - 1); cout << "A";
		atXY(posX + 33, posY); cout << "M";
		atXY(posX + 33, posY + 1); cout << "M";
		atXY(posX + 33, posY + 2); cout << "M";
		atXY(posX + 33, posY + 3); cout << "M";
		atXY(posX + 33, posY + 4); cout << "M";
		atXY(posX + 33, posY + 5); cout << "V";

		atXY(posX + 36, posY - 1); cout << "A";
		atXY(posX + 36, posY); cout << "M";
		atXY(posX + 36, posY + 1); cout << "M";
		atXY(posX + 36, posY + 2); cout << "M";
		atXY(posX + 36, posY + 3); cout << "M";
		atXY(posX + 36, posY + 4); cout << "M";
		atXY(posX + 36, posY + 5); cout << "V";

		atXY(posX + 34, posY + 2); cout << "M";
		atXY(posX + 35, posY + 2); cout << "M";
		atXY(posX + 36, posY + 2); cout << "M";
	}

	Sleep(20);
	//print 'I': posX=99, posY=24;
	{
		atXY(posX + 39, posY - 1); cout << "O";
		atXY(posX + 39, posY); cout << "M";
		atXY(posX + 39, posY + 1); cout << "M";
		atXY(posX + 39, posY + 2); cout << "M";
		atXY(posX + 39, posY + 3); cout << "M";
		atXY(posX + 39, posY + 4); cout << "M";
		atXY(posX + 39, posY + 5); cout << "V";
	}

	Sleep(20);
	//print 'P': posX=103, posY=27;
	{
		atXY(posX + 43, posY + 2); cout << "M";
		atXY(posX + 44, posY + 2); cout << "M";
		//atXY(posX + 45, posY + 2); cout << "M";

		atXY(posX + 45, posY + 1); cout << "M";
		atXY(posX + 45, posY); cout << "M";
		//atXY(posX + 45, posY - 1); cout << "M";

		atXY(posX + 44, posY - 1); cout << "M";
		atXY(posX + 43, posY - 1); cout << "M";
		//atXY(posX + 42, posY - 1); cout << "M";

		atXY(posX + 42, posY); cout << "M";
		atXY(posX + 42, posY + 1); cout << "M";
		atXY(posX + 42, posY + 2); cout << "M";
		atXY(posX + 42, posY + 3); cout << "M";
		atXY(posX + 42, posY + 4); cout << "M";
		atXY(posX + 42, posY + 5); cout << "V";
	};

	Sleep(20);
	//print 'space': posX=108,posY=27;
	{
		atXY(posX + 48, posY + 2); cout << "<";
		atXY(posX + 49, posY + 2); cout << "[";
		atXY(posX + 50, posY + 2); cout << "]";
		atXY(posX + 51, posY + 2); cout << ">";
	};

	Sleep(20);
	//print 'D': posX=114, posY=30;
	{
		atXY(posX + 54, posY + 5); cout << "V";
		atXY(posX + 54, posY + 4); cout << "M";
		atXY(posX + 54, posY + 3); cout << "M";
		atXY(posX + 54, posY + 2); cout << "M";
		atXY(posX + 54, posY + 1); cout << "M";
		atXY(posX + 54, posY); cout << "M";
		atXY(posX + 54, posY - 1); cout << "M";

		atXY(posX + 55, posY - 1); cout << "M";
		atXY(posX + 56, posY - 1); cout << "M";

		atXY(posX + 57, posY); cout << "M";
		atXY(posX + 57, posY + 1); cout << "M";
		atXY(posX + 57, posY + 2); cout << "M";
		atXY(posX + 57, posY + 3); cout << "M";
		atXY(posX + 57, posY + 4); cout << "M";

		atXY(posX + 56, posY + 5); cout << "M";
		atXY(posX + 55, posY + 5); cout << "<";
	}

	Sleep(20);
	//print 'E': posX=123, posY=24;
	{
		atXY(posX + 63, posY - 1); cout << ">";
		atXY(posX + 62, posY - 1); cout << "M";
		atXY(posX + 61, posY - 1); cout << "M";
		//atXY(posX + 60, posY - 1); cout << "M";

		atXY(posX + 60, posY); cout << "M";
		atXY(posX + 60, posY + 1); cout << "M";
		atXY(posX + 60, posY + 2); cout << "M";
		atXY(posX + 60, posY + 3); cout << "M";
		atXY(posX + 60, posY + 4); cout << "M";
		//atXY(posX + 60, posY + 5); cout << "M";

		atXY(posX + 61, posY + 5); cout << "M";
		atXY(posX + 62, posY + 5); cout << "M";
		atXY(posX + 63, posY + 5); cout << ">";

		atXY(posX + 60, posY + 2); cout << "M";
		atXY(posX + 61, posY + 2); cout << "M";
		atXY(posX + 62, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'F': posX=129,posY=24;
	{
		atXY(posX + 69, posY - 1); cout << ">";
		atXY(posX + 68, posY - 1); cout << "M";
		atXY(posX + 67, posY - 1); cout << "M";
		//atXY(posX + 66, posY - 1); cout << "M";

		atXY(posX + 66, posY); cout << "M";
		atXY(posX + 66, posY + 1); cout << "M";
		atXY(posX + 66, posY + 2); cout << "M";
		atXY(posX + 66, posY + 3); cout << "M";
		atXY(posX + 66, posY + 4); cout << "M";
		atXY(posX + 66, posY + 5); cout << "M";

		atXY(posX + 67, posY + 2); cout << "M";
		atXY(posX + 68, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'E': posX=135, posY=24;
	{
		atXY(posX + 75, posY - 1); cout << ">";
		atXY(posX + 74, posY - 1); cout << "M";
		atXY(posX + 73, posY - 1); cout << "M";
		//atXY(posX + 72, posY - 1); cout << "M";

		atXY(posX + 72, posY); cout << "M";
		atXY(posX + 72, posY + 1); cout << "M";
		atXY(posX + 72, posY + 2); cout << "M";
		atXY(posX + 72, posY + 3); cout << "M";
		atXY(posX + 72, posY + 4); cout << "M";
		//atXY(posX + 72, posY + 5); cout << "M";

		atXY(posX + 73, posY + 5); cout << "M";
		atXY(posX + 74, posY + 5); cout << "M";
		atXY(posX + 75, posY + 5); cout << ">";

		atXY(posX + 73, posY + 2); cout << "M";
		atXY(posX + 75, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'N': posX=138, posY=30
	{
		atXY(posX + 78, posY + 5); cout << "V";
		atXY(posX + 78, posY + 4); cout << "M";
		atXY(posX + 78, posY + 3); cout << "M";
		atXY(posX + 78, posY + 2); cout << "M";
		atXY(posX + 78, posY + 1); cout << "M";
		atXY(posX + 78, posY); cout << "M";
		atXY(posX + 78, posY - 1); cout << "A";

		atXY(posX + 79, posY + 1); cout << "~";
		atXY(posX + 80, posY + 2); cout << "~";

		atXY(posX + 81, posY - 1); cout << "A";
		atXY(posX + 81, posY); cout << "M";
		atXY(posX + 81, posY + 1); cout << "M";
		atXY(posX + 81, posY + 2); cout << "M";
		atXY(posX + 81, posY + 3); cout << "M";
		atXY(posX + 81, posY + 4); cout << "M";
		atXY(posX + 81, posY + 5); cout << "M";
	}

	Sleep(20);
	//print 'D': posX=144, posY=30;
	{
		atXY(posX + 84, posY + 5); cout << "V";
		atXY(posX + 84, posY + 4); cout << "M";
		atXY(posX + 84, posY + 3); cout << "M";
		atXY(posX + 84, posY + 2); cout << "M";
		atXY(posX + 84, posY + 1); cout << "M";
		atXY(posX + 84, posY); cout << "M";
		atXY(posX + 84, posY - 1); cout << "M";

		atXY(posX + 85, posY - 1); cout << "M";
		atXY(posX + 86, posY - 1); cout << "M";

		atXY(posX + 87, posY); cout << "M";
		atXY(posX + 87, posY + 1); cout << "M";
		atXY(posX + 87, posY + 2); cout << "M";
		atXY(posX + 87, posY + 3); cout << "M";
		atXY(posX + 87, posY + 4); cout << "M";

		atXY(posX + 86, posY + 5); cout << "M";
		atXY(posX + 85, posY + 5); cout << "<";
	}

	Sleep(20);
	//print 'E': posX=153, posY=24;
	{
		atXY(posX + 93, posY - 1); cout << ">";
		atXY(posX + 92, posY - 1); cout << "M";
		atXY(posX + 91, posY - 1); cout << "M";
		//atXY(posX + 90, posY - 1); cout << "M";

		atXY(posX + 90, posY); cout << "M";
		atXY(posX + 90, posY + 1); cout << "M";
		atXY(posX + 90, posY + 2); cout << "M";
		atXY(posX + 90, posY + 3); cout << "M";
		atXY(posX + 90, posY + 4); cout << "M";
		//atXY(posX + 90, posY + 5); cout << "M";

		atXY(posX + 91, posY + 5); cout << "M";
		atXY(posX + 92, posY + 5); cout << "M";
		atXY(posX + 93, posY + 5); cout << ">";

		atXY(posX + 91, posY + 2); cout << "M";
		atXY(posX + 92, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'R': posX=156, posY=30;
	{
		atXY(posX + 96, posY + 5); cout << "V";
		atXY(posX + 96, posY + 4); cout << "M";
		atXY(posX + 96, posY + 3); cout << "M";
		atXY(posX + 96, posY + 2); cout << "M";
		atXY(posX + 96, posY + 1); cout << "M";
		atXY(posX + 96, posY); cout << "M";
		//atXY(posX + 96, posY - 1); cout << "M";

		atXY(posX + 97, posY - 1); cout << "M";
		atXY(posX + 98, posY - 1); cout << "M";

		atXY(posX + 99, posY); cout << "M";
		atXY(posX + 99, posY + 1); cout << "M";

		atXY(posX + 98, posY + 2); cout << "M";
		atXY(posX + 97, posY + 2); cout << "M";

		atXY(posX + 99, posY + 3); cout << "M";
		atXY(posX + 99, posY + 4); cout << "M";
		atXY(posX + 99, posY + 5); cout << "V";
	}
}