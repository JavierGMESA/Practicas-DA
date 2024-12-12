#include <iostream>
#include <map>
#include <random>
#include <list>

#include "damas.hpp"

void P4ej2();

int main() {
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
    P4ej2();

    std::cout << std::endl << std::endl << "System pause" << std::endl;
}



void P4ej2()
{
    Tablero t(6);
    std::list<Tablero> soluciones = damas(t);
    int i = 1;
    for(auto s: soluciones)
    {
        std::cout << "Solución " << i << ":" << std::endl;
        std::cout << s << std::endl << std::endl;
        ++i;
    }
}
