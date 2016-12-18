#pragma once
#include "Person.h"
#include "Attribute.h"
#include "Physical.h"
#include <string>
using std::string;

class Melee: public Person
{
private:
	Physical* special;
	string type;
public:
	Melee(string, double, double, double, double, double, double, double);
	Melee(string, double, double);
	Melee();
	virtual ~Melee();
	virtual double damage();
};
