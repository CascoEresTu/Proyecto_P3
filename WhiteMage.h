#pragma once
#include "Person.h"
#include "Attribute.h"
#include "Stealth.h"
#include <string>
using std::string;

class WhiteMage
{
private:
	Light* heal;
	string type;
public:
	WhiteMage(string, double, double, double, double, double, double, double);
	WhiteMage();
	virtual ~WhiteMage();
	virtual double damage();;
	
};