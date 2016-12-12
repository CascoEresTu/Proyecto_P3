#include "Dark.h"
#include "Attribute.h"
#include <stdlib.h>

Dark::Dark(){
	damage = 50;
	useMP = 10;
}
void Dark::setAttackP(){
	attackProbability = rand()%10 + 1;
	if (attackProbability >= 4)
	{
		damage = 50;
	}else{
		damage = 0;
	}
}
double Dark::getDamage(){
	return damage;
}
double Dark::getUseMp(){
	return useMP;
}
Dark::~Dark(){
	damage = 0;
	useMP = 0;
}