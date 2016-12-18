#pragma once
#include "Person.h"
#include "Attribute.h"
#include "Dark.h"
#include <string>
using std::string;

class BlackMage: public Person
{
private:
	Dark* spell;
	string type;
public:
	BlackMage(string, double, double);
	BlackMage(string, double, double, double, double, double, double, double);
	BlackMage();
	virtual ~BlackMage();
	virtual double damage();
};
