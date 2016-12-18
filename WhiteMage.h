#pragma once
#include "Person.h"
#include "Attribute.h"
#include "Light.h"
#include <string>
using std::string;

class WhiteMage: public Person
{
private:
	Light* heal;
	string type;
public:
	WhiteMage(string, double, double, double, double, double, double, double);
		WhiteMage(string, double, double);
	WhiteMage();
	virtual ~WhiteMage();
	virtual double damage();

};
