#ifndef POTENCIAMATRIZ
#define POTENCIAMATRIZ

#include "matriz.hpp"

inline double f(std::size_t i, std::size_t j)
{
    if(i == j)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

matriz potencia_iterativa(matriz m, int expo);

matriz potencia_rapida(matriz m, int expo);

#endif