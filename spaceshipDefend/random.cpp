#include<iostream>
#include<time.h>
using namespace std;
int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}