#include"effects_text.h"
using namespace std;
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