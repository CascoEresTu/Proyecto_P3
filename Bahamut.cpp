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

    for (size_t i = 0; i < party.size(); i++) {
        Person* temp = party.at(i);

        std::cout << "Entrando" << std::endl;

        //std::cout << party.at(i)->getHP() << std::endl;

        //int hpActual = party.at(i)->getHP() - 50;

        temp->setHP(temp->getHP()- 50);
        std::cout << temp->getHP() << std::endl;

        //party.at(i)->setHP(hpActual);

        //std::cout << party.at(i)->getHP() << std::endl;
    }

  /*  if/ (party.size()==1) {
      std::cout << "hola" << std::endl;
    }

    if (party.size()==2){
        for (size_t i = 0; i < party.size(); i++) {
        party.at(i)->setHP(party.at(i)->getHP() - 50 );
        }
    }
*/
}
