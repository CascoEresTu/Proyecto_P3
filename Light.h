#pragma once
#include "Attribute.h"

class Light: public Attribute
{
private:
	double heal;
	double useMP;
public:
	Light();
	virtual void setAttackP();
	double getHeal();
	double getUseMP();
	~Light();
	
};