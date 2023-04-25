//#include<iostream>
//using namespace std;
//
//class PLAYER {
//private:
//	int life;
//	int power;
//	string objectP;
//	char bullet;
//public:
//	PLAYER(int life, int power, string objectP,char bullet) {
//		this->life = life;
//		this->power = power;
//		this->objectP = objectP; 
//		this->bullet = bullet;
//	}
//
//	int getLife() {
//		return life;
//	}
//	void setLife(int life) {
//		this->life = life;
//	}
//
//	int getPower() {
//		return life;
//	}
//	void setPower(int power) {
//		this->power = power;
//	}
//
//	string getObjectP() {
//		return objectP;
//	}
//	void setObjectP(string objectP) {
//		this->objectP = objectP;
//	}
//
//	char getBullet() {
//		return bullet;
//	}
//	void setBullet(char bullet) {
//		this->bullet = bullet;
//	}
//};
#include"Player.h"

PLAYER::PLAYER(int life, int power, string objectP, string bullet) {
	setPlayer(life, power, objectP, bullet);
}
void PLAYER::setPlayer(int life, int power, string objectP, string bullet) {
	m_life = life;
	m_power = power;
	m_objectP = objectP;
	m_bullet = bullet;
}