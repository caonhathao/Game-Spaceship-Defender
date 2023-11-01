#pragma once
#ifndef _VARIABLE_H

#define _VARIABLE_H
#include<iostream>
#include<thread>
#include<mutex>

#include"struct.cpp"
#include"Activities.cpp"
#include"Player.h"
#include"Enemy.h"

extern int *g_printSpeed;
extern int *g_count_down;
extern int *g_choice;
extern int *g_playerSize;
extern int* g_speed;
extern int* g_step;

extern char *c;

extern Position cursorPos;
extern Position playerPos;
extern Position enemyPos;
extern Position bulletPos;

extern  PLAYER *playerWeak;
extern ENEMY *enemyWeak;

extern Activities activities;
//extern vector<infoPlayer>Data = {};
#endif // !_VARIABLE_H