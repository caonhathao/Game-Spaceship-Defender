#include<iostream>
#include"functions_control_console.h"
using std::cout;
void drawBorder(int posX, int posY, int height, int width,int color_code) {
	setColor(0, color_code);
	for (int i = 0; i < width; i++)
	{
		atXY(posX + i, posY); cout << "-";
	};
	for (int i = 1; i <= height; i++)
	{
		atXY(posX, posY + i); cout << "|";
	};
	for (int i = 0; i < 100; i++) {
		atXY(posX + i, posY + height + 1); cout << "-";
	};
	for (int i = 1; i <=height; i++)
	{
		atXY(posX + width - 1, posY + i); cout << "|";
	}
}