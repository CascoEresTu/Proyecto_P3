#pragma once
#include<string>
#include<iostream>
#include"Person.h"
#include<vector>
#include<stdlib.h>

class Boss{

<<<<<<< HEAD
=======
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
>>>>>>> 85033b50e42754cdd0e8047f8f6134ef4f7d4a35
};
