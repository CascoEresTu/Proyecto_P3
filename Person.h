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
  Person(string name, double hp, double mp, double att, double def, double spa, double spd, double Speed);
  virtual ~Person();
  virtual double damage()=0;

  void setName(string);
  string getName();

  void setHP(double);
  double getHP();

  void setMP(double);
  double getMP();

  void setAttack(double);
  double getAttack();

  void setDefense(double);
  double getDefense();

  void set_spAttack(double);
  double get_spAttack();

  void set_spDefense(double);
  double get_spDefense();

  void setSpeed(double);
  double getSpeed();

};
