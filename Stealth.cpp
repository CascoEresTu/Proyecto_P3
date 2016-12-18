#include "Stealth.h"
#include "Attribute.h"
#include <stdlib.h>

Stealth::Stealth(){
	steal = 0;
	useMP = 10;
}

void Stealth::setAttackP(){
	attackProbability = rand()%10 + 1;
}
double Stealth::stealHP(double life){
	if(attackProbability >= 3){
		steal = (life* 0.2);
	}else{
		steal = 5;
	}
	return steal;
}
double Stealth::getSteal(){
	return steal;
} 
double Stealth::getUseMP(){
	return useMP;
}
Stealth::~Stealth(){
	steal = 0;
	useMP = 10;
}


