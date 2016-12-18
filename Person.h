#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person{

protected:
  string name;
  double HP;
  double MP;
  double attack;
  double defense;
  double spAttack;
  double spDefense;
  double speed;

public:
  Person();
  Person(string name, const double hp, const double mp, const double att, const double def, const double spa, const double spd, const double Speed);
  virtual ~Person();
  virtual double damage()=0;

  void setName(string);
  string getName();

  void setHP(const double);
  double getHP();

  void setMP(const double);
  double getMP();

  void setAttack(const double);
  double getAttack();

  void setDefense(const double);
  double getDefense();

  void set_spAttack(const double);
  double get_spAttack();

  void set_spDefense(const double);
  double get_spDefense();

  void setSpeed(const double);
  double getSpeed();

};
