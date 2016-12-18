main: main.o Person.o Melee.o Boss.o Bahamut.o Attribute.o Physical.o Light.o Stealth.o Dark.o Rogue.o WhiteMage.o
	g++ main.o Person.o Melee.o Boss.o Bahamut.o Attribute.o Physical.o Light.o Stealth.o Dark.o Rogue.o WhiteMage.o -o main -lncurses

main.o: Attribute.h Person.h Light.h Physical.h main.cpp
	g++ -c main.cpp

Person.o: Person.h Person.cpp
	g++ -c Person.cpp

Melee.o: Person.h Attribute.h Physical.h Melee.h Melee.cpp
	g++ -c Melee.cpp

Rogue.o: Person.h Attribute.h Stealth.h Boss.h Rogue.h Rogue.cpp
	g++ -c Rogue.cpp

WhiteMage.o: Person.h Attribute.h Light.h WhiteMage.h WhiteMage.cpp
	g++ -c WhiteMage.cpp

BlackMage.o: Person.h Attribute.h Dark.h BlackMage.h BlackMage.cpp
	g++ -c BlackMage.cpp

Boss.o: Boss.h Boss.cpp
	g++ -c Boss.cpp

Bahamut.o: Boss.h Bahamut.h Bahamut.cpp
	g++ -c Bahamut.cpp

Attribute.o: Attribute.h Attribute.cpp
	g++ -c Attribute.cpp

Physical.o: Attribute.h Physical.h Physical.cpp
	g++ -c Physical.cpp

Light.o: Attribute.h Light.h Light.cpp
	g++ -c Light.cpp

Stealth.o: Attribute.h Stealth.h Stealth.cpp
	g++ -c Stealth.cpp

Dark.o:	Attribute.h Dark.h Dark.cpp
	g++ -c Dark.cpp

clean:
	rm -f *.o main