#include "Person.h"

using namespace std;

Person::Person(){

}

Person::Person(string nombre, double hp, double mp, double att, double def, double spa, double spd, double Speed){
   name=nombre;
   HP=hp;
   MP=mp;
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

void Person::setHP(double hp){
  HP= hp;
}

double Person::getHP(){
  return MP;
}

void Person::setMP(double mp){
  MP = mp;
}

double Person::getMP(){
  return MP;
}

void Person::setAttack(double att){
  attack = att;
}

double Person::getAttack(){
  return attack;
}

void Person::setDefense(double def){
  defense = def;
}

double Person::getDefense(){
  return defense;
}

void Person::set_spAttack(double spa){
    spAttack = spa;
}

double Person::get_spAttack(){
  return spAttack;
}

void Person::set_spDefense(double spd){
  spDefense = spd;
}

double Person::get_spDefense(){
  return spDefense;
}

void Person::setSpeed(double spd){
  speed = spd;
}

double Person::getSpeed(){
  return speed;
}
