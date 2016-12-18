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

    for (int i = 0; i < party.size(); i++) {
        Person* temp =  party.at(i);
        std::cout << "Entrando" << std::endl;
        std::cout << "" << std::endl;
        double dano = 250.0;
        double hp = party.at(i)->getHP();
        double nuevaHP = hp-dano;
        party.at(i)->setHP(nuevaHP);
        std::cout << party.at(i)->getHP() << std::endl;
    }

}
