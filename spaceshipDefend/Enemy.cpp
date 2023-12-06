#include"Enemy.h"

Enemy::Enemy(int rateAppear, int rewardPoint, int minusPoint, string objectE) {
	setEnemy(rateAppear, rewardPoint, minusPoint, objectE);
}

void Enemy::setEnemy(int rateAppear, int rewardPoint, int minusPoint, string objectE) {
	this->m_rateAppear = rateAppear;
	this->m_rewardPoint = rewardPoint;
	this->m_minusPoint = minusPoint;
	this->m_objectE = objectE;
};
int Enemy::getRateAppear() {
	return m_rateAppear;
};
int Enemy::getRewardPoint() {
	return m_rewardPoint;
}
int Enemy::getMinusPoint() {
	return m_minusPoint;
};
string Enemy::getObjectE() {
	return m_objectE;
}