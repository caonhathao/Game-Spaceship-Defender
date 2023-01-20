#include"Enemy.h"

/*
class ENEMY {
private:
	int rateAppear;
	int rewardPoint;
	int minusPoint;
	string objectE;
public:
	ENEMY(int rateAppear, int rewardPoint, int minusPoint,string objectE) {
		this->rateAppear = rateAppear;
		this->rewardPoint = rewardPoint;
		this->minusPoint = minusPoint;
		this->objectE = objectE;
	}
	int getRateAppear() {
		return rateAppear;
	}
	void setRateAppear(int rateAppear) {
		this->rateAppear = rateAppear;
	}
	int getRewardPoint() {
		return rewardPoint;
	}
	void setRewardPoint(int rewardPoint) {
		this->rewardPoint = rewardPoint;
	}
	int getMinusPoint() {
		return minusPoint;
	}
	void setMinusPoint(int minusPoint) {
		this->minusPoint = minusPoint;
	}
	string getObjectE() {
		return objectE;
	}
	void setObjectE(string objectE) {
		this->objectE = objectE;
	}
};
*/

ENEMY::ENEMY(int rateAppear, int rewardPoint, int minusPoint, string objectE) {
	setEnemy(rateAppear, rewardPoint, minusPoint, objectE);
}

void ENEMY::setEnemy(int rateAppear, int rewardPoint, int minusPoint, string objectE) {
	m_rateAppear = rateAppear;
	m_rewardPoint = rewardPoint;
	m_minusPoint = minusPoint;
	m_objectE = objectE;
}