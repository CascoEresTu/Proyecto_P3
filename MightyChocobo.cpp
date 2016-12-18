#include "MightyChocobo.h"

MightyChocobo::MightyChocobo(){

}

MightyChocobo::MightyChocobo(string name, int hp, string warcr): Boss(name,hp){
  this->warcry = "CHOCOOOOO, CHOCOOOOOOOO";
}

MightyChocobo::~MightyChocobo(){
  std::cout << "MightyChocobo ded, lol." << std::endl;
}

void MightyChocobo::attack(vector<Person*> party){
  //int teamMembers = party.size();
  if (party.size >0 ) {

  int aleatorio;
  int aleatorio2;
  aleatorio = rand()%10 +1;
  aleatorio2 = rand()%party.size();

    if (aleatorio >= 8) {
        party.at(aleatorio2)->setHP(0);      
        party.erase(party.begin()+ aleatorio2);
    }else{
        for (size_t i = 0; i < party.size(); i++) {
            party.at(i)->setHp(party.at(i)->getHP - 40.5);
            if (party.at(i)->getHP() <= 0) {
              party.erase(party.begin()+ party.at(i));
            }
        }
      }
    }
  }
