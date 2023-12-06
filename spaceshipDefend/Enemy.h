#pragma once
#ifndef Enemy_H
#define Enemy_H

#include<iostream>
using std::string;

class Enemy {
private:
	int m_rateAppear{};
	int m_rewardPoint{};
	int m_minusPoint{};
	string m_objectE{};
public:
	Enemy(int rateAppear, int rewardPpoint, int minusPoint, string objectE);

	void setEnemy(int rateAppear, int rewardPoint, int minusPoint, string objectE);

	int getRateAppear();
	int getRewardPoint();
	int getMinusPoint();
	string getObjectE();
};
#endif // !Enemy_H

