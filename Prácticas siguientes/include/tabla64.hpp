#ifndef TABLA64
#define TABLA64

#include <vector>
#include <iostream>

struct fila_tabla
{
    int n;
    int logaritmo;
    std::vector<int> binario;
    int productos;
};

int logaritmo_2(int n);

std::vector<int> binario(int n, int tama);

fila_tabla* tabla64(int numero);

using namespace std;
ostream& operator <<(ostream& os, const fila_tabla& t);

#endif