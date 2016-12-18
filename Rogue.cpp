#include "Person.h"
#include "Attribute.h"
#include "Stealth.h"
#include "Rogue.h"
#include "Boss.h"
#include <sstream>
#include <string>
using std::stringstream;
using std::string;


Rogue::Rogue(string nombre, double hp, double mp):Person(nombre,hp,mp){
	this->attack=30;
	this->defense=30;
	this->spAttack=0;
	this->spDefense=30;
	this->speed = 50;
	type = "Stealth";
	steal = new Stealth();
}


Rogue::Rogue(string nombre, double hp, double mp, double att, double def, double spa, double spd, double Speed):Person(nombre,hp,mp,att,def,spa,spd,Speed){
	type = "Stealth";
	steal = new Stealth();
}

Rogue::Rogue(){
	type = "Stealth";
	steal = new Stealth();
}

Rogue::~Rogue(){
	delete steal;
}

double Rogue::damage(){
	steal->setAttackP();
	return steal->stealHP(2000);
}

string Rogue::toString(){
	stringstream ss;
	ss<<"Rogue"<<";"<<name<<";"<<HP<<";"<<MP<<";";
	return ss.str();
}

