#include "fibonacci.h"

natural f1(natural n)
{
    natural a = 0, b = 1;
    while(n > 1)
    {
        const natural c = a + b;
        a = b;
        b = c;
        --n;
    }
    return n ? b : a;
}