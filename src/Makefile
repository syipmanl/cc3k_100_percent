CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror -MMD
EXEC = main
OUTPUT = cc3k
OBJECTS = main.o textdisplay.o tile.o subject.o floor.o map.o gamesystem.o chamber.o enemy.o floorobject.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${OUTPUT}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OUTPUT} ${DEPENDS} ${OBJECTS}


