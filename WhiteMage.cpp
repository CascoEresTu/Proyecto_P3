#include "WhiteMage.h"
#include "Person.h"
#include "Attribute.h"
#include "Light.h"
#include <string>
using std::string;


WhiteMage::WhiteMage(string nombre, double hp, double mp):Person(nombre,hp,mp){
	this->attack=10;
	this->defense=20;
	this->spAttack=30;
	this->spDefense=50;
	this->speed = 30;
	heal = new Light();
	type = "Healer";
}

WhiteMage::WhiteMage(string nombre, double hp, double mp, double att, double def, double spa, double spd, double Speed):Person(nombre,hp,mp,att,def,spa,spd,Speed){
	heal = new Light();
	type = "Healer";
}
WhiteMage::WhiteMage(){
	heal = new Light();
	type = "Healer";
}
WhiteMage::~WhiteMage(){
	delete heal;
}
double WhiteMage::damage(){
	return heal->getHeal();
}
