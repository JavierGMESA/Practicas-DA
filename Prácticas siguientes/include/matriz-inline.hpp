// Notas:
//
// Este fichero contiene definiciones en línea de funciones y operadores
// relacionados con la clase matriz, y ya se incluye en la cabecera
// "matriz.h". Por lo tanto, no debe incluirse ni compilarse por separado.

// Constructores: matriz constante.

inline matriz::matriz(size_t m, size_t n, double y):
  m(m), n(n), x(std::valarray(y, n), m)
{}

// Dimensión.

inline size_t matriz::filas() const
{ return m; }

inline size_t matriz::columnas() const
{ return n; }

// Operadores de índice.

inline std::valarray<double>& matriz::operator [](size_t i)
{ return x[i]; }

inline const std::valarray<double>& matriz::operator [](size_t i) const
{ return x[i]; }

// Operadores de auto-suma, auto-resta y auto-multiplicación.

inline matriz& matriz::operator +=(const matriz& a)
{
  x += a.x;
  return *this;
}

inline matriz& matriz::operator -=(const matriz& a)
{
  x -= a.x;
  return *this;
}

inline matriz& matriz::operator *=(const matriz& a)
{ return *this = *this * a; }

// Operadores de signo.

inline matriz operator +(const matriz& a)
{ return a; }

inline matriz operator -(const matriz& a)
{
  matriz c(a);
  c.x = -c.x;
  return c;
}

// Operadores de suma y resta.

inline matriz operator +(const matriz& a, const matriz& b)
{ return matriz(a) += b; }

inline matriz operator -(const matriz& a, const matriz& b)
{ return matriz(a) -= b; }
