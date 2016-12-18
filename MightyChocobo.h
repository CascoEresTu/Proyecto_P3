#include "Boss.h"
#include "Person.h"
#include <vector>

class MightyChocobo : public Boss{
private:
string cry;

public:
  MightyChocobo();
  MightyChocobo(string nombre,int hp, string warcry);
  ~MightyChocobo();
  void attack(vector<Person*>);





};
