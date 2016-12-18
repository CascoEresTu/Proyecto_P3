#include "BlackMage.h"
#include "Person.h"
#include "Attribute.h"
#include "Dark.h"
#include <string>
using std::string;

BlackMage::BlackMage(string nombre, double hp, double mp):Person(nombre,hp,mp){
	this->attack=30;
	this->defense=30;
	this->spAttack=0;
	this->spDefense=30;
	this->speed = 50;
	spell = new Dark();
	type = "Dark";
}


BlackMage::BlackMage(string nombre, double hp, double mp, double att, double def, double spa, double spd, double Speed):Person(nombre,hp,mp,att,def,spa,spd,Speed){
	spell = new Dark();
	type = "Dark";
}

BlackMage::BlackMage(){
	spell = new Dark();
	type = "Dark";
}

BlackMage::~BlackMage(){
	delete spell;
}

double BlackMage::damage(){
	spell->setAttackP();
	return spell->getDamage();
}
