#include"Enemy.h"

ENEMY::ENEMY(int rateAppear, int rewardPoint, int minusPoint, string objectE) {
	setEnemy(rateAppear, rewardPoint, minusPoint, objectE);
}

void ENEMY::setEnemy(int rateAppear, int rewardPoint, int minusPoint, string objectE) {
	this->m_rateAppear = rateAppear;
	this->m_rewardPoint = rewardPoint;
	this->m_minusPoint = minusPoint;
	this->m_objectE = objectE;
};
int ENEMY::getRateAppear() {
	return m_rateAppear;
};
int ENEMY::getRewardPoint() {
	return m_rewardPoint;
}
int ENEMY::getMinusPoint() {
	return m_minusPoint;
};
string ENEMY::getObjectE() {
	return m_objectE;
}