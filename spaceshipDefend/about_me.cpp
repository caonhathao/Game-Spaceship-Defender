#include<iostream>
#include<vector>
#include<conio.h>

#include"effects_text.h"
#include"functions_control_console.h"
#include"variable.h"

void about_me(int printSpeed) {
	system("cls");
	vector<string>para = { "[ Tac Gia: CAO NHAT HAO. ]",
	"[ Thiet Ke: CAO NHAT HAO. ]",
	"[ Chiu Trach Nhiem San Xuat: CAO NHAT HAO. ]",
	"[ Kich Ban Game: CAO NHAT HAO. ]",
	"[ Nam Khoi Dong Du An: 2022. ]" };

	for (int i = 0; i < para.size(); i++)
	{
		atXY(15, 5 + i);
		effectText_word(para[i], printSpeed);
	}

	atXY(15, 12);
	setColor(0, 2);
	cout << "[ Press 'r' to back the menu. ]";

	*c = ' ';
	*g_count_down = 3000;

	while (true)
	{
		if (_kbhit()) {
			*c = _getch();
			*c = tolower(*c);
			if (*c == 'r')
			{
				break;
			}
		}
		if (*g_count_down == 0 || *g_count_down == 3000)
		{
			atXY(15, 12);
			setColor(0, 12);
			cout << "[ Press 'r' to back the menu. ]";
			if (*g_count_down == 0)
			{
				*g_count_down = 3000;
			}
		};

		if (*g_count_down == 1500)
		{

			setColor(0, 2);
			atXY(15, 12);
			cout << "[ Press 'r' to back the menu. ]";
		};
		(*g_count_down)--;
	}
}