# Para el ejercicio de la damas

CXX = g++
EXE = programa
OBJS = main.o damas.o
CXXFLAGS = -O3


all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $^ $(LDLIBS)

$(OBJS): damas.hpp

clean:
	$(RM) $(EXE) $(OBJS) core *~
