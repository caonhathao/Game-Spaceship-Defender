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
	char m_bullet;
public:
	PLAYER(int life, int power, string objectP, char bullet);
	void setPlayer(int life, int power, string objectP, char bullet);

	int getLife() {
		return m_life;
	}
	int getPower() {
		return m_power;
	}
	string getObjectP() {
		return m_objectP;
	}
	char getBullet() {
		return m_bullet;
	}
};
#endif // !PLAYER_H

