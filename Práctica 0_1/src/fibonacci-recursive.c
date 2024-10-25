#include "fibonacci.h"

natural f2(natural n)
{
    if(n < 2)
    {
        return n;
    }
    else
    {
        return f2(n - 1) + f2(n - 2);
    }
}