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
extern int *g_PlayerSize;
extern int* g_speed;
extern int* g_step;

//the variable below will add some units for posY (scale this frame)
extern int* addPosY;

extern char *c;

extern Position cursorPos;
extern Position PlayerPos;
extern Position EnemyPos;
extern Position bulletPos;

extern  Player *PlayerWeak;
extern Enemy *EnemyWeak;

extern Activities activities;
#endif // !_VARIABLE_H