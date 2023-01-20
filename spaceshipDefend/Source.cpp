#include<iostream>
#include<conio.h>
#include"functions_control_console.h"

int g_printSpeed = 20; //toc do in

#pragma region functions
int loginScreen(int printSpeed);
void story_chapter_1(int printSpeed);
void stage_chapter_1(int speed);
void stage_chapter_game();
#pragma endregion

#pragma region plot
void startPlot() {
	story_chapter_1(g_printSpeed);
}
#pragma endregion

//int main() {
//	//startPlot();
//	showCursor(false);
//	int res = loginScreen(g_printSpeed);
//	if (res==1)
//	{
//		system("cls");
//		cout << "Ban co muon di theo cot truyen khong (Y/N): ";
//		char c;
//		cin >> c;
//		c = tolower(c);
//		if (c=='y')
//		{
//			story_chapter_1(g_printSpeed);
//			stage_chapter_1(200);
//		}
//		else stage_chapter_game();
//	}
//	return 0;
//}