#include "particion.hpp"

Particion::Particion(int n): p{n}
{
    for(int i = 0; i < n; ++i)
    {
        p[i] = -1;
    }
}

int Particion::buscar(int i) const
{
    int raiz, a, b;
    raiz = a = i;
    while(p[raiz] >= 0)
    {
        raiz = p[raiz];
    }
    return raiz;
}

void Particion::unir(int i, int j)
{
    if(p[i] < p[j])
    {
        p[j] = i;
        --p[i];
    }
    else
    {
        p[i] = j;
        --p[j];
    }
}