
CXX = g++


ProgramaCarreteras: main.o carreteras.o
	$(CXX) -o $@ $(LDFLAGS) $(LDLIBS) $^

main.o: main.cpp carreteras.hpp
	$(CXX) -c $(CXXFLAGS) $<

carreteras.o: carreteras.cpp carreteras.hpp
	$(CXX) -c $(CXXFLAGS) $<

tiempos: ProgramaCarreteras.tmp

# PARA QUE ESTA PARTE FUNCIONE, EL PROGRAMA ProgramaCerreteras debería tener un resultado por pantalla
# parecido al de Fibonacci (tamaño tiempo)
ProgramaCarreteras.tmp: ProgramaCarreteras
	./$< | tee $@

graficas:
	gnuplot graficas.plot

graficas-pdf:
	gnuplot graficas-pdf.plot

clean:
	$(RM) ProgramaCarreteras main.o carreteras.o ~*


