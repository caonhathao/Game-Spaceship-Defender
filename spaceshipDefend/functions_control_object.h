#pragma once
#ifndef _FUNCTIONS_CONTROL_OBJECT_
#include<iostream>

#include"struct.cpp"
#include"variable.h"
using namespace std;

void drawObject(string object, Position& objectPos, int beginX, int endX, int beginY, int endY, int idColor);
void controlSignal(Activities& activities, char& c, int& speed, int& step);
void controlWithoutEvent(Activities activities ,Position& Object, int& step);
#endif // !_FUNCTIONS_CONTROL_OBJECT_

