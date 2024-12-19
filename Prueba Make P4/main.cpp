#include <iostream>
#include <map>
#include <random>
#include <list>
#include <charconv>
#include <cstdlib>
#include <cstring>

#include "damas.hpp"

void P4ej2(int n);
void P4ej5(int n);

int main(int argc, char* argv[]) {
    //P1ej1();
    //P1ej2();
    //P1ej3();
    //P1ej4();
    //P1ej5();

    //P2ej1();
    //P2ej2();
    
    //P3ej1();
    //P3ej2();
    //P3ej4();
    //P3ej5();
    //P3ej6();
    //P3ej7();

    //P4ej1();

    int n;
    auto result = std::from_chars(argv[1], argv[1] + std::strlen(argv[1]), n);
    if (result.ec != std::errc() || n <= 0) {
        std::cerr << "Error: El tamaño del tablero debe ser un entero positivo." << std::endl;
    }
    else
    {
        //std::cout << n << std::endl;
        //P4ej2(n);
        P4ej5(n);
    }

    //std::cout << std::endl << std::endl << "System pause" << std::endl;
}



void P4ej2(int n)
{
    Tablero t(n);
    std::list<Tablero> soluciones = damas(t);
    int i = 1;
    for(auto s: soluciones)
    {
        std::cout << "Solución " << i << ":" << std::endl;
        std::cout << s << std::endl << std::endl;
        ++i;
    }
}

void P4ej5(int n)
{
    Tablero t(n);
    std::list<Tablero> soluciones = damas2(t);
    int i = 1;
    for(auto s: soluciones)
    {
        std::cout << "Solución " << i << ":" << std::endl;
        std::cout << s << std::endl << std::endl;
        ++i;
    }
}
