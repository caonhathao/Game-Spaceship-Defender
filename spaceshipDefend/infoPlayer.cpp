#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include<direct.h>
#include<vector>
#include<fstream>
#include<sstream>

#include<Windows.h>

#include"functions_control_console.h"
#include"struct.cpp"

using namespace std;

int status;

infoPlayer dataPlayer;

std::vector<string>splitString(string str) {
	vector<string>res = {};
	string a = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			a = a + str[i];
		}
		else
		{
			res.push_back(a);
			a = "";
		}
	};
	res.push_back(a);
	return res;
}
std::vector<infoPlayer> inputDataAccount() {
	status = _chdir(".\\Data-Account");
	if (status!=0)
	{
		status = _mkdir(".\\Data-Account");
		status = _chdir(".\\Data-Accont");
	}

	//char buf[256];
	//cout << _getcwd(buf, 256) << endl;

	vector<infoPlayer>res = {};
	int serial = 0;
	string name = "";
	int scoreChapter1 = 0;
	int process = 0;
	int impact = 0;
	int scoreChapterGame = 0;


	fstream fileDataInput("data_Users.txt", ios::in);
	fileDataInput.seekg(0, ios::beg);

	if (fileDataInput.fail())
	{
		cout << "ERROR: Cannot open file data!";
		system("pause");
		fstream fileDataInput("data_Users.txt", ios::in | ios::trunc);
		fileDataInput.seekg(0, ios::beg);
	}

	//fileDataInput.open("data_Users.txt");

	while (!fileDataInput.eof())
	{
		char temp[255];
		fileDataInput.getline(temp, 255);
		string line = temp;
		if (line.length() == 0)
		{
			break;
		}

		vector<string>split = splitString(line);

		int num = 0;
		stringstream str_0(split[0]);
		str_0 >> num;
		dataPlayer.serial = num;

		dataPlayer.name = split[1];

		stringstream str_2(split[2]);
		str_2 >> num;
		dataPlayer.scoreChapter1 = num;

		stringstream str_3(split[3]);
		str_3 >> num;
		dataPlayer.process = num;

		stringstream str_4(split[4]);
		str_4 >> num;
		dataPlayer.contact = num;

		stringstream str_5(split[5]);
		str_5 >> num;
		dataPlayer.scoreChapterGame = num;

		res.push_back(dataPlayer);
	};

	fileDataInput.close();
	
	return res;
}