#include "Boss.h"
#include "Person.h"
#include <vector>

class Cactuar : public Boss{
private:
string cry;

public:
  Cactuar();
  Cactuar(string nombre,int hp, string warcry);
  ~Cactuar();
  void attack(vector<Person*>);

};
