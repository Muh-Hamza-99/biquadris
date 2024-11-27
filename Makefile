CXX = g++
CXXFLAGS = -std=c++20 -g -Wall -Werror=vla -MMD
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}

SOURCES = $(wildcard *.cc)
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}
EXEC = biquadris

.PHONY : clean
${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@ -lX11

# ${CXX} ${CXXFLAGS} $^ -o $@ -lX11 with graphics

${OBJECTS} : ${MAKEFILE_NAME}
-include ${DEPENDS}
clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}