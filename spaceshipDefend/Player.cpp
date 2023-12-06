#include"Player.h"

Player::Player(int life, int power, string objectP, string bullet) {
	setPlayer(life, power, objectP, bullet);
}
void Player::setPlayer(int life, int power, string objectP, string bullet) {
	this->m_life = life;
	this->m_power = power;
	this->m_objectP = objectP;
	this->m_bullet = bullet;
}
int Player::getLife() {
	return m_life;
};
int Player::getPower() {
	return m_power;
}
string Player::getObjectP() {
	return m_objectP;
};
string Player::getBullet() {
	return m_bullet;
}