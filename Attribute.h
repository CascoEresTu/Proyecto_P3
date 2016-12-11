//Atributos para losa ataques
#pragma once
class Attribute
{
protected:
	int attackProbability;
public:
	Attribute();
	virtual void setAttackP()=0;
	~Attribute();
	
};