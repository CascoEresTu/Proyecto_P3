#include "Light.h"
#include "Attribute.h"
#include <stdlib.h>

Light::Light(){
	heal = 25;
	useMP = 10;
}

void Light::setAttackP(){
	attackProbability = 10;
}

double Light::getHeal(){
	return heal;
}

double Light::getUseMP(){
	return useMP;
}

Light::~Light(){
	heal=0;
	useMP = 0;
}