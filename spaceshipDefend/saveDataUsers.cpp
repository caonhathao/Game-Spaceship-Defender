#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include"struct.cpp"
using namespace std;

void saveDataUsers(vector<infoPlayer>Data) {
	ofstream outputFile(".\\data_Users.txt", ios::trunc);

	outputFile << Data[0].serial << ' ' << Data[0].name << ' ' << Data[0].hadLogin << ' ' << Data[0].g_scoreChapter1 << ' ' << Data[0].g_process << ' ' << Data[0].g_contact << ' ' << Data[0].g_scoreChapterGame;

	for (int i = 1; i < Data.size(); i++)
	{
		outputFile << '\n' << Data[i].serial << ' ' << Data[i].name << ' ' << Data[i].hadLogin << ' ' << Data[i].g_scoreChapter1 << ' ' << Data[i].g_process << ' ' << Data[i].g_contact << ' ' << Data[i].g_scoreChapterGame;
	}
}