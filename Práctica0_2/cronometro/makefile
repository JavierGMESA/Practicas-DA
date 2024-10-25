CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
EXE = prueba
OBJS = prueba.o

${EXE}: ${OBJS}
	${CXX} ${LDFLAGS} -o $@ $^

${OBJS}: cronometro.hpp

clean:
	${RM} ${EXE} ${OBJS} *~
