// Clase para matrices de números en coma flotante y doble precisión.

#ifndef MATRIZ_HPP_
#define MATRIZ_HPP_

#include <valarray>

class matriz {
public:				
  explicit matriz(size_t m = 1, size_t n = 1, double y = 0.0);
  matriz(size_t m, size_t n, double f(size_t i, size_t j));
  size_t filas() const;
  size_t columnas() const;
  std::valarray<double>& operator [](size_t i);
  const std::valarray<double>& operator [](size_t i) const;
  matriz& operator +=(const matriz& a);
  matriz& operator -=(const matriz& a);
  matriz& operator *=(const matriz& a);
  friend matriz operator -(const matriz& a);
private:
  size_t m, n;
  std::valarray<std::valarray<double>> x;
};

// Prototipos de operadores externos no amigos que trabajan con matrices.

matriz operator +(const matriz& a);
matriz operator +(const matriz& a, const matriz& b);
matriz operator -(const matriz& a, const matriz& b);
matriz operator *(const matriz& a, const matriz& b);

// Definiciones en línea.

#include "matriz-inline.hpp"

#endif
