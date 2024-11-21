#include "potenciaMatriz.hpp"

matriz potencia_iterativa(matriz m, int expo)
{
    matriz res = m;
    for(int i = 1; i < expo; ++i)
    {
        res *= m;
    }
    return res;
}

matriz potencia_rapida(matriz m, int expo)
{
    if(expo == 0)
    {
        return matriz(m.filas(), m.columnas(), f);
    }
    else if(expo == 1)
    {
        return m;
    }
    else if(expo % 2 == 0)
    {
        return potencia_rapida(m * m, expo / 2);
    }
    else
    {
        return m * potencia_rapida(m, expo - 1);
    }
}