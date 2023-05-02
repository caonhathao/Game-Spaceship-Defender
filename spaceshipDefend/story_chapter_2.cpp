#include<iostream>
#include<Windows.h>
#include<vector>
#include<conio.h>

#include"effects_text.h"
#include"variable.h"
#include"functions_control_console.h"

using namespace std;
void story_chapter_2(int printSpeed) {
	system("cls");
	string p = "[ Dang khoi dong chuong 2 ]";
	effectText_char(p, 20);
	Sleep(1500);
	system("cls");

	setColor(0, 2);
	cout << "[*** NHAT KY HANH TRINH ***]" << endl;
	setColor(0, 6);
	vector<string>para = {"[ Xin chao, toi la Haruto, thuyen truong cua tau VN-34U25-8A ]",
	"[ Luc nay la 8:00PM, chung toi dang nghi chan o hanh tinh WT-256F de nghi ngoi va bao tri dong co ]",
	"[ Phi hanh doan chung toi gom 25 nguoi thuoc To 5 trinh sat cua tap doan quan Herrscher 3 ]",
	"[ Nhiem vu lan nay se dien ra trong khoan thoi gian kha dai... ]",
	"[ A quen, chung toi se tien hanh don duong, boi chung toi dang di ngang qua vanh dai cua MK-26f gom rat nhieu tieu hanh tinh. ]"};

	for (int i = 0; i < para.size(); i++)
	{
		effectText_char(para[i], printSpeed);
		if (i == 0 || i == 2 || i == 3)
		{
			cout << endl;
			Sleep(500);
		}
	};
	cout << endl;
	Sleep(1000);

	stringFlicker("[ Press 'r' to continue ]", 95, 11, 2, 4);
	//setColor(0, 4);
	//cout << "[ Press 'r' to continue ! ]";
	//*c = ' ';
	//while (*c != 'r')
	//{
	//	if (_kbhit()) {
	//		*c = _getch();
	//		*c = tolower(*c);
	//	}
	//};
	system("cls");

}