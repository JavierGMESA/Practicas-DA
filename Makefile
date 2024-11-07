
CXX = g++


ProgramaCarreteras: main.o carreteras.o
    $(CXX) -o $@ $(LDFLAGS) $(LDLIBS) $^

main.o: main.cpp carreteras.hpp
    $(CXX) -c $(CXXFLAGS) $<

carreteras.o: carreteras.cpp carreteras.hpp
    $(CXX) -c $(CXXFLAGS) $<

clean:
    $(RM) ProgramaCarreteras main.o carreteras.o ~*


