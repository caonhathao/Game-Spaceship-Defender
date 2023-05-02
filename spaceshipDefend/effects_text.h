#pragma once
#ifndef _EFFECTS_TEXT_H

#define _EFFECTS_TEXT_H

#include<iostream>
#include<string>
#include<Windows.h>
#pragma once
using namespace std;
void effectText_char(string str, int printSpeed);
void effectText_word(string str, int printSpeed);
string uppercaseLetter(string name);
void stringFlicker(string str, int posX, int posY, int colorCode_1, int colorCode_2);
#endif
