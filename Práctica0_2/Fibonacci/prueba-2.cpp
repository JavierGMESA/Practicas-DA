#include <iostream>
#include "natural.hpp"
#include "cronometro.hpp"

natural f(natural n);

// Genera la tabla de tiempos frente a n.

int main()
{
  cronometro c;
  for (natural n = 0; n <= 50; ++n) {
    const int r = 1000;
    c.activar();
    for (int i = 0; i < r; ++i)
      f(n);
    c.parar();
    std::cout << n << '\t' << c.tiempo() / r << std::endl;
  }
}
