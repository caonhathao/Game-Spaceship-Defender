#include<iostream>
#include<Windows.h>
using namespace std;
void effectText_char(int printSpeed, string str) {
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
		Sleep(printSpeed);
	}
	cout << endl;
}