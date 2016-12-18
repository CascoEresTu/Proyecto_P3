#include "Person.h"
#include "Melee.h"
#include "Attribute.h"
#include "Physical.h"
#include <string>
using std::string;

Melee::Melee(string nombre, double hp, double mp):Person(nombre,hp,mp){
	this->attack=50;
	this->defense=50;
	this->spAttack=0;
	this->spDefense=25;
	this->speed = 20;
	type = "Physical";
	special = new Physical();
}

Melee::Melee(string nombre, double hp, double mp, double att, double def, double spa, double spd, double Speed):Person(nombre,hp,mp,att,def,spa,spd,Speed){
	type = "Physical";
	special = new Physical();
}
Melee::Melee(){
	type = "Physical";
	special = new Physical();
}
Melee::~Melee(){
	delete special;
}
double Melee::damage(){
	special->setAttackP();
	return (special-> getDamage());
}
