#pragma once
#include "Boss.h"
#include "Person.h"
class Bahamut : public Boss{

private:
  string warcry;
public:
  Bahamut();
  Bahamut(string nombre,int hp);
  ~Bahamut();
   void attack(vector<Person*>);
};
