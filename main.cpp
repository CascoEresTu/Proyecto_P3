#include "Person.h"
#include "Melee.h"
#include "BlackMage.h"
#include "Attribute.h"
#include "Boss.h"
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
		double hp;
		double mp;
		if (option == 1) {
			clear();
			if (party.size() < 4)
			{
				addstr("Ingrese el nombre de su Melee: \n");
				refresh();
				getstr(nombre);
				addstr("Ingrese el HP de su Melee: \n");
				refresh();
				scanw("%f", &hp);
				addstr("Ingrese el MP de su Melee: \n");
				refresh();
				scanw("%f", &mp);
				party.push_back(new Melee());
				addstr("Su Melee ha sido agregado exitosamente\n");
				refresh();
			}else{
				addstr("Ya se encuentran 4 personajes en su equipo. \n");
				refresh();
			}
		}

		if (option == 2){
			addstr("Ingrese el nombre de su Rogue: \n");
			refresh();
			getstr(nombre);
			addstr("Ingrese el HP de su Rogue: \n");
			refresh();
			scanw("%f", &hp);
			addstr("Ingrese el MP de su Rogue: \n");
			refresh();
			scanw("%f", &mp);
			party.push_back(new Rogue());
			addstr("Su Rogue ha sido agregado exitosamente\n");
			refresh();
		}else{
			addstr("Ya se encuentran 4 personajes en su equipo. \n");
			refresh();
		}
	}

	if (option == 3) {


	}else{
		addstr("Ocupa almenos 4 escuadrones para poder iniciar la simulación.\n");
		refresh();
		addstr("");
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

void guardarPartida(vector<Person*> party){
	try{
		ofstream salida;
		salida.open("Partida.ff", ios::out|ios::binary);
		for (int i = 0; i < party.size(); ++i)
		{
			salida.write((char *)(party.at(i)), sizeof(Person));
		}
		salida.close();
	}catch(...){
		cerr<< "Ocurrió un error"<<endl;
	}
}
void cargarPartida(vector<Person*>& party){
	try{
		ifstream entrada;
		entrada.open("Partida.ff", ios::in|ios::binary);
		while(entrada.read((char *)&party, sizeof(Person)));
		entrada.close();
	}catch(...){
		cerr<< "Ocurrió un error"<<endl;
	}
}
