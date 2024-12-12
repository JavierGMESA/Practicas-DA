# Para el ejercicio de la damas

CXX = g++
EXE = programa
OBJS = main.o damas.o
CXXFLAGS = -o -ggdb -pg

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $(LDLIBS) $^

main.o: damas.hpp
damas.o: damas.hpp

clean:
	$(RM) $(EXE) $(OBJS) core *~

