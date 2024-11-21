#include "matriz.hpp"

// Constructor: matriz definida por una función.

matriz::matriz(size_t m, size_t n, double f(size_t i, size_t j)):
  m(m), n(n), x(std::valarray<double>(n), m)
{
  for (size_t i = 0; i < m; ++i)
    for (size_t j = 0; j < n; ++j)
      x[i][j] = f(i, j);
}

// Operador de multiplicación.

matriz operator *(const matriz& a, const matriz& b)
{
  matriz c(a.filas(), b.columnas());  // Matriz nula.
  for (size_t i = 0; i < a.filas(); ++i)
    for (size_t j = 0; j < b.columnas(); ++j)
      for (size_t k = 0; k < a.columnas(); ++k)
	c[i][j] += a[i][k] * b[k][j];
  return c;
}
