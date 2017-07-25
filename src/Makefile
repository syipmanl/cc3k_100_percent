CXX = g++
CXXFLAGS = -Wall -MMD -g -std=c++14
EXEC = cc3k
OBJECTS = main.o gamesystem.o map.o floor.o chamber.o textdisplay.o object.o tile.o character.o hero.o enemy.o item.o potion.o gold.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
