AntsvsBees: main.o Game.o Bee.o Ant.o Ninja.o Thrower.o Wall.o ShortThrower.o LongThrower.o Harvester.o Fire.o Bodyguard.o
	g++  -std=c++0x  main.o Game.o Bee.o Ant.o Ninja.o Thrower.o Wall.o ShortThrower.o LongThrower.o Harvester.o Fire.o Bodyguard.o -o AntsvsBees

main.o: main.cpp Game.cpp Game.h
	g++ -std=c++0x -c main.cpp
	
Game.o: Game.cpp Game.h Insect.h Cell.h Bee.cpp Bee.h Ninja.cpp Ninja.h Thrower.cpp Thrower.h Wall.cpp Wall.h ShortThrower.cpp ShortThrower.h LongThrower.cpp LongThrower.h Harvester.cpp Harvester.h Fire.cpp Fire.h Bodyguard.cpp Bodyguard.h
	g++ -std=c++0x -c Game.cpp
	
Bee.o: Bee.cpp Bee.h Insect.h Cell.h
	g++ -std=c++0x -c Bee.cpp

Ant.o: Ant.cpp Ant.h Insect.h Cell.h
	g++ -std=c++0x -c Ant.cpp
	
Ninja.o: Ninja.cpp Ninja.h Insect.h Ant.cpp Ant.h Cell.h
	g++ -std=c++0x -c Ninja.cpp

Thrower.o: Thrower.cpp Thrower.h Insect.h Ant.cpp Ant.h Cell.h
	g++ -std=c++0x -c Thrower.cpp
	
Wall.o: Wall.cpp Wall.h Insect.h Ant.cpp Ant.h Cell.h
	g++ -std=c++0x -c Wall.cpp
	
ShortThrower.o: ShortThrower.cpp ShortThrower.h Insect.h Ant.cpp Ant.h Cell.h
	g++ -std=c++0x -c ShortThrower.cpp
	
LongThrower.o: LongThrower.cpp LongThrower.h Insect.h Ant.cpp Ant.h Cell.h
	g++ -std=c++0x -c LongThrower.cpp
	
Harvester.o: Harvester.cpp Harvester.h Insect.h Ant.cpp Ant.h Cell.h
	g++ -std=c++0x -c Harvester.cpp

Fire.o: Fire.cpp Fire.h Insect.h Ant.cpp Ant.h Cell.h
	g++ -std=c++0x -c Fire.cpp
	
Bodyguard.o: Bodyguard.cpp Bodyguard.h Insect.h Ant.cpp Ant.h Cell.h
	g++ -std=c++0x -c Bodyguard.cpp

clean:
	del *.o AntsvsBees.exe