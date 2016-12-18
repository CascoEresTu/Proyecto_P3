#include "Person.h"
#include "Melee.h"
#include "Attribute.h"
#include "Boss.h"
#include "Physical.h"
#include "Light.h"
#include "Boss.h"
#include "Bahamut.h"
#include "MightyChocobo.h"
#include <ncurses.h>

bool allDead(vector<Person*>);

int main(int argc, char const *argv[]) {
	/*WINDOW *w;
    char list[5][7] = { "One", "Two", "Three", "Four", "Five" };
    char item[7];
    int ch, i = 0, width = 7;

    initscr(); // initialize Ncurses
    w = newwin( 10, 12, 1, 1 ); // create a new window
    box( w, 0, 0 ); // sets default borders for the window

// now print all the menu items and highlight the first one
    for( i=0; i<5; i++ ) {
        if( i == 0 )
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item );
    }

    wrefresh( w ); // update the terminal screen

    i = 0;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.

       // get the input
    while(( ch = wgetch(w)) != 'q'){

                // right pad with spaces to make the items appear with even width.
            sprintf(item, "%-7s",  list[i]);
            mvwprintw( w, i+1, 2, "%s", item );
              // use a variable to increment or decrement the value based on the input.
            switch( ch ) {
                case KEY_UP:
                            i--;
                            i = ( i<0 ) ? 4 : i;
                            break;
                case KEY_DOWN:
                            i++;
                            i = ( i>4 ) ? 0 : i;
                            break;
								case KEY_ENTER:

												return 1;
												break;
            }
            // now highlight the next item in the list.
            wattron( w, A_STANDOUT );

            sprintf(item, "%-7s",  list[i]);
            mvwprintw( w, i+1, 2, "%s", item);
            wattroff( w, A_STANDOUT );
    }
    delwin(w);
    endwin();*/

		vector<Person*> party;

		for (size_t i = 0; i < 4; i++) {
			party.push_back(new Melee("José",1500,300,150,150,0,60,100));
		}

		Bahamut* asd = new Bahamut("Bahamut",5000,"hijos de puta, me pegaron");
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
									break;
								}
							}
							if (opcion == 2){
								std::cout << "spoof" << std::endl;

								if(asd->getHP() <= 0 ){
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
