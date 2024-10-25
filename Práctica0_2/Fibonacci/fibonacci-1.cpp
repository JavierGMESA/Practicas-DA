#include "natural.hpp"

// Cálcula el n-ésimo número de Fibonacci por el algoritmo recursivo trivial.

natural f(natural n)
{
  return n <= 1 ? n : f(n - 1) + f(n - 2);
}
