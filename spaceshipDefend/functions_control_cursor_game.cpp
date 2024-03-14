#include<Windows.h>
#include<WinUser.h>
#include"functions_control_cursor_game.h"
#include"functions_control_console.h"

#include"struct.cpp"

Position cursorPosition;
bool isCursorTouchLimit(int& startPosY, int& endPosY, Position& cursorPosition) {
	if (cursorPosition.nextPosY < startPosY || cursorPosition.nextPosY > endPosY) {
		return true;
	}; return false;
};
void moveCursor(int startPosY, int endPosY, Position& cursorPosition) {
	if (!isCursorTouchLimit(startPosY, endPosY, cursorPosition)) {
		atXY(cursorPosition.prevPosX, cursorPosition.prevPosY);
		cout << "  ";
		atXY(cursorPosition.nextPosX, cursorPosition.nextPosY);
		setColor(0, 6);
		cout << ">>";

		cursorPosition.prevPosX = cursorPosition.nextPosX;
		cursorPosition.prevPosY = cursorPosition.nextPosY;
	}
	else {
		setColor(0, 6);
		cursorPosition.nextPosX = cursorPosition.prevPosX;
		cursorPosition.nextPosY = cursorPosition.prevPosY;
	}
};
void controlCursor(Position& cursorPosition, int step, string direc) {
	if (direc == "UP") {
		cursorPosition.nextPosX = cursorPosition.prevPosX;
		cursorPosition.nextPosY = cursorPosition.prevPosY - step;
	}
	else if (direc == "DOWN") {
		cursorPosition.nextPosX = cursorPosition.prevPosX;
		cursorPosition.nextPosY = cursorPosition.prevPosY + step;
	}
};