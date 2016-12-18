#pragma once
#include "Person.h"
#include "Attribute.h"
#include "Stealth.h"
#include "Boss.h"
#include <string>
using std::string;

class Rogue: public Person
{
private:
	Stealth* steal;
	string type;
public:
	Rogue(string, double, double, double, double, double, double, double);
	Rogue(string , double , double );
	Rogue();
	virtual ~Rogue();
	virtual double damage();

};
