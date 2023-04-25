#pragma once
#ifndef PLAYER_H
#define PLAYE_H
#include<iostream>
using namespace std;
class PLAYER {
private:
	int m_life;
	int m_power;
	string m_objectP;
	string m_bullet;
public:
	PLAYER(int life, int power, string objectP, string bullet);
	void setPlayer(int life, int power, string objectP, string bullet);

	int getLife() {
		return m_life;
	}
	int getPower() {
		return m_power;
	}
	string getObjectP() {
		return m_objectP;
	}
	string getBullet() {
		return m_bullet;
	}
};
#endif // !PLAYER_H

