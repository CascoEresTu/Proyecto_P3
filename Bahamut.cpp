#include "Bahamut.h"

Bahamut::Bahamut(){

}

Bahamut::Bahamut(string name, int hp): Boss(name,hp){
  this->warcry = "SIMPLES MORTALES, NUNCA ME VENCERÁN";
}

Bahamut::~Bahamut(){
  std::cout << "bahamut ded, lol." << std::endl;
}

void Bahamut::attack(vector<Person*> party){

  //int teamMembers = party.size();



    if (party.size()==1) {
      std::cout << "hola" << std::endl;
    }

    if (party.size()==2){
        for (size_t i = 0; i < party.size(); i++) {
        party.at(i)->setHP(party.at(i)->getHP() - 50 );
        }
    }


}
