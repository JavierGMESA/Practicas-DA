#include "mochilaDiscreta.hpp"

#include <iterator>

using namespace std;
istream& operator >>(istream& is, Objeto& o)
{
    return is >> o.Nombre() >> o.Peso() >> o.Valor();
}

istream& operator >>(istream& is, Objetos& o)
{
    istream_iterator<Objeto> ife(is), fin;
    copy(ife, fin, back_inserter(o));
    return is;
}
ostream& operator <<(ostream& os, const Objeto& o)
{
    return os << o.Nombre() << "\t" << o.Peso() << "\t" << o.Valor();
}
ostream& operator <<(ostream& os, const Objetos& o)
{
    copy(begin(o), end(o), ostream_iterator<Objeto>(os, "\n"));
    return os;
}

Objetos mochila(const Objetos& objetos, unsigned int capacidad)
{
    // Tabla de subproblemas resueltos (TSP).
    using Indice = Objetos::size_type;
    using TSP = std::vector<std::vector<double>>;
    const Indice n = objetos.size();
    TSP tsp(n, TSP::value_type(capacidad + 1));

    // Cálculo de los valores de la TSP.
    int i, j;
    for(i = 0; i <= capacidad; ++i)
    {
        if(objetos[0].Peso() > i)
        {
            tsp[0][i] = 0;
        }
        else
        {
            tsp[0][i] = objetos[0].Valor();
        }
    }
    for(i = 1; i < n ; ++i)
    {
        for(j = 0; j <= capacidad ; ++j)
        {
            if(objetos[i].Peso() > j)
            {
                tsp[i][j] = tsp[i-1][j];
            }
            else
            {
                tsp[i][j] = maximo(tsp[i-1][j], objetos[i].Valor() + tsp[i-1][j-objetos[i].Peso()]);
            }
        }
    }
    // Recuperación de la solución a partir de la TSP.
    Objetos solucion;
    i = n - 1;
    j = capacidad;
    while(i > 0)
    {
        if(tsp[i][j] != tsp[i-1][j])
        {
            solucion.push_back(objetos[i]);
            j -= objetos[i].Peso();
            --i;
        }
        else
        {
            --i;
        }
    }
    if(tsp[i][j] != 0)
    {
        solucion.push_back(objetos[i]);
    }
    return solucion;
}