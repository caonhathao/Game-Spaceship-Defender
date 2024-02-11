#pragma once
#ifndef _FUNCTIONS_CONTROL_CONSOLE_H

#define _FUNCTIONS_CONTROL_CONSOLE_H // !_FUNCTIONS_CONTROL_CONSOLE_H

#include<Windows.h>
using namespace std;
void setWindowSize(SHORT width, SHORT height);
void setScreenBufferSize(SHORT width, SHORT height);
void moveWindow(SHORT x, SHORT y, SHORT width, SHORT height);
void disableResizeWindow();
void atXY(SHORT posX, SHORT posY);
void showCursor(bool cursorVisibility);
void showScrollbar(BOOL Show);
void setColor(int background_color, int text_color);
void disableSelection();
int random(int minN, int maxN);
#endif