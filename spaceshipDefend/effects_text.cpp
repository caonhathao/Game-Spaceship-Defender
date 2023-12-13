#include<conio.h>
#include<time.h>
#include<thread>
#include<mutex>

#include"effects_text.h"
#include"functions_control_console.h"
#include"variable.h"

using std::mutex;
mutex mtx_2;
void effectText_char(string str,  int printSpeed) {
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
		Sleep(printSpeed);
	}
	cout << endl;
}
void effectText_word(string str, int printSpeed) {
	string* word = new string("");
	str = str + ' ';
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
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
string uppercaseLetter(string name) {
	if (name == "" || name == "_")
	{
		return "";
	}
	else
	{
		string res = "";
		for (int i = 0; i < name.size(); i++)
		{
			res += name[i] - 32;
		}
		return res;
	}
}
void stringFlicker(string str,char k, int posX, int posY, int colorCode_1, int colorCode_2) {
	lock_guard<mutex>lock(mtx_2);

	//set color and change 
	clock_t start, end;
	start = clock();
	do
	{
		end = clock();
	} while ((end - start) / CLOCKS_PER_SEC < 2);
	atXY(posX, posY);
	setColor(0, colorCode_1);
	cout << str;

	*c = ' ';
	*g_count_down = 8000;

	while (*c != k)
	{
		if (_kbhit())
		{
			*c = _getch();
			*c = tolower(*c);
		}
		if (*c == k)
		{
			break;
		}

		if (*g_count_down == 0 || *g_count_down == 8000)
		{
			atXY(posX, posY);
			setColor(0, colorCode_2);
			cout << str;
			if (*g_count_down == 0)
			{
				*g_count_down = 8000;
			}
		}
		else if (*g_count_down == 4000)
		{
			atXY(posX, posY);
			setColor(0, colorCode_1);
			cout << str;
		};
		(*g_count_down)--;
	};
}