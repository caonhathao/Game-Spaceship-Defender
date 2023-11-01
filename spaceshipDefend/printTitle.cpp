#include<iostream>
#include"functions_control_console.h"
using std::cout;
void printTitle(int posX, int posY, int colorCode) {

	//posX=60, posY=25: default value
	setColor(0, colorCode);

	//print 'S' :posX=60, posY=25
	{
		go_to_xy(posX, posY); cout << "V";
		

		go_to_xy(posX - 1, posY - 1); cout << "M";
		go_to_xy(posX - 2, posY - 1); cout << "M";
		

		go_to_xy(posX - 3, posY); cout << "M";
		go_to_xy(posX - 3, posY + 1); cout << "M";

		
		go_to_xy(posX - 2, posY + 2); cout << "M";
		go_to_xy(posX - 1, posY + 2); cout << "M";
		

		go_to_xy(posX, posY + 3); cout << "M";
		go_to_xy(posX, posY + 4); cout << "M";
		

		go_to_xy(posX - 1, posY + 5); cout << "M";
		go_to_xy(posX - 2, posY + 5); cout << "M";
		

		go_to_xy(posX - 3, posY + 4); cout << "A";
	}
	Sleep(20);

	//print 'P' :posX=64, posY=27
	{
		go_to_xy(posX + 4, posY + 2); cout << "M";
		go_to_xy(posX + 5, posY + 2); cout << "M";
		//go_to_xy(posX + 6, posY + 2); cout << "M";

		go_to_xy(posX + 6, posY + 1); cout << "M";
		go_to_xy(posX + 6, posY); cout << "M";
		//go_to_xy(posX + 6, posY - 1); cout << "M";

		go_to_xy(posX + 5, posY - 1); cout << "M";
		go_to_xy(posX + 4, posY - 1); cout << "M";
		//go_to_xy(posX + 3, posY - 1); cout << "M";

		go_to_xy(posX + 3, posY); cout << "M";
		go_to_xy(posX + 3, posY + 1); cout << "M";
		go_to_xy(posX + 3, posY + 2); cout << "M";
		go_to_xy(posX + 3, posY + 3); cout << "M";
		go_to_xy(posX + 3, posY + 4); cout << "M";
		go_to_xy(posX + 3, posY + 5); cout << "V";
	}

	Sleep(20);
	//print 'A' :posX=69, posY=30
	{
		go_to_xy(posX + 9, posY + 5); cout << "V";
		go_to_xy(posX + 9, posY + 4); cout << "M";
		go_to_xy(posX + 9, posY + 3); cout << "M";
		go_to_xy(posX + 9, posY + 2); cout << "M";
		go_to_xy(posX + 9, posY + 1); cout << "M";
		go_to_xy(posX + 9, posY); cout << "M";

		go_to_xy(posX + 10, posY - 1); cout << "M";
		go_to_xy(posX + 11, posY - 1); cout << "M";

		go_to_xy(posX + 12, posY); cout << "M";
		go_to_xy(posX + 12, posY + 1); cout << "M";
		go_to_xy(posX + 12, posY + 2); cout << "M";
		go_to_xy(posX + 12, posY + 3); cout << "M";
		go_to_xy(posX + 12, posY + 4); cout << "M";
		go_to_xy(posX + 12, posY + 5); cout << "V";

		go_to_xy(posX + 10, posY + 2); cout << "M";
		go_to_xy(posX + 11, posY + 2); cout << "M";
	};

	Sleep(20);
	//print 'C' :posX=78, posY=26
	{
		go_to_xy(posX + 18, posY + 1); cout << "V";
		go_to_xy(posX + 18, posY); cout << "M";
		
		go_to_xy(posX + 17, posY - 1); cout << "M";
		go_to_xy(posX + 16, posY - 1); cout << "M";
		
		go_to_xy(posX + 15, posY); cout << "M";
		go_to_xy(posX + 15, posY + 1); cout << "M";
		go_to_xy(posX + 15, posY + 2); cout << "M";
		go_to_xy(posX + 15, posY + 3); cout << "M";
		go_to_xy(posX + 15, posY + 4); cout << "M";
		
		go_to_xy(posX + 16, posY + 5); cout << "M";
		go_to_xy(posX + 17, posY + 5); cout << "M";
		
		go_to_xy(posX + 18, posY + 4); cout << "M";
		go_to_xy(posX + 18, posY + 3); cout << "A";
	}

	Sleep(20);
	//print 'E' :posX=84, posY=24
	{
		go_to_xy(posX + 24, posY - 1); cout << ">";
		go_to_xy(posX + 23, posY - 1); cout << "M";
		go_to_xy(posX + 22, posY - 1); cout << "M";
		//go_to_xy(posX + 21, posY - 1); cout << "M";

		go_to_xy(posX + 21, posY); cout << "M";
		go_to_xy(posX + 21, posY + 1); cout << "M";
		go_to_xy(posX + 21, posY + 2); cout << "M";
		go_to_xy(posX + 21, posY + 3); cout << "M";
		go_to_xy(posX + 21, posY + 4); cout << "M";
		//go_to_xy(posX + 21, posY + 5); cout << "M";

		go_to_xy(posX + 22, posY + 5); cout << "M";
		go_to_xy(posX + 23, posY + 5); cout << "M";
		go_to_xy(posX + 24, posY + 5); cout << ">";

		go_to_xy(posX + 22, posY + 2); cout << "M";
		go_to_xy(posX + 23, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'S' :posX=90; posY=25
	{
		go_to_xy(posX + 30, posY); cout << "V";
		//go_to_xy(posX + 30, posY - 1); cout << "M";

		go_to_xy(posX + 29, posY - 1); cout << "M";
		go_to_xy(posX + 28, posY - 1); cout << "M";
		//go_to_xy(posX + 27, posY - 1); cout << "M";

		go_to_xy(posX + 27, posY); cout << "M";
		go_to_xy(posX + 27, posY + 1); cout << "M";
		//go_to_xy(posX + 27, posY + 2); cout << "M";

		go_to_xy(posX + 28, posY + 2); cout << "M";
		go_to_xy(posX + 29, posY + 2); cout << "M";
		//go_to_xy(posX + 30, posY + 2); cout << "M";

		go_to_xy(posX + 30, posY + 3); cout << "M";
		go_to_xy(posX + 30, posY + 4); cout << "M";
		//go_to_xy(posX + 30, posY + 5); cout << "M";

		go_to_xy(posX + 29, posY + 5); cout << "M";
		go_to_xy(posX + 28, posY + 5); cout << "M";
		//go_to_xy(posX + 27, posY + 5); cout << "M";

		go_to_xy(posX + 27, posY + 4); cout << "A";
	}

	Sleep(20);
	//print 'H': posX=93, posY=24;
	{
		go_to_xy(posX + 33, posY - 1); cout << "A";
		go_to_xy(posX + 33, posY); cout << "M";
		go_to_xy(posX + 33, posY + 1); cout << "M";
		go_to_xy(posX + 33, posY + 2); cout << "M";
		go_to_xy(posX + 33, posY + 3); cout << "M";
		go_to_xy(posX + 33, posY + 4); cout << "M";
		go_to_xy(posX + 33, posY + 5); cout << "V";

		go_to_xy(posX + 36, posY - 1); cout << "A";
		go_to_xy(posX + 36, posY); cout << "M";
		go_to_xy(posX + 36, posY + 1); cout << "M";
		go_to_xy(posX + 36, posY + 2); cout << "M";
		go_to_xy(posX + 36, posY + 3); cout << "M";
		go_to_xy(posX + 36, posY + 4); cout << "M";
		go_to_xy(posX + 36, posY + 5); cout << "V";

		go_to_xy(posX + 34, posY + 2); cout << "M";
		go_to_xy(posX + 35, posY + 2); cout << "M";
		go_to_xy(posX + 36, posY + 2); cout << "M";
	}

	Sleep(20);
	//print 'I': posX=99, posY=24;
	{
		go_to_xy(posX + 39, posY - 1); cout << "O";
		go_to_xy(posX + 39, posY); cout << "M";
		go_to_xy(posX + 39, posY + 1); cout << "M";
		go_to_xy(posX + 39, posY + 2); cout << "M";
		go_to_xy(posX + 39, posY + 3); cout << "M";
		go_to_xy(posX + 39, posY + 4); cout << "M";
		go_to_xy(posX + 39, posY + 5); cout << "V";
	}

	Sleep(20);
	//print 'P': posX=103, posY=27;
	{
		go_to_xy(posX + 43, posY + 2); cout << "M";
		go_to_xy(posX + 44, posY + 2); cout << "M";
		//go_to_xy(posX + 45, posY + 2); cout << "M";

		go_to_xy(posX + 45, posY + 1); cout << "M";
		go_to_xy(posX + 45, posY); cout << "M";
		//go_to_xy(posX + 45, posY - 1); cout << "M";

		go_to_xy(posX + 44, posY - 1); cout << "M";
		go_to_xy(posX + 43, posY - 1); cout << "M";
		//go_to_xy(posX + 42, posY - 1); cout << "M";

		go_to_xy(posX + 42, posY); cout << "M";
		go_to_xy(posX + 42, posY + 1); cout << "M";
		go_to_xy(posX + 42, posY + 2); cout << "M";
		go_to_xy(posX + 42, posY + 3); cout << "M";
		go_to_xy(posX + 42, posY + 4); cout << "M";
		go_to_xy(posX + 42, posY + 5); cout << "V";
	};

	Sleep(20);
	//print 'space': posX=108,posY=27;
	{
		go_to_xy(posX + 48, posY + 2); cout << "<";
		go_to_xy(posX + 49, posY + 2); cout << "[";
		go_to_xy(posX + 50, posY + 2); cout << "]";
		go_to_xy(posX + 51, posY + 2); cout << ">";
	};

	Sleep(20);
	//print 'D': posX=114, posY=30;
	{
		go_to_xy(posX + 54, posY + 5); cout << "V";
		go_to_xy(posX + 54, posY + 4); cout << "M";
		go_to_xy(posX + 54, posY + 3); cout << "M";
		go_to_xy(posX + 54, posY + 2); cout << "M";
		go_to_xy(posX + 54, posY + 1); cout << "M";
		go_to_xy(posX + 54, posY); cout << "M";
		go_to_xy(posX + 54, posY - 1); cout << "M";

		go_to_xy(posX + 55, posY - 1); cout << "M";
		go_to_xy(posX + 56, posY - 1); cout << "M";

		go_to_xy(posX + 57, posY); cout << "M";
		go_to_xy(posX + 57, posY + 1); cout << "M";
		go_to_xy(posX + 57, posY + 2); cout << "M";
		go_to_xy(posX + 57, posY + 3); cout << "M";
		go_to_xy(posX + 57, posY + 4); cout << "M";

		go_to_xy(posX + 56, posY + 5); cout << "M";
		go_to_xy(posX + 55, posY + 5); cout << "<";
	}

	Sleep(20);
	//print 'E': posX=123, posY=24;
	{
		go_to_xy(posX + 63, posY - 1); cout << ">";
		go_to_xy(posX + 62, posY - 1); cout << "M";
		go_to_xy(posX + 61, posY - 1); cout << "M";
		//go_to_xy(posX + 60, posY - 1); cout << "M";

		go_to_xy(posX + 60, posY); cout << "M";
		go_to_xy(posX + 60, posY + 1); cout << "M";
		go_to_xy(posX + 60, posY + 2); cout << "M";
		go_to_xy(posX + 60, posY + 3); cout << "M";
		go_to_xy(posX + 60, posY + 4); cout << "M";
		//go_to_xy(posX + 60, posY + 5); cout << "M";

		go_to_xy(posX + 61, posY + 5); cout << "M";
		go_to_xy(posX + 62, posY + 5); cout << "M";
		go_to_xy(posX + 63, posY + 5); cout << ">";

		go_to_xy(posX + 60, posY + 2); cout << "M";
		go_to_xy(posX + 61, posY + 2); cout << "M";
		go_to_xy(posX + 62, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'F': posX=129,posY=24;
	{
		go_to_xy(posX + 69, posY - 1); cout << ">";
		go_to_xy(posX + 68, posY - 1); cout << "M";
		go_to_xy(posX + 67, posY - 1); cout << "M";
		//go_to_xy(posX + 66, posY - 1); cout << "M";

		go_to_xy(posX + 66, posY); cout << "M";
		go_to_xy(posX + 66, posY + 1); cout << "M";
		go_to_xy(posX + 66, posY + 2); cout << "M";
		go_to_xy(posX + 66, posY + 3); cout << "M";
		go_to_xy(posX + 66, posY + 4); cout << "M";
		go_to_xy(posX + 66, posY + 5); cout << "M";

		go_to_xy(posX + 67, posY + 2); cout << "M";
		go_to_xy(posX + 68, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'E': posX=135, posY=24;
	{
		go_to_xy(posX + 75, posY - 1); cout << ">";
		go_to_xy(posX + 74, posY - 1); cout << "M";
		go_to_xy(posX + 73, posY - 1); cout << "M";
		//go_to_xy(posX + 72, posY - 1); cout << "M";

		go_to_xy(posX + 72, posY); cout << "M";
		go_to_xy(posX + 72, posY + 1); cout << "M";
		go_to_xy(posX + 72, posY + 2); cout << "M";
		go_to_xy(posX + 72, posY + 3); cout << "M";
		go_to_xy(posX + 72, posY + 4); cout << "M";
		//go_to_xy(posX + 72, posY + 5); cout << "M";

		go_to_xy(posX + 73, posY + 5); cout << "M";
		go_to_xy(posX + 74, posY + 5); cout << "M";
		go_to_xy(posX + 75, posY + 5); cout << ">";

		go_to_xy(posX + 73, posY + 2); cout << "M";
		go_to_xy(posX + 75, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'N': posX=138, posY=30
	{
		go_to_xy(posX + 78, posY + 5); cout << "V";
		go_to_xy(posX + 78, posY + 4); cout << "M";
		go_to_xy(posX + 78, posY + 3); cout << "M";
		go_to_xy(posX + 78, posY + 2); cout << "M";
		go_to_xy(posX + 78, posY + 1); cout << "M";
		go_to_xy(posX + 78, posY); cout << "M";
		go_to_xy(posX + 78, posY - 1); cout << "A";

		go_to_xy(posX + 79, posY + 1); cout << "~";
		go_to_xy(posX + 80, posY + 2); cout << "~";

		go_to_xy(posX + 81, posY - 1); cout << "A";
		go_to_xy(posX + 81, posY); cout << "M";
		go_to_xy(posX + 81, posY + 1); cout << "M";
		go_to_xy(posX + 81, posY + 2); cout << "M";
		go_to_xy(posX + 81, posY + 3); cout << "M";
		go_to_xy(posX + 81, posY + 4); cout << "M";
		go_to_xy(posX + 81, posY + 5); cout << "M";
	}

	Sleep(20);
	//print 'D': posX=144, posY=30;
	{
		go_to_xy(posX + 84, posY + 5); cout << "V";
		go_to_xy(posX + 84, posY + 4); cout << "M";
		go_to_xy(posX + 84, posY + 3); cout << "M";
		go_to_xy(posX + 84, posY + 2); cout << "M";
		go_to_xy(posX + 84, posY + 1); cout << "M";
		go_to_xy(posX + 84, posY); cout << "M";
		go_to_xy(posX + 84, posY - 1); cout << "M";

		go_to_xy(posX + 85, posY - 1); cout << "M";
		go_to_xy(posX + 86, posY - 1); cout << "M";

		go_to_xy(posX + 87, posY); cout << "M";
		go_to_xy(posX + 87, posY + 1); cout << "M";
		go_to_xy(posX + 87, posY + 2); cout << "M";
		go_to_xy(posX + 87, posY + 3); cout << "M";
		go_to_xy(posX + 87, posY + 4); cout << "M";

		go_to_xy(posX + 86, posY + 5); cout << "M";
		go_to_xy(posX + 85, posY + 5); cout << "<";
	}

	Sleep(20);
	//print 'E': posX=153, posY=24;
	{
		go_to_xy(posX + 93, posY - 1); cout << ">";
		go_to_xy(posX + 92, posY - 1); cout << "M";
		go_to_xy(posX + 91, posY - 1); cout << "M";
		//go_to_xy(posX + 90, posY - 1); cout << "M";

		go_to_xy(posX + 90, posY); cout << "M";
		go_to_xy(posX + 90, posY + 1); cout << "M";
		go_to_xy(posX + 90, posY + 2); cout << "M";
		go_to_xy(posX + 90, posY + 3); cout << "M";
		go_to_xy(posX + 90, posY + 4); cout << "M";
		//go_to_xy(posX + 90, posY + 5); cout << "M";

		go_to_xy(posX + 91, posY + 5); cout << "M";
		go_to_xy(posX + 92, posY + 5); cout << "M";
		go_to_xy(posX + 93, posY + 5); cout << ">";

		go_to_xy(posX + 91, posY + 2); cout << "M";
		go_to_xy(posX + 92, posY + 2); cout << ">";
	}

	Sleep(20);
	//print 'R': posX=156, posY=30;
	{
		go_to_xy(posX + 96, posY + 5); cout << "V";
		go_to_xy(posX + 96, posY + 4); cout << "M";
		go_to_xy(posX + 96, posY + 3); cout << "M";
		go_to_xy(posX + 96, posY + 2); cout << "M";
		go_to_xy(posX + 96, posY + 1); cout << "M";
		go_to_xy(posX + 96, posY); cout << "M";
		//go_to_xy(posX + 96, posY - 1); cout << "M";

		go_to_xy(posX + 97, posY - 1); cout << "M";
		go_to_xy(posX + 98, posY - 1); cout << "M";

		go_to_xy(posX + 99, posY); cout << "M";
		go_to_xy(posX + 99, posY + 1); cout << "M";

		go_to_xy(posX + 98, posY + 2); cout << "M";
		go_to_xy(posX + 97, posY + 2); cout << "M";

		go_to_xy(posX + 99, posY + 3); cout << "M";
		go_to_xy(posX + 99, posY + 4); cout << "M";
		go_to_xy(posX + 99, posY + 5); cout << "V";
	}
}