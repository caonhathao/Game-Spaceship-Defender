#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include<iostream>
using namespace std;

class ENEMY {
private:
	int m_rateAppear;
	int m_rewardPoint;
	int m_minusPoint;
	string m_objectE;
public:
	ENEMY(int rateAppear, int rewardPpoint, int minusPoint, string objectE);

	void setEnemy(int rateAppear, int rewardPoint, int minusPoint, string objectE);

	int getRateAppear() { return m_rateAppear; };
	int getRewardPoint() { return m_rewardPoint; };
	int getMinusPoint() { return m_minusPoint; };
	string getObjectE() { return m_objectE; };
};
#endif // !ENEMY_H

