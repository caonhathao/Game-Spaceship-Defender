#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include"struct.cpp"
using namespace std;

void saveDataUsers(vector<infoPlayer>Data) {
	ofstream outputFile(".\\Data_Users.txt",ios::trunc);

	outputFile << Data[0].serial << ' ' << Data[0].name << ' ' << Data[0].scoreChapter1 << ' ' << Data[0].process << ' ' << Data[0].contact << ' ' << Data[0].scoreChapterGame;

	for (int i = 1; i < Data.size(); i++)
	{
		outputFile <<'\n' << Data[i].serial << ' ' << Data[i].name << ' ' << Data[i].scoreChapter1 << ' ' << Data[i].process << ' ' << Data[i].contact << ' ' << Data[i].scoreChapterGame;
	}
}