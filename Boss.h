#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Person.h"
#include <stdlib.h>
#include <typeinfo>

class Boss{
protected:
  int HP;
  string name;
public:
  Boss();
  Boss(string nombre, int hp);
  virtual ~Boss();
  virtual void attack(vector<Person*>)=0;
  void setHP(double hp);
  double getHP();
};
