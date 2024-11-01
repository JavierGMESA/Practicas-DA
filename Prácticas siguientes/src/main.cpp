#include <iostream>

#include "cronometro.hpp"

#include "fajo.hpp"
#include "particion.hpp"
#include "grafo-ponderado.hpp"
#include "kruskal.hpp"

void P1ej1();
void P1ej2();
void P1ej3();
void P1ej4();
void P1ej5();

int main() {
    //P1ej1();
    //P1ej2();
    P1ej3();
    P1ej4();

    std::cout << std::endl << std::endl << "System pause" << std::endl;
}

void P1ej1()
{
    std::ifstream datos("caja.dat");
    fajos caja;
    datos >> caja;
    std::cout << caja << std::endl;

    fajos resultado = reintegrar(caja, 120);
    std::cout << resultado << std::endl;
}

void P1ej2()
{
    Particion P(8);
    P.unir(0, 1);
    P.unir(P.buscar(0), 2);
    std::cout << P.buscar(2) << " " << P.buscar(0) << std::endl;
}

void P1ej3()
{
    using namespace std;
    GrafoPonderado<int> G;
    ifstream datos("grafo.dat"); //IMPORTANTE: LECTURA DE FICHERO
    datos >> G;
    cout << G << endl;

    cout << Kruskal1(G) << endl;
}

void P1ej4()
{
    GrafoPonderado<int> g;
    std::ifstream datos("grafo.dat"); //IMPORTANTE: LECTURA DE FICHERO
    datos >> g;
    std::cout << g << std::endl;

    GrafoPonderado g1 = Kruskal2(g);
    std::cout << g1 << std::endl;
}

void P1ej5()
{
    cronometro crono;
    GrafoPonderado<int> g;
    std::ifstream datos("grafo.dat"); //IMPORTANTE: LECTURA DE FICHERO
    datos >> g;

    crono.activar();
    GrafoPonderado g1 = Kruskal1(g);
    crono.parar();
    std::cout << "El tipo en la preordenacion ha sido " << crono.tiempo() << std::endl;

    crono.activar();
    GrafoPonderado g2 = Kruskal2(g);
    crono.parar();
    std::cout << "El tipo con los montículos ha sido " << crono.tiempo() << std::endl;
}