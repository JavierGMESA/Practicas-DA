#include <iostream>


#include "fajo.hpp"
#include "particion.hpp"

void P1ej1();
void P1ej2();

int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;
    P1ej1();
    P1ej2();
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