#pragma once
#include "Attribute.h"

class Physical: public Attribute
{
private:
	double damage;
	double useMP;
public:
	Physical();
	virtual void setAttackP();
	double getUseMP();
	double getDamage();
	virtual ~Physical();
	
};