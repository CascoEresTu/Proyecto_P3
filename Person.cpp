#include "Person.h"

using namespace std;

Person::Person(){

}

Person::Person(string nombre, const double hp, const double mp, const double att,const double def,const double spa,const double spd,const double Speed){
   name=nombre;
   HP= hp;
   this->setHP(hp);
   MP= mp;
   attack=att;
   defense=def;
   spAttack=spa;
   spDefense=spd;
   speed = Speed;
}

Person::~Person(){
  cout<< "Lol, u ded." <<endl;
}

void Person::setName(string nombre){
   name = nombre;
}

string Person::getName(){
  return name;
}

void Person::setHP(const double hp){
  this->HP = hp;
}

double Person::getHP(){
  return this->HP;
}

void Person::setMP(const double mp){
  this->MP = mp;
}

double Person::getMP(){
  return this->MP;
}

void Person::setAttack(const double att){
  attack = att;
}

double Person::getAttack(){
  return attack;
}

void Person::setDefense(const double def){
  defense = def;
}

double Person::getDefense(){
  return defense;
}

void Person::set_spAttack(const double spa){
    spAttack = spa;
}

double Person::get_spAttack(){
  return spAttack;
}

void Person::set_spDefense(const double spd){
  spDefense = spd;
}

double Person::get_spDefense(){
  return spDefense;
}

void Person::setSpeed(const double spd){
  speed = spd;
}

double Person::getSpeed(){
  return speed;
}
