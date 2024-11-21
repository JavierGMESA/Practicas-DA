#include "tabla64.hpp"
#include <math.h>

int logaritmo_2(int n)
{
    if(n <= 1)
    {
        return 0;
    }
    else
    {
        return logaritmo_2(n / 2) + 1;
    }
}

std::vector<int> binario(int n, int tama)
{
    std::vector<int> res(tama, 0);
    int cuent = 0;
    for(int i = 0; i < tama; ++i)
    {
        if(cuent + pow(2, tama - i - 1) <= n)
        {
            res[i] = 1;
            cuent += pow(2, tama - i - 1);
        }
    }
    return res;
}

fila_tabla* tabla64(int numero)
{
    fila_tabla* tabla = new fila_tabla[numero];
    for(int i = 1; i <= numero; ++i)
    {
        tabla[i-1].n = i;
        tabla[i-1].logaritmo = logaritmo_2(i);
        tabla[i-1].binario = binario(i, tabla[i-1].logaritmo);
        if(i % 2 == 0)
        {
            tabla[i-1].productos = tabla[i-1].logaritmo;
        }
        else
        {
            tabla[i-1].productos = 2 * logaritmo_2(i + 1) - 2;
        }
    }
    return tabla;
}

using namespace std;
ostream& operator <<(ostream& os, const fila_tabla& t)
{
    os << t.n << "\t" << t.logaritmo << "\t";
    for(int i = 0; i < t.binario.size(); ++i)
    {
        os << t.binario[i];
    }
    os << "\t" << t.productos;
    return os;
}