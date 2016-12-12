#pragma once
#include "Attribute.h"
class Dark: public Attribute
{
private:
	double damage;
	double useMP;
public:
	Dark();
	virtual void setAttackP();
	double getDamage();
	double getUseMp();
	~Dark();
};