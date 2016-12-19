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
#include "Cactuar.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <ncurses.h>
#include <vector>
#include <typeinfo>


bool allDead(vector<Person*>);
void guardarPartida(vector<Person*>);
void cargarPartida(vector<Person*>);
using namespace std;

void write(vector<Person*>);
bool allDead(vector<Person*>);

int main(int argc, char const *argv[]) {
	vector<Person*> party;
	//cargarPartida(party);
	initscr();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	int option = 0 ;
	while (option != 6) {
		// Menú
		clear();
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
			// Crear Melee
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
				//Crear Rogue
				try{
					addstr("Ingrese el nombre de su Rogue: \n");
					refresh();
					getstr(nombre);
					addstr("Ingrese el HP de su Rogue: \n");
					refresh();
					scanw("%d", &hp);
					addstr("Ingrese el MP de su Rogue: \n");
					refresh();
					scanw("%d", &mp);
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
				//Crear White Mage
				try{
					addstr("Ingrese el nombre de su White Mage: \n");
					refresh();
					getstr(nombre);
					addstr("Ingrese el HP de su White Mage: \n");
					refresh();
					scanw("%d", &hp);
					addstr("Ingrese el MP de su White Mage: \n");
					refresh();
					scanw("%d", &mp);
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
				//Crear Black Mage
				try{
					addstr("Ingrese el nombre de su Black Mage: \n");
					refresh();
					getstr(nombre);
					addstr("Ingrese el HP de su Black Mage: \n");
					refresh();
					scanw("%d", &hp);
					addstr("Ingrese el MP de su Black Mage: \n");
					refresh();
					scanw("%d", &mp);
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
			//Simulación
			clear();
			int opcion;
			while(opcion != 5){
				clear();
				addstr("1) Pelear contra Bahamut\n");
				refresh();
				addstr("2) Pelear contra Mighty Chocobo\n");
				refresh();
				addstr("3) Pelear contra Cactuar\n");
				refresh();
				addstr("4) Cargar Partida Anterior \n");
				refresh();
				addstr("5) Salir de la Simulación \n");
				refresh();
				addstr("Ingrese una opción:  \n");
				refresh();
				scanw("%d", &opcion);
				if(opcion == 1){
					//Pelea contra Bahamut
					clear();
					Bahamut* bahamut = new Bahamut("Bahamut",5000);
					addstr((bahamut->warCry()).c_str());
					refresh();
					int select;
					bool dead = allDead(party);
					while(bahamut->getHP()>0 && dead == false && select!= 4){
						clear();
						for (int i = 0; i < party.size(); ++i)
						{
							clear();
							addstr("1) Ataque normal\n");
							refresh();
							addstr("2) Ataque Especial\n");
							refresh();
							addstr("3) Saltar turno\n");
							refresh();
							addstr("4) Guardar Partida\n");
							refresh();
							addstr("Ingrese una opción:  \n");
							refresh();
							scanw("%d", &select);
							stringstream pelea;
							if (select == 1)
							{
								bahamut->setHP(bahamut->getHP()-party.at(i)->getAttack());
							}
							if (select == 2)
							{
								if (party.at(i)->getMP()>=10)
								{
									if (dynamic_cast<Melee*> (party.at(i))!=NULL)
									{
										bahamut->setHP(bahamut->getHP() - party.at(i)-> damage());
										party.at(i)->setMP(party.at(i)->getMP() - 10);
									}else if(dynamic_cast<Rogue*> (party.at(i))!=NULL){
										bahamut->setHP(bahamut->getHP() - party.at(i)-> damage());
										if(party.at(i)->getHP()<2500){
											party.at(i)->setHP(party.at(i)-> getHP() + party.at(i)->damage());
											party.at(i)->setMP(party.at(i)->getMP() - 10);
										}
									}else if (dynamic_cast<WhiteMage*> (party.at(i))!=NULL){
										for (int j = 0; j < party.size(); ++j)
										{
											if(party.at(i)->getHP()<2500){
												party.at(i)->setHP(party.at(i)-> getHP()+ party.at(i)->damage());
												party.at(i)->setMP(party.at(i)->getMP() - 10);
											}
										}
									}else{
										bahamut->setHP(bahamut->getHP() - party.at(i)-> damage());
										party.at(i)->setMP(party.at(i)->getMP() - 10);
									}
								}else{
									clear();
									addstr("No tiene el suficiente MP para cumplir esta acción.\n");
									refresh();
								}
							}
							if (select == 3)
							{
								party.at(i)->setMP(party.at(i)->getMP()+5);
							}
							if(select == 4){
								guardarPartida(party);
								clear();
								addstr("Se guardó la partida.\n");
								refresh();
							}
						}
						bahamut->attack(party);
						dead = allDead(party);
					}
				}
				if(opcion == 2){
					//Pelea contra chocobo
					clear();
					MightyChocobo* chocobo = new MightyChocobo("Mighty Chocobo",5000);
					addstr((chocobo->warCry()).c_str());
					refresh();
					int select;
					double MHP;
					double RHP;
					double WHP;
					double BHP;
					bool dead = allDead(party);
					while(chocobo->getHP()>0 && allDead(party)== false && select!= 4){
						clear();
						for (int i = 0; i < party.size(); ++i)
						{
							clear();
							addstr("1) Ataque normal\n");
							refresh();
							addstr("2) Ataque Especial\n");
							refresh();
							addstr("3) Saltar turno\n");
							refresh();
							addstr("4) Guardar Partida\n");
							refresh();
							addstr("Ingrese una opción:  \n");
							refresh();
							scanw("%d", &select);

							if (select == 1)
							{
								chocobo->setHP(chocobo->getHP()-party.at(i)->getAttack());
							}
							if (select == 2)
							{
								if (party.at(i)->getMP()>=10)
								{
									if (dynamic_cast<Melee*> (party.at(i))!=NULL)
									{
										chocobo->setHP(chocobo->getHP() - party.at(i)-> damage());
										party.at(i)->setMP(party.at(i)->getMP() - 10);
									}else if(dynamic_cast<Rogue*> (party.at(i))!=NULL){
										chocobo->setHP(chocobo->getHP() - party.at(i)-> damage());
										if(party.at(i)->getHP()<2500){
											party.at(i)->setHP(party.at(i)-> getHP() + party.at(i)->damage());
											party.at(i)->setMP(party.at(i)->getMP() - 10);
										}
									}else if (dynamic_cast<WhiteMage*> (party.at(i))!=NULL){
										for (int j = 0; j < party.size(); ++j)
										{
											if(party.at(i)->getHP()<2500){
												party.at(i)->setHP(party.at(i)-> getHP()+ party.at(i)->damage());
												party.at(i)->setMP(party.at(i)->getMP() - 10);
											}
										}
									}else{
										chocobo->setHP(chocobo->getHP() - party.at(i)-> damage());
										party.at(i)->setMP(party.at(i)->getMP() - 10);
									}
								}else{
									clear();
									addstr("No tiene el suficiente MP para cumplir esta acción.\n");
									refresh();
								}
							}
							if (select == 3)
							{
								party.at(i)->setMP(party.at(i)->getMP()+5);
							}
							if(select == 4){
								guardarPartida(party);
								clear();
								addstr("Se guardó la partida.\n");
								refresh();
							}
						}
						chocobo->attack(party);
						dead = allDead(party);
					}
				}
				if (opcion == 3)
				{
					//Pelea contra Cactuar
					clear();
					Cactuar* cactuar = new Cactuar("Cactuar",5000);
					addstr((cactuar->warCry()).c_str());
					refresh();
					int select;
					double MHP;
					double RHP;
					double WHP;
					double BHP;
					bool dead = allDead(party);
					while(cactuar->getHP()>0 && dead == false && select!= 4){
						clear();
						for (int i = 0; i < party.size(); ++i)
						{
							clear();
							addstr("1) Ataque normal\n");
							refresh();
							addstr("2) Ataque Especial\n");
							refresh();
							addstr("3) Saltar turno\n");
							refresh();
							addstr("4) Guardar Partida\n");
							refresh();
							addstr("Ingrese una opción:  \n");
							refresh();
							scanw("%d", &select);

							if (select == 1)
							{
								cactuar->setHP(cactuar->getHP()-party.at(i)->getAttack());
							}
							if (select == 2)
							{
								if (party.at(i)->getMP()>=10)
								{
									if (dynamic_cast<Melee*> (party.at(i))!=NULL)
									{
										cactuar->setHP(cactuar->getHP() - party.at(i)-> damage());
										party.at(i)->setMP(party.at(i)->getMP() - 10);
									}else if(dynamic_cast<Rogue*> (party.at(i))!=NULL){
										cactuar->setHP(cactuar->getHP() - party.at(i)-> damage());
										if(party.at(i)->getHP()<2500){
											party.at(i)->setHP(party.at(i)-> getHP() + party.at(i)->damage());
											party.at(i)->setMP(party.at(i)->getMP() - 10);
										}
									}else if (dynamic_cast<WhiteMage*> (party.at(i))!=NULL){
										for (int j = 0; j < party.size(); ++j)
										{
											if(party.at(i)->getHP()<2500){
												party.at(i)->setHP(party.at(i)-> getHP()+ party.at(i)->damage());
												party.at(i)->setMP(party.at(i)->getMP() - 10);
											}
										}
									}else{
										cactuar->setHP(cactuar->getHP() - party.at(i)-> damage());
										party.at(i)->setMP(party.at(i)->getMP() - 10);
									}
								}else{
									clear();
									addstr("No tiene el suficiente MP para cumplir esta acción.\n");
									refresh();
								}
							}
							if (select == 3)
							{
								party.at(i)->setMP(party.at(i)->getMP()+5);
							}
							if(select == 4){
								guardarPartida(party);
								clear();
								addstr("Se guardó la partida.\n");
								refresh();
							}
						}
						cactuar->attack(party);
						dead = allDead(party);
					}
				}
				if (opcion == 4)
				{

					clear();
				}
				if (opcion == 5)
				{
					clear();
					addstr("Salió de la simulación.");
					refresh();
				}
			}
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
		return true;
}else{
	return false;
}
}

//Guardar partida
void guardarPartida(vector<Person*> party){
	ofstream data;
	data.open ("Data.txt");
	for (int i = 0; i < party.size(); i++) {
		data<< party.at(i)->toString()<<endl;
	}
	data.close();
}
//Cargar Partida
void cargarPartida(vector<Person*> party){
	ifstream data;
	string tipo= "";
	string nombre= "";
	string hp= "";
	string mp= "";

	data.open("Data.txt");
	if(data.fail()){
				//cout<<"Falló el archivo."<<endl;
		addstr("La carga del archivo ha fallado");
		refresh();
	}else{
		while(!data.eof()){
			getline(data, tipo,';');
			getline(data, nombre,';');
			getline(data, hp,';');
			getline(data, mp,';');

			if (tipo == "Melee") {
				party.push_back(new Melee(nombre,atoi( hp.c_str() ),atof(mp.c_str()) ) );
			}

			else if (tipo == "WhiteMage") {
				party.push_back(new WhiteMage(nombre,atoi( hp.c_str() ),atof(mp.c_str()) ) );
			}

			else if (tipo == "BlackMage") {
				party.push_back(new BlackMage(nombre,atoi( hp.c_str() ),atof(mp.c_str()) ) );
			}

			else if (tipo == "Rogue") {
				party.push_back(new Rogue(nombre,atoi( hp.c_str() ),atof(mp.c_str()) ) );
			}
			tipo = "";
		}
	}
	data.close();
}
