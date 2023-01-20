#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;
void effectText_char(int printSpeed, string str);
void story_chapter_2(int printSpeed) {
	system("cls");
	cout << "[*** NHAT KY HANH TRINH ***]";
	vector<string>para = {"[ Xin chao, toi la Haruto, thuyen truong cua tau VN-34U25-8A ]",
	"[ Luc nay la 8:00PM, chung toi dang nghi chan o hanh tinh WT-256F de nghi ngoi va bao tri dong co ]",
	"[ Phi hanh doan chung toi gom 25 nguoi thuoc To 5 trinh sat cua tap doan quan Herrscher 3 ]",
	"[ Nhiem vu lan nay se dien ra trong khoan thoi gian kha dai... ]",
	"[ A quen, chung toi hien dang cach KP2 khoang 1/6 nam anh sang."};

	for (int i = 0; i < para.size(); i++)
	{
		effectText_char(printSpeed, para[i]);
		if (i==0||i==2||i==3)
		{
			cout << endl;
			Sleep(500);
		}
	}
	cout << endl;
	Sleep(1000);
	system("pause");
}