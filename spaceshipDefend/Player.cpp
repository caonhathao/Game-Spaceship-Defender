#include"Player.h"

PLAYER::PLAYER(int life, int power, string objectP, string bullet) {
	setPlayer(life, power, objectP, bullet);
}
void PLAYER::setPlayer(int life, int power, string objectP, string bullet) {
	this->m_life = life;
	this->m_power = power;
	this->m_objectP = objectP;
	this->m_bullet = bullet;
}
int PLAYER::getLife() {
	return m_life;
};
int PLAYER::getPower() {
	return m_power;
}
string PLAYER::getObjectP() {
	return m_objectP;
};
string PLAYER::getBullet() {
	return m_bullet;
}