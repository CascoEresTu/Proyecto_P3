main: main.o Person.o Attribute.o Physical.o Light.o
	g++ main.o Person.o Attribute.o Physical.o Light.o -o main

main.o: Attribute.h Person.h Light.h Physical.h main.cpp
	g++ -c main.cpp

Person.o: Person.h Person.cpp
	g++ -c Person.cpp

Attribute.o: Attribute.h Attribute.cpp
	g++ -c Attribute.cpp

Physical.o: Attribute.h Physical.h Physical.cpp
	g++ -c Physical.cpp

Light.o: Attribute.h Light.h Light.cpp
	g++ -c Light.cpp