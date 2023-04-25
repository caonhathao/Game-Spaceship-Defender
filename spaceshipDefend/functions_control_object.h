#pragma once
#ifndef _FUNCTIONS_CONTROL_OBJECT_
#include<iostream>

#include"struct.cpp"
using namespace std;

void drawObject(string object, Position& objectPos, int beginX, int endX, int beginY, int endY, int idColor);
void controlObject(Position& Object);
#endif // !_FUNCTIONS_CONTROL_OBJECT_

