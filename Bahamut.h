#pragma once
#include "Boss.h"

class Bahamut : public Boss{

private:
  string warcry;
public:
  Bahamut();
  Bahamut(string nombre,int hp, string warcry);
  ~Bahamut();
  void attack(vector<Person*>);

};
