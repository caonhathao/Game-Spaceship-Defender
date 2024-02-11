#pragma once
#ifndef _EFFECTS_H

#define _EFFECTS_H

#include<iostream>
#include<string>
#include<Windows.h>
#include"variable.h"
#pragma once

using std::string;

void effectText_char(string str, int printSpeed);
void effectText_word(string str, int printSpeed);
void uppercaseString(string &str);
void lowercaseString(string &str);
void stringFlicker(string str,char k, int posX, int posY, int colorCode_1, int colorCode_2);
void drawBorder(int posX, int posY, int height, int width, int color_code);
#endif