#include<iostream>
#include<vector>
#include<conio.h>

#include"effects.h"
#include"functions_control_console.h"
#include"variable.h"

void about_me(int printSpeed) {
	system("cls");

	drawBorder(50, 10, 15, 100, 2);

	vector<string>para = { 
	"[ Tac Gia: CAO NHAT HAO. ]",
	"[ Kich Ban Game: CAO NHAT HAO. ]",
	"[ Thiet Ke: CAO NHAT HAO. ]",
	"[ Chiu Trach Nhiem San Xuat: CAO NHAT HAO. ]",
	"[ Giam Sat Du An: CAO NHAT HAO ]",
	"[ Nam Khoi Dong Du An: 2022. ]" ,
	"[ Phien Ban Hien Tai: 0.0.0.1"
	};

	for (int i = 0; i < para.size(); i++)
	{
		atXY(50 + 50 - int(para[i].size()/2), 15 + i);
		effectText_word(para[i], printSpeed);
	}

	stringFlicker("Press 'r' to back the menu", 'r', 50 + 50 - 13, 27, 3, 6);
}