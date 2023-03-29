#pragma once
#ifndef _FUNCTIONS_CONTROL_CURSOR_GAME_H

#define _FUNCTIONS_CONTROL_CURSOR_GAME_H
#include<iostream>

#include"struct.cpp"
using namespace std;

void controlCursor(Position &cursorPosition);
void moveCursor(int startPosY, int endPosY, Position &cursorPosition);
bool isCursorTouchLimit(int startPosY, int endPosY, Position cursorPosition);

#endif // !_FUNCTIONS_CONTROL_CURSOR_GAME_H

