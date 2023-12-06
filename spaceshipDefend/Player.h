#pragma once
#ifndef Player_H
#define Player_H
#include<iostream>
using std::string;
class Player {
private:
	int m_life{};
	int m_power{};
	string m_objectP{};
	string m_bullet{};
public:
	Player() {};
	Player(int life, int power, string objectP, string bullet);
	void setPlayer(int life, int power, string objectP, string bullet);

	int getLife();
	int getPower();
	string getObjectP();
	string getBullet();
};
#endif // !Player_H

