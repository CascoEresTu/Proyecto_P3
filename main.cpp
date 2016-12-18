#include "Person.h"
#include "Melee.h"
#include "BlackMage.h"
#include "Attribute.h"
#include "Boss.h"
#include "Rogue.h"
#include "Physical.h"
#include "Light.h"
#include "Boss.h"
#include "Bahamut.h"
#include "MightyChocobo.h"
#include <fstream>
#include <ncurses.h>
#include <vector>
#include <typeinfo>


using namespace std;

void write(vector<Person*>);
bool allDead(vector<Person*>);

int main(int argc, char const *argv[]) {

		///////////////////////////////////////
		double pepe = 0.123;
		Melee melel;
		melel.setHP(pepe);
		melel.setName("dasd");

		BlackMage flan;
		flan.setHP(500.0);
		std::cout << flan.getHP() << std::endl;


		std::cout << melel.getName() << std::endl;
		std::cout << melel.getHP() << std::endl;
		melel.setHP(212.0);
		std::cout << melel.getHP() << std::endl;

		/////////////////////////////////
		vector<Person*> party;

		for (size_t i = 0; i < 4; i++) {
			party.push_back(new Melee("José",1500,300));
		}

		Bahamut* asd = new Bahamut("Bahamut",5000);
		bool allAlive= true ;

		while(true){

			for (size_t i = 0; i < party.size(); i++) {
					int opcion = 0;
					if( !(party.at(i)->getHP() <= 0 )){
					std::cout << party.at(i)->getHP() << std::endl;
					std::cout << "Turno de: " << i << std::endl;
					std::cout << "¿Que hará? " << std::endl;
					std::cout << "1)Ataque " << std::endl;
					std::cout << "2)Ataque Especial" << std::endl;
					std::cout << "3)Pasar turno" << std::endl;
					cin>>opcion;

						if(opcion == 1){
							std::cout << i<< " ataca!" <<std::endl;
							asd->setHP(asd->getHP() - party.at(i)->getAttack());
								if(asd->getHP() <= 0 ){
									std::cout << "me muero" << std::endl;
									break;
								}
							}
							if (opcion == 2){
								std::cout << "spoof" << std::endl;

								if(asd->getHP() <= 0 ){
									std::cout << "me muero" << std::endl;
									break;
								}
							}

							if (opcion == 3) {
								std::cout << "has saltado turno" << std::endl;
							}
						}
					}

					if (asd->getHP() <= 0 ) {
						std::cout << "HIJOS DE PUTA, ME MUEROOOOO " << std::endl;
						std::cout << "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
						break;
					}
					asd->attack(party);

					//std::cout <<"hp de Bahamut: "<<asd->getHP()  <<std::endl;

//			allAlive = allDead(party);
		}

  return 0;
}




bool allDead(vector<Person*> party){
	if ( (party.at(0)->getHP()<= 0) &&
			 (party.at(1)->getHP()<= 0) &&
			 (party.at(2)->getHP()<= 0) &&
			 (party.at(3)->getHP()<= 0)
		) {
		return false;
	}

}
