#include <stdio.h>
#include <stdlib.h>

#include "fibonacci.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s n \n", argv[0]);
        return 1;
    }
    natural n = atol(argv[1]);
    printf("Fibonacci numbers (n = %lu)\n", n);
    puts("\nIterative algorithm:\n");
    for(natural k = 0; k <= n; ++k)
    {
        printf("F1(%lu) = %lu\n", k, f1(k));
    }
    puts("\nRecursive algorithm:\n");
    for (natural k = 0; k <= n; ++k)
    {
        printf("F2(%lu) = %lu\n", k, f2(k));
    }
    return 0;
}