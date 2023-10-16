#include<iostream>
#include"functions_control_console.h"
using std::cout;
void printTitle(int posX, int posY, int colorCode) {

	//posX=60, posY=25: default value
	setColor(0, colorCode);

	//print 'S' :posX=60, posY=25
	{
		gotoXY(posX, posY); cout << "V";
		gotoXY(posX, posY - 1); cout << "M";

		gotoXY(posX - 1, posY - 1); cout << "M";
		gotoXY(posX - 2, posY - 1); cout << "M";
		gotoXY(posX - 3, posY - 1); cout << "M";

		gotoXY(posX - 3, posY); cout << "M";
		gotoXY(posX - 3, posY + 1); cout << "M";

		gotoXY(posX - 3, posY + 2); cout << "M";
		gotoXY(posX - 2, posY + 2); cout << "M";
		gotoXY(posX - 1, posY + 2); cout << "M";
		gotoXY(posX, posY + 2); cout << "M";

		gotoXY(posX, posY + 3); cout << "M";
		gotoXY(posX, posY + 4); cout << "M";
		gotoXY(posX, posY + 5); cout << "M";

		gotoXY(posX - 1, posY + 5); cout << "M";
		gotoXY(posX - 2, posY + 5); cout << "M";
		gotoXY(posX - 3, posY + 5); cout << "M";

		gotoXY(posX - 3, posY + 4); cout << "A";
	}
	Sleep(20);

	//print 'P' :posX=64, posY=27
	{
		gotoXY(posX + 4, posY + 2); cout << "M";
		gotoXY(posX + 5, posY + 2); cout << "M";
		gotoXY(posX + 6, posY + 2); cout << "M";

		gotoXY(posX + 6, posY + 1); cout << "M";
		gotoXY(posX + 6, posY); cout << "M";
		gotoXY(posX + 6, posY - 1); cout << "M";

		gotoXY(posX + 5, posY - 1); cout << "M";
		gotoXY(posX + 4, posY - 1); cout << "M";
		gotoXY(posX + 3, posY - 1); cout << "M";

		gotoXY(posX + 3, posY); cout << "M";
		gotoXY(posX + 3, posY + 1); cout << "M";
		gotoXY(posX + 3, posY + 2); cout << "M";
		gotoXY(posX + 3, posY + 3); cout << "M";
		gotoXY(posX + 3, posY + 4); cout << "M";
		gotoXY(posX + 3, posY + 5); cout << "V";
	}

	Sleep(20);
	//print 'A' :posX=69, posY=30
	{
		gotoXY(posX + 9, posY + 5); cout << "V";
		gotoXY(posX + 9, posY + 4); cout << "M";
		gotoXY(posX + 9, posY + 3); cout << "M";
		gotoXY(posX + 9, posY + 2); cout << "M";
		gotoXY(posX + 9, posY + 1); cout << "M";
		gotoXY(posX + 9, posY); cout << "M";
		gotoXY(posX + 9, posY - 1); cout << "M";

		gotoXY(posX + 10, posY - 1); cout << "M";
		gotoXY(posX + 11, posY - 1); cout << "M";
		gotoXY(posX + 12, posY - 1); cout << "M";

		gotoXY(posX + 12, posY); cout << "M";
		gotoXY(posX + 12, posY + 1); cout << "M";
		gotoXY(posX + 12, posY + 2); cout << "M";
		gotoXY(posX + 12, posY + 3); cout << "M";
		gotoXY(posX + 12, posY + 4); cout << "M";
		gotoXY(posX + 12, posY + 5); cout << "V";

		gotoXY(posX + 10, posY + 2); cout << "M";
		gotoXY(posX + 11, posY + 2); cout << "M";
	};

	Sleep(20);
	//print 'C' :posX=78, posY=26
	{
		gotoXY(posX + 18, posY + 1); cout << "V";
		gotoXY(posX + 18, posY); cout << "M";
		gotoXY(posX + 18, posY - 1); cout << "M";
		gotoXY(posX + 17, posY - 1); cout << "M";
		gotoXY(posX + 16, posY - 1); cout << "M";
		gotoXY(posX + 15, posY - 1); cout << "M";
		gotoXY(posX + 15, posY); cout << "M";
		gotoXY(posX + 15, posY + 1); cout << "M";
		gotoXY(posX + 15, posY + 2); cout << "M";
		gotoXY(posX + 15, posY + 3); cout << "M";
		gotoXY(posX + 15, posY + 4); cout << "M";
		gotoXY(posX + 15, posY + 5); cout << "M";
		gotoXY(posX + 16, posY + 5); cout << "M";
		gotoXY(posX + 17, posY + 5); cout << "M";
		gotoXY(posX + 18, posY + 5); cout << "M";
		gotoXY(posX + 18, posY + 4); cout << "M";
		gotoXY(posX + 18, posY + 3); cout << "A";
	}

	Sleep(20);
	//print 'E' :posX=84, posY=24
	{
		gotoXY(posX + 24, posY - 1); cout << ">";
		gotoXY(posX + 23, posY - 1); cout << "M";
		gotoXY(posX + 22, posY - 1); cout << "M";
		gotoXY(posX + 21, posY - 1); cout << "M";

		gotoXY(posX + 21, posY); cout << "M";
		gotoXY(posX + 21, posY + 1); cout << "M";
		gotoXY(posX + 21, posY + 2); cout << "M";
		gotoXY(posX + 21, posY + 3); cout << "M";
		gotoXY(posX + 21, posY + 4); cout << "M";
		gotoXY(posX + 21, posY + 5); cout << "M";

		gotoXY(posX + 22, posY + 5); cout << "M";
		gotoXY(posX + 23, posY + 5); cout << "M";
		gotoXY(posX + 24, posY + 5); cout << ">";

		gotoXY(posX + 22, posY + 2); cout << "M";
		gotoXY(posX + 23, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'S' :posX=90; posY=25
	{
		gotoXY(posX + 30, posY); cout << "V";
		gotoXY(posX + 30, posY - 1); cout << "M";

		gotoXY(posX + 29, posY - 1); cout << "M";
		gotoXY(posX + 28, posY - 1); cout << "M";
		gotoXY(posX + 27, posY - 1); cout << "M";

		gotoXY(posX + 27, posY); cout << "M";
		gotoXY(posX + 27, posY + 1); cout << "M";
		gotoXY(posX + 27, posY + 2); cout << "M";

		gotoXY(posX + 28, posY + 2); cout << "M";
		gotoXY(posX + 29, posY + 2); cout << "M";
		gotoXY(posX + 30, posY + 2); cout << "M";

		gotoXY(posX + 30, posY + 3); cout << "M";
		gotoXY(posX + 30, posY + 4); cout << "M";
		gotoXY(posX + 30, posY + 5); cout << "M";

		gotoXY(posX + 29, posY + 5); cout << "M";
		gotoXY(posX + 28, posY + 5); cout << "M";
		gotoXY(posX + 27, posY + 5); cout << "M";

		gotoXY(posX + 27, posY + 4); cout << "A";
	}

	Sleep(20);
	//print 'H': posX=93, posY=24;
	{
		gotoXY(posX + 33, posY - 1); cout << "A";
		gotoXY(posX + 33, posY); cout << "M";
		gotoXY(posX + 33, posY + 1); cout << "M";
		gotoXY(posX + 33, posY + 2); cout << "M";
		gotoXY(posX + 33, posY + 3); cout << "M";
		gotoXY(posX + 33, posY + 4); cout << "M";
		gotoXY(posX + 33, posY + 5); cout << "V";

		gotoXY(posX + 36, posY - 1); cout << "A";
		gotoXY(posX + 36, posY); cout << "M";
		gotoXY(posX + 36, posY + 1); cout << "M";
		gotoXY(posX + 36, posY + 2); cout << "M";
		gotoXY(posX + 36, posY + 3); cout << "M";
		gotoXY(posX + 36, posY + 4); cout << "M";
		gotoXY(posX + 36, posY + 5); cout << "V";

		gotoXY(posX + 34, posY + 2); cout << "M";
		gotoXY(posX + 35, posY + 2); cout << "M";
		gotoXY(posX + 36, posY + 2); cout << "M";
	}

	Sleep(20);
	//print 'I': posX=99, posY=24;
	{
		gotoXY(posX + 39, posY - 1); cout << "O";
		gotoXY(posX + 39, posY); cout << "M";
		gotoXY(posX + 39, posY + 1); cout << "M";
		gotoXY(posX + 39, posY + 2); cout << "M";
		gotoXY(posX + 39, posY + 3); cout << "M";
		gotoXY(posX + 39, posY + 4); cout << "M";
		gotoXY(posX + 39, posY + 5); cout << "V";
	}

	Sleep(20);
	//print 'P': posX=103, posY=27;
	{
		gotoXY(posX + 43, posY + 2); cout << "M";
		gotoXY(posX + 44, posY + 2); cout << "M";
		gotoXY(posX + 45, posY + 2); cout << "M";

		gotoXY(posX + 45, posY + 1); cout << "M";
		gotoXY(posX + 45, posY); cout << "M";
		gotoXY(posX + 45, posY - 1); cout << "M";

		gotoXY(posX + 44, posY - 1); cout << "M";
		gotoXY(posX + 43, posY - 1); cout << "M";
		gotoXY(posX + 42, posY - 1); cout << "M";

		gotoXY(posX + 42, posY); cout << "M";
		gotoXY(posX + 42, posY + 1); cout << "M";
		gotoXY(posX + 42, posY + 2); cout << "M";
		gotoXY(posX + 42, posY + 3); cout << "M";
		gotoXY(posX + 42, posY + 4); cout << "M";
		gotoXY(posX + 42, posY + 5); cout << "V";
	};

	Sleep(20);
	//print 'space': posX=108,posY=27;
	{
		gotoXY(posX + 48, posY + 2); cout << "<";
		gotoXY(posX + 49, posY + 2); cout << "[";
		gotoXY(posX + 50, posY + 2); cout << "]";
		gotoXY(posX + 51, posY + 2); cout << ">";
	};

	Sleep(20);
	//print 'D': posX=114, posY=30;
	{
		gotoXY(posX + 54, posY + 5); cout << "V";
		gotoXY(posX + 54, posY + 4); cout << "M";
		gotoXY(posX + 54, posY + 3); cout << "M";
		gotoXY(posX + 54, posY + 2); cout << "M";
		gotoXY(posX + 54, posY + 1); cout << "M";
		gotoXY(posX + 54, posY); cout << "M";
		gotoXY(posX + 54, posY - 1); cout << "M";

		gotoXY(posX + 55, posY - 1); cout << "M";
		gotoXY(posX + 56, posY - 1); cout << "M";

		gotoXY(posX + 57, posY); cout << "M";
		gotoXY(posX + 57, posY + 1); cout << "M";
		gotoXY(posX + 57, posY + 2); cout << "M";
		gotoXY(posX + 57, posY + 3); cout << "M";
		gotoXY(posX + 57, posY + 4); cout << "M";

		gotoXY(posX + 56, posY + 5); cout << "M";
		gotoXY(posX + 55, posY + 5); cout << "<";
	}

	Sleep(20);
	//print 'E': posX=123, posY=24;
	{
		gotoXY(posX + 63, posY - 1); cout << ">";
		gotoXY(posX + 62, posY - 1); cout << "M";
		gotoXY(posX + 61, posY - 1); cout << "M";
		gotoXY(posX + 60, posY - 1); cout << "M";

		gotoXY(posX + 60, posY); cout << "M";
		gotoXY(posX + 60, posY + 1); cout << "M";
		gotoXY(posX + 60, posY + 2); cout << "M";
		gotoXY(posX + 60, posY + 3); cout << "M";
		gotoXY(posX + 60, posY + 4); cout << "M";
		gotoXY(posX + 60, posY + 5); cout << "M";

		gotoXY(posX + 61, posY + 5); cout << "M";
		gotoXY(posX + 62, posY + 5); cout << "M";
		gotoXY(posX + 63, posY + 5); cout << ">";

		gotoXY(posX + 60, posY + 2); cout << "M";
		gotoXY(posX + 62, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'F': posX=129,posY=24;
	{
		gotoXY(posX + 69, posY - 1); cout << ">";
		gotoXY(posX + 68, posY - 1); cout << "M";
		gotoXY(posX + 67, posY - 1); cout << "M";
		gotoXY(posX + 66, posY - 1); cout << "M";

		gotoXY(posX + 66, posY); cout << "M";
		gotoXY(posX + 66, posY + 1); cout << "M";
		gotoXY(posX + 66, posY + 2); cout << "M";
		gotoXY(posX + 66, posY + 3); cout << "M";
		gotoXY(posX + 66, posY + 4); cout << "M";
		gotoXY(posX + 66, posY + 5); cout << "M";

		gotoXY(posX + 67, posY + 2); cout << "M";
		gotoXY(posX + 68, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'E': posX=135, posY=24;
	{
		gotoXY(posX + 75, posY - 1); cout << ">";
		gotoXY(posX + 74, posY - 1); cout << "M";
		gotoXY(posX + 73, posY - 1); cout << "M";
		gotoXY(posX + 72, posY - 1); cout << "M";

		gotoXY(posX + 72, posY); cout << "M";
		gotoXY(posX + 72, posY + 1); cout << "M";
		gotoXY(posX + 72, posY + 2); cout << "M";
		gotoXY(posX + 72, posY + 3); cout << "M";
		gotoXY(posX + 72, posY + 4); cout << "M";
		gotoXY(posX + 72, posY + 5); cout << "M";

		gotoXY(posX + 73, posY + 5); cout << "M";
		gotoXY(posX + 74, posY + 5); cout << "M";
		gotoXY(posX + 75, posY + 5); cout << ">";

		gotoXY(posX + 73, posY + 2); cout << "M";
		gotoXY(posX + 75, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'N': posX=138, posY=30
	{
		gotoXY(posX + 78, posY + 5); cout << "V";
		gotoXY(posX + 78, posY + 4); cout << "M";
		gotoXY(posX + 78, posY + 3); cout << "M";
		gotoXY(posX + 78, posY + 2); cout << "M";
		gotoXY(posX + 78, posY + 1); cout << "M";
		gotoXY(posX + 78, posY); cout << "M";
		gotoXY(posX + 78, posY - 1); cout << "A";

		gotoXY(posX + 79, posY + 1); cout << "M";
		gotoXY(posX + 80, posY + 2); cout << "M";

		gotoXY(posX + 81, posY - 1); cout << "A";
		gotoXY(posX + 81, posY); cout << "M";
		gotoXY(posX + 81, posY + 1); cout << "M";
		gotoXY(posX + 81, posY + 2); cout << "M";
		gotoXY(posX + 81, posY + 3); cout << "M";
		gotoXY(posX + 81, posY + 4); cout << "M";
		gotoXY(posX + 81, posY + 5); cout << "M";
	}

	Sleep(20);
	//print 'D': posX=144, posY=30;
	{
		gotoXY(posX + 84, posY + 5); cout << "V";
		gotoXY(posX + 84, posY + 4); cout << "M";
		gotoXY(posX + 84, posY + 3); cout << "M";
		gotoXY(posX + 84, posY + 2); cout << "M";
		gotoXY(posX + 84, posY + 1); cout << "M";
		gotoXY(posX + 84, posY); cout << "M";
		gotoXY(posX + 84, posY - 1); cout << "M";

		gotoXY(posX + 85, posY - 1); cout << "M";
		gotoXY(posX + 86, posY - 1); cout << "M";

		gotoXY(posX + 87, posY); cout << "M";
		gotoXY(posX + 87, posY + 1); cout << "M";
		gotoXY(posX + 87, posY + 2); cout << "M";
		gotoXY(posX + 87, posY + 3); cout << "M";
		gotoXY(posX + 87, posY + 4); cout << "M";

		gotoXY(posX + 86, posY + 5); cout << "M";
		gotoXY(posX + 85, posY + 5); cout << "<";
	}

	Sleep(20);
	//print 'E': posX=153, posY=24;
	{
		gotoXY(posX + 93, posY - 1); cout << ">";
		gotoXY(posX + 92, posY - 1); cout << "M";
		gotoXY(posX + 91, posY - 1); cout << "M";
		gotoXY(posX + 90, posY - 1); cout << "M";

		gotoXY(posX + 90, posY); cout << "M";
		gotoXY(posX + 90, posY + 1); cout << "M";
		gotoXY(posX + 90, posY + 2); cout << "M";
		gotoXY(posX + 90, posY + 3); cout << "M";
		gotoXY(posX + 90, posY + 4); cout << "M";
		gotoXY(posX + 90, posY + 5); cout << "M";

		gotoXY(posX + 91, posY + 5); cout << "M";
		gotoXY(posX + 92, posY + 5); cout << "M";
		gotoXY(posX + 93, posY + 5); cout << ">";

		gotoXY(posX + 91, posY + 2); cout << "M";
		gotoXY(posX + 92, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'R': posX=156, posY=30;
	{
		gotoXY(posX + 96, posY + 5); cout << "V";
		gotoXY(posX + 96, posY + 4); cout << "M";
		gotoXY(posX + 96, posY + 3); cout << "M";
		gotoXY(posX + 96, posY + 2); cout << "M";
		gotoXY(posX + 96, posY + 1); cout << "M";
		gotoXY(posX + 96, posY); cout << "M";
		gotoXY(posX + 96, posY - 1); cout << "M";

		gotoXY(posX + 97, posY - 1); cout << "M";
		gotoXY(posX + 98, posY - 1); cout << "M";

		gotoXY(posX + 99, posY); cout << "M";
		gotoXY(posX + 99, posY + 1); cout << "M";

		gotoXY(posX + 98, posY + 2); cout << "M";
		gotoXY(posX + 97, posY + 2); cout << "M";

		gotoXY(posX + 99, posY + 3); cout << "M";
		gotoXY(posX + 99, posY + 4); cout << "M";
		gotoXY(posX + 99, posY + 5); cout << "V";
	}
}