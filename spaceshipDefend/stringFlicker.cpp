//#include<iostream>
//#include<conio.h>
//#include"functions_control_console.h"
//#include"variable.h"
//using namespace std;
//void stringFlicker(string str,int posX,int posY, int colorCode_1, int colorCode_2) {
//	//set color and change 
//	atXY(posX, posY);
//	setColor(0, colorCode_1);
//	cout << str;
//
//	*c = ' ';
//	*g_count_down = 8000;
//
//	while (*c != 'r')
//	{
//		if (_kbhit())
//		{
//			*c = _getch();
//			*c = tolower(*c);
//		}
//		if (*c == 'r')
//		{
//			break;
//		};
//
//		if (*g_count_down == 0 || *g_count_down == 8000)
//		{
//			atXY(posX, posY);
//			setColor(0, colorCode_2);
//			cout << str;
//			if (*g_count_down == 0)
//			{
//				*g_count_down = 8000;
//			}
//		}
//		else if (*g_count_down == 4000)
//		{
//			atXY(posX, posY);
//			setColor(0, colorCode_1);
//			cout << str;
//		};
//		(*g_count_down)--;
//	};
//}