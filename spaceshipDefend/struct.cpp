#include<iostream>
using std::string;
#pragma once
struct Position {
	int prevPosX = 0;
	int prevPosY = 0;
	int nextPosX = 0;
	int nextPosY = 0;
};
struct result {
	int g_score = 0;
	int g_destroyed = 0;
	int g_process = 0;
	int g_contact = 0;
};
struct infoPlayer{
	int serial = 0;

	string name = "";

	int g_scoreChapter1 = 0;

	//chapter_2
	int g_process = 0;
	int g_contact = 0;

	int g_scoreChapterGame = 0;
	infoPlayer() {};
};