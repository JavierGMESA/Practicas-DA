#ifndef ORDENACION
#define ORDENACION

#include <algorithm>
#include <iostream>

template <typename I>
void ordenacion_simple(I i, I j)
{
    if(i != j)
    {
        for(I k = i + 1; k != j; ++k)
        {
            I x = k;
            while(x != i && *x < *(x - 1))
            {
                std::swap(*x, *(x - 1));
                --x;
            }
        }
    }
}

template <typename I> 
void ordenacion_fusion(I i, I j, int n0 = 1)
{
    int n = j - i;          //IMPORTANTE: j ES EL SIGUIENTE AL ÚLTIMO, POR LO QUE NO HAY QUE SUMAR 1
    if(n <= n0)
    {
        ordenacion_simple(i, j);
    }
    else
    {
        I k = i + n / 2;                //IMPORTANTE: j ES EL SIGUIENTE AL ÚLTIMO, POR LO QUE NO HAY QUE RESTAR 1
        ordenacion_fusion(i, k, n0);
        ordenacion_fusion(k, j, n0);
        std::inplace_merge(i, k, j);
    }
}

template <typename I> 
I pivote(I i, I j)
{
    I p = i;
    auto x = *i;
    for(I k = i + 1; k != j; ++k)
    {
        if(*k <= x)
        {
            p = p + 1;
            std::swap(*p, *k);
        }
    }
    *i = *p;
    *p = x;
    return p;
}


template <typename I> 
void ordenacion_rapida(I i, I j, int n0 = 1)
{
    int n = j - i;
    if(n <= n0)
    {
        ordenacion_simple(i, j);
    }
    else
    {
        I k = pivote(i, j);
        //std::cout << *k << std::endl;
        ordenacion_rapida(i, k, n0);
        ordenacion_rapida(k + 1, j, n0);
    }
}


#endif