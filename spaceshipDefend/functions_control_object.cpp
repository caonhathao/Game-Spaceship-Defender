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
	gotoXY(objectPos.prevPosX, objectPos.prevPosY);
	setColor(0, idColor);
	cout << object;
};
void controlSignal(Activities& activities, char& c, int& speed,int defaultSpeed) {
	if (c == 'w')
	{
		activities = Activities::top;
		speed = defaultSpeed;
	}
	else if (c == 's')
	{
		activities = Activities::bottom;
		speed = defaultSpeed;
	}
	else if (c == 'd')
	{
		activities = Activities::right;
		speed = defaultSpeed - 50;
	}
	else if (c == 'a')
	{
		activities = Activities::left;
		speed = defaultSpeed - 50;
	}
	else if (c == ' ') {
		activities = Activities::stop;
	}
};
void controlWithoutEvent(Activities activities, Position& objectPos) {
	if (activities == Activities::top)
	{
		objectPos.nextPosX = objectPos.prevPosX;
		objectPos.nextPosY = objectPos.prevPosY - 1;
	}
	else if (activities == Activities::bottom)
	{
		objectPos.nextPosX = objectPos.prevPosX;
		objectPos.prevPosX = objectPos.prevPosY + 1;
	}
	else if (activities == Activities::left)
	{
		objectPos.nextPosX = objectPos.prevPosX - 1;
		objectPos.nextPosY = objectPos.prevPosY;
	}
	else if (activities == Activities::right)
	{
		objectPos.nextPosX = objectPos.prevPosX + 1;
		objectPos.nextPosY = objectPos.prevPosY;
	}
	else if (activities == Activities::fire)
	{
		objectPos.nextPosX = objectPos.prevPosX;
		objectPos.nextPosY = objectPos.prevPosY;
	};
};