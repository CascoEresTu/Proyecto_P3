#pragma once
#include "Attribute.h"

class Physical: public Attribute
{
protected:
	double damage;
	double useMP;
public:
	Physical();
	virtual void setAttackP();
	~Physical();
	
};