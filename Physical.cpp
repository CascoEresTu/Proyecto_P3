#include "Physical.h"
#include "Attribute.h"
#include <stdlib.h>
Physical::Physical(){
	damage = 50;
	useMP = 10;
}
void Physical::setAttackP(){
	attackProbability = rand()%10 + 1;
	if (attackProbability >= 4)
	{
		damage = 50;
	}else{
		damage = 0;
	}
}
Physical::~Physical(){
	damage = 0;
	useMP = 0;
}
double Physical::getDamage(){
	return damage;
}
double Physical::getUseMP(){
	return useMP;
}