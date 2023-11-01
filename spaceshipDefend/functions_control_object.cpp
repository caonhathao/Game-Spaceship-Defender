#pragma once

#include"functions_control_object.h"
#include"functions_control_console.h"
#include"struct.cpp"
#include"variable.h"	

void drawObject(string object, Position& objectPos, int beginX, int endX, int beginY, int endY, int idColor) {
	objectPos.prevPosX = random(beginX, endX);
	objectPos.prevPosY = random(beginY, endY);
	objectPos.nextPosX = 0;
	objectPos.nextPosY = 0;
	setColor(0, idColor);
	go_to_xy(objectPos.prevPosX, objectPos.prevPosY);
	cout << object;
};
void controlSignal(Activities& activities, char& c, int& speed,int& step) {
	if (c == 'w')
	{
		activities = Activities::top;
		step = 1;
	}
	else if (c == 's')
	{
		activities = Activities::bottom;
		step = 1;
	}
	else if (c == 'd')
	{
		activities = Activities::right;
		step = 2;
	}
	else if (c == 'a')
	{
		activities = Activities::left;
		step = 2;
	}
	else if (c == ' ') {
		activities = Activities::stop;
	}
};
void controlWithoutEvent(Activities activities, Position& objectPos, int& step) {
	if (activities == Activities::top)
	{
		objectPos.nextPosX = objectPos.prevPosX;
		objectPos.nextPosY = objectPos.prevPosY - step;
	}
	else if (activities == Activities::bottom)
	{
		objectPos.nextPosX = objectPos.prevPosX;
		objectPos.nextPosY = objectPos.prevPosY + step;
	}
	else if (activities == Activities::left)
	{
		objectPos.nextPosX = objectPos.prevPosX - step;
		objectPos.nextPosY = objectPos.prevPosY;
	}
	else if (activities == Activities::right)
	{
		objectPos.nextPosX = objectPos.prevPosX + step;
		objectPos.nextPosY = objectPos.prevPosY;
	}
	else if (activities == Activities::fire || activities == Activities::stop)
	{
		objectPos.nextPosX = objectPos.prevPosX;
		objectPos.nextPosY = objectPos.prevPosY;
	};
};	