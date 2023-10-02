#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
using std::string;
class PLAYER {
private:
	int m_life{};
	int m_power{};
	string m_objectP{};
	string m_bullet{};
public:
	PLAYER() {};
	PLAYER(int life, int power, string objectP, string bullet);
	void setPlayer(int life, int power, string objectP, string bullet);

	int getLife();
	int getPower();
	string getObjectP();
	string getBullet();
};
#endif // !PLAYER_H

