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

std::vector<string>splitString(string &str) {
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
std::vector<infoPlayer> inputDataAccount(string &st_login) {
	vector<infoPlayer>res = {};

	status = _chdir(".\\Data-Account");

	if (status != 0) //if status = -1
	{
		fstream fileDataInput("data_Users.txt", ios::in);
		if (fileDataInput.fail())
		{
			status = _mkdir(".\\Data-Account");
			status = _chdir(".\\Data-Account");
		}
		fileDataInput.close();
	}

	fstream fileDataInput("data_Users.txt", ios::in);
	fileDataInput.seekg(0, ios::beg);

	if (fileDataInput.fail())//error
	{
		cout << "ERROR: Cannot open file data!";
		system("pause");
		fstream fileDataInput("data_Users.txt", ios::in | ios::trunc);
		fileDataInput.seekg(0, ios::beg);
	}

	//fileDataInput.open("data_Users.txt");

	while (!fileDataInput.eof())
	{
		string temp="";
		getline(fileDataInput, temp);
		if (temp.length() == 0)
		{
			break;
		}

		vector<string>split = splitString(temp);
		
		stringstream ss;
		ss << split[0];
		ss >> dataPlayer.serial;

		ss << split[1];
		ss >> dataPlayer.name;

		ss << split[2];
		ss >> dataPlayer.hadLogin;
		if (dataPlayer.hadLogin == true)
		{
			st_login = "current";
		};

		ss << split[3];
		ss >> dataPlayer.g_scoreChapter1;

		ss << split[4];
		ss >> dataPlayer.g_process;

		ss << split[5];
		ss >> dataPlayer.g_contact;

		ss << split[6];
		ss >> dataPlayer.g_scoreChapterGame;

		ss.clear();
		res.push_back(dataPlayer);
	};

	fileDataInput.close();

	return res;
};
