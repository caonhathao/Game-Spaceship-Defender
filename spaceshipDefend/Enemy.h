#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include<iostream>
using std::string;

class ENEMY {
private:
	int m_rateAppear;
	int m_rewardPoint;
	int m_minusPoint;
	string m_objectE;
public:
	ENEMY(int rateAppear, int rewardPpoint, int minusPoint, string objectE);

	void setEnemy(int rateAppear, int rewardPoint, int minusPoint, string objectE);

	int getRateAppear();
	int getRewardPoint();
	int getMinusPoint();
	string getObjectE();
};
#endif // !ENEMY_H

