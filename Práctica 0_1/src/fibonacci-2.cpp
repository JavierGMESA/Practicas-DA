#include "natural.hpp"

// Cálcula el n-ésimo número de Fibonacci por programación dinámica.

natural f(natural n)
{
  natural a = 0, b = 1;
  while (n > 1) {
    const natural c = a + b;
    a = b;
    b = c;
    --n;
  }
  return n ? b : a;
}
