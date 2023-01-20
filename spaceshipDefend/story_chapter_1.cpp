#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;
void effectText_char(int printSpeed, string str);
void story_chapter_1(int printSpeed) {
	system("cls");
	cout << "[ *** NHAT KY CHUYEN BAY *** ]" << endl;
	vector<string>para = { "[ K2 - Aircraft Carrier KP2 - 8:00AM - 25/08/2506]",
		"[ VN-34U25-8A, day la bo phan khong luu, nghe ro tra loi! ]",
		"[ VN-34U25-8A, nghe ro, xin chi thi! ]" ,
		"[ Khong luu nghe ro, VN-34U25-8A, qua duong bang so 2, yeu cau kiem tra toan phan! ]" ,
		"[ VN-34U25-8A xac nhan ]",
		"[ Nhu thuong le, co truong Anh kiem tra cac muc co ban truoc:",
		"[ Nang luong: ??? % ]",
		"[ He thong lai tu dong: tra ve CRF-?? ]",
		"[ He thong phong thu: 48 - 55 - 67 - N ]",
		"[ Duong khi: F ]",
		"[ 10 phut troi qua ]",
		"[ VN-34U25-8A san sang cat canh ] ",
		"[ VN-34U25-8A, CAT CANH!!! ] "};
	
	for (int i = 0; i < para.size(); i++)
	{
		effectText_char(printSpeed, para[i]);
		if (i == 0 || i == 4 || i == 9 || i == 10)
		{
			cout << endl;
			Sleep(500);
		};
	};
	cout << endl;
	Sleep(1000);
	system("pause");
}