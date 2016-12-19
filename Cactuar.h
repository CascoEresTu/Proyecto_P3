#pragma once
#include "Boss.h"
#include "Person.h"
#include <vector>

class Cactuar : public Boss{
private:
string warcry;

public:
  Cactuar();
  Cactuar(string nombre,int hp);
  ~Cactuar();
  void attack(vector<Person*>);
  string warCry();
};
