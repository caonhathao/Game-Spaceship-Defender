#include<iostream>
using namespace std;
#pragma once
struct Position {
	int prevPosX = 0;
	int prevPosY = 0;
	int nextPosX = 0;
	int nextPosY = 0;
};
struct result {
	int score = 0;
	int destroyed = 0;
};
struct infoPlayer{
	int serial = 0;

	string name = "";

	int scoreChapter1 = 0;

	//chapter_2
	int process = 0;
	int contact = 0;

	int scoreChapterGame = 0;
};