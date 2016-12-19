#pragma once
#include "Boss.h"
#include "Person.h"
#include <vector>

class MightyChocobo : public Boss{
private:
string warcry;

public:
  MightyChocobo();
  MightyChocobo(string nombre,int hp);
  ~MightyChocobo();
  void attack(vector<Person*>);
  string warCry();
};
