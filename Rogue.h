#pragma once
#include "Person.h"
#include "Attribute.h"
#include "Stealth.h"
#include <string>
using std::string;

class Rogue: public Person
{
private:
	Stealth* steal;
	string type = "Stealth";
public:
	Rogue(tring, double, double, double, double, double, double, double);
	Rogue();
	virtual ~Rogue();
	virtual double damage();
	
};