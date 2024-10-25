# Compilador de C++ y opciones de compilación.

CXX = c++
override CXXFLAGS += -std=c++17 -Wall -Wextra

# Módulos objeto y ejecutables.

OBJS = prueba-1.o prueba-2.o fibonacci-1.o fibonacci-2.o
EXES = prueba-1 prueba-2

# Ficheros de tiempo y de gráficas.

TIEMPOS = prueba-1.tmp prueba-2.tmp
GRAFICAS = prueba-1.pdf prueba-2.pdf pruebas-1-y-2.pdf

# Por omisión, obtiene los ficheros de tiempo.

all: $(TIEMPOS)

# Obtención de los ejecutables.

prueba-1: prueba-1.o fibonacci-1.o
	$(CXX) $(LDFLAGS) -o $@ $^

prueba-2: prueba-2.o fibonacci-2.o
	$(CXX) $(LDFLAGS) -o $@ $^

# Obtención de los objetos.

$(OBJS): natural.hpp

prueba-1.o prueba-2.o: cronometro.hpp

# Obtención de los ficheros de tiempo.

prueba-1.tmp: prueba-1
	./$< | tee $@

prueba-2.tmp: prueba-2
	./$< | tee $@

# Obtención de las gráficas.

graficas:
	gnuplot graficas.plot

graficas-pdf:
	gnuplot graficas-pdf.plot

# Limpieza del directorio.

clean:
	$(RM) $(EXES) $(OBJS) *~

clean-all: clean
	$(RM) $(TIEMPOS) $(GRAFICAS)
