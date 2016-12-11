#pragma once
#include "Attribute.h"

class Stealth:public Attribute
{
private:
	double steal;
	double useMP;
public:
	Stealth();
	virtual void setAttackP();
	void stealHP(double);
	double getSteal();
	double getUseMP();
	~Stealth();
	
};