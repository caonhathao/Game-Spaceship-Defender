#pragma once
#ifndef _FUNCTIONS_CONTROL_CONSOLE_H

#define _FUNCTIONS_CONTROL_CONSOLE_H // !_FUNCTIONS_CONTROL_CONSOLE_H

#include<Windows.h>
using namespace std;
void setWindowSize(SHORT width, SHORT height); //inactive
	//HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	//SMALL_RECT WindowSize;
	//WindowSize.Top = 0;
	//WindowSize.Left = 0;
	//WindowSize.Right = width;
	//WindowSize.Bottom = height;

/*	SetConsoleWindowInfo(hStdout, 1, &WindowSize)*/;

void setScreenBufferSize(SHORT width, SHORT height); //inactive
	//HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD newSize;
	//newSize.X = width;
	//newSize.Y = height;
	//SetConsoleScreenBufferSize(hStdout, newSize);


void disableResizeWindow();
	//HWND hWnd = GetConsoleWindow();
	//SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);


void gotoXY(SHORT posX, SHORT posY);
	//HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD Position;
	//Position.X = posX;
	//Position.Y = posY;
	//SetConsoleCursorPosition(hStdout, Position);

void showCursor(bool cursorVisibility);
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_CURSOR_INFO	 ConCurInf;
	//ConCurInf.dwSize = 10;
	//ConCurInf.bVisible = cursorVisibility;
	//SetConsoleCursorInfo(handle, &ConCurInf);
void setColor(int background_color, int text_color);
void disableSelection();
int random(int minN, int maxN);
#endif