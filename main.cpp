#include "Person.h"
#include "Melee.h"
#include "BlackMage.h"
#include "WhiteMage.h"
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


bool allDead(vector<Person*>);
void guardarPartida(vector<Person*>);
void cargarPartida(vector<Person*>&);
using namespace std;

void write(vector<Person*>);
bool allDead(vector<Person*>);

int main(int argc, char const *argv[]) {
	vector<Person*> party;
	initscr();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	int option = 0 ;
	char temp[1];
	while (option != 6) {
		addstr("Final Fantasy I - Simulator\n");
		refresh();
		addstr("1) Crear Melee\n");
		refresh();
		addstr("2) Crear Rogue\n");
		refresh();
		addstr("3) Crear White Mage\n");
		refresh();
		addstr("4) Crear Black Mage \n");
		refresh();
		addstr("5) Simulator \n");
		refresh();
		addstr("6) Salir \n");
		refresh();
		scanw("%d",&option);
		clear();
		char nombre[25];
		int hp;
		int mp;
		if (option == 1) {
			clear();
			if (party.size() < 4)
			{
				try{
					addstr("Ingrese el nombre de su Melee: \n");
					refresh();
					getstr(nombre);
					addstr("Ingrese el HP de su Melee: \n");
					refresh();
					scanw("%d", &hp);
					addstr("Ingrese el MP de su Melee: \n");
					refresh();
					scanw("%d", &mp);
					party.push_back(new Melee(nombre,hp,mp));
					addstr("Su Melee ha sido agregado exitosamente\n");
					refresh();
				}catch(...){
					addstr("Ocurrió un error al agregar el Melee.\n");
					refresh();
				}
			}else{
				addstr("Ya se encuentran 4 personajes en su equipo. \n");
				refresh();
			}
		}

		if (option == 2){
			clear();
			if (party.size() < 4)
			{
				try{
					addstr("Ingrese el nombre de su Rogue: \n");
					refresh();
					getstr(nombre);
					addstr("Ingrese el HP de su Rogue: \n");
					refresh();
					scanw("%f", &hp);
					addstr("Ingrese el MP de su Rogue: \n");
					refresh();
					scanw("%f", &mp);
					party.push_back(new Rogue(nombre,hp,mp));
					addstr("Su Rogue ha sido agregado exitosamente\n");
					refresh();
				}catch(...){
					addstr("Ocurrió un error al agregar el Rogue.\n");
					refresh();
				}
			}else{
				addstr("Ya se encuentran 4 personajes en su equipo. \n");
				refresh();
			}
		}
		if (option == 3) {
			clear();
			if (party.size() < 4)
			{
				try{
					addstr("Ingrese el nombre de su White Mage: \n");
					refresh();
					getstr(nombre);
					addstr("Ingrese el HP de su White Mage: \n");
					refresh();
					scanw("%f", &hp);
					addstr("Ingrese el MP de su White Mage: \n");
					refresh();
					scanw("%f", &mp);
					party.push_back(new WhiteMage(nombre,hp,mp));
					addstr("Su White Mage ha sido agregado exitosamente\n");
					refresh();
				}catch(...){
					addstr("Ocurrió un error al agregar el White Mage.\n");
					refresh();
				}
			}else{
				addstr("Ya se encuentran 4 personajes en su equipo. \n");
				refresh();
			}
		}
		if (option == 4) {
			clear();
			if (party.size() < 4)
			{
				try{
					addstr("Ingrese el nombre de su Black Mage: \n");
					refresh();
					getstr(nombre);
					addstr("Ingrese el HP de su Black Mage: \n");
					refresh();
					scanw("%f", &hp);
					addstr("Ingrese el MP de su Black Mage: \n");
					refresh();
					scanw("%f", &mp);
					party.push_back(new BlackMage(nombre,hp,mp));
					addstr("Su Black Mage ha sido agregado exitosamente\n");
					refresh();
				}catch(...){
					addstr("Ocurrió un error al agregar el Black Mage.\n");
					refresh();
				}
			}else{
				addstr("Ya se encuentran 4 personajes en su equipo. \n");
				refresh();
			}
		}
		if(option == 5){
				guardarPartida(party);
		}
		if(option == 6){
			clear();
			addstr("Salió. \n");
			refresh();
		}
	}
	for (int i = 0; i < party.size(); ++i)
	{
		delete party.at(i);
		party.erase(party.begin()+i);
	}
	party.clear();

	refresh();
	getch();
	endwin();
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

void write(vector<Person*> party){
	ofstream data;
	data.open ("Data.txt");

	for (size_t i = 0; i < party.size(); i++) {
			if (dynamic_cast<Melee*> (party.at(i))!=NULL){
					Melee* temp = dynamic_cast<Melee*>(party.at(i));
					data<< temp->toString();
					delete temp;
			}
			if (dynamic_cast<Rogue*> (party.at(i))!=NULL){
					Rogue* temp = dynamic_cast<Rogue*>(party.at(i));
					data<< temp->toString();
					delete temp;
			}
			if (dynamic_cast<WhiteMage*> (party.at(i))!=NULL){
					WhiteMage* temp = dynamic_cast<WhiteMage*>(party.at(i));
					data<< temp->toString();
					delete temp;
			}
			if (dynamic_cast<BlackMage*> (party.at(i))!=NULL){
					BlackMage* temp = dynamic_cast<BlackMage*>(party.at(i));
					data<< temp->toString();
					delete temp;}
				}
	data.close();
}




void guardarPartida(vector<Person*> party){

	ofstream data;
	data.open ("Data.txt");

	for (int i = 0; i < party.size(); i++) {
			if (dynamic_cast<Melee*> (party.at(i))!=NULL){
					Melee* temp = dynamic_cast<Melee*>(party.at(i));
					data<< temp->toString();
		//			delete temp;
			}
			if (dynamic_cast<Rogue*> (party.at(i))!=NULL){
					Rogue* temp = dynamic_cast<Rogue*>(party.at(i));
					data<< temp->toString();
			//		delete temp;
			}
			if (dynamic_cast<WhiteMage*> (party.at(i))!=NULL){
					WhiteMage* temp = dynamic_cast<WhiteMage*>(party.at(i));
					data<< temp->toString();
				///	delete temp;
			}
			if (dynamic_cast<BlackMage*> (party.at(i))!=NULL){
					BlackMage* temp = dynamic_cast<BlackMage*>(party.at(i));
					data<< temp->toString();
				// 		delete temp;
			}
		}
		data.close();
}

void cargarPartida(vector<Person*>& party){


}
