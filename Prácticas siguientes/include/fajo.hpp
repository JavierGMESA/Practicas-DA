#ifndef FAJO
#define FAJO

#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

class fajo {
public:
    fajo(): v{0}, u{0} {}
    fajo(unsigned int v, unsigned int u): v{v}, u{u} {}
    unsigned int valor() const { return v; }
    unsigned int& valor() { return v; }
    unsigned int unidades() const { return u; }
    unsigned int& unidades() { return u; }
private:
    unsigned int v, u; // Valor y número de unidades de cada billete.
};
using fajos = std::vector<fajo>;

inline bool operator < (fajo a, fajo b)
{
    if(a.valor() < b.valor())
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::istream& operator >>(std::istream& fe, fajo& f);
std::istream& operator >>(std::istream& fe, fajos& f);
std::ostream& operator <<(std::ostream& fs, const fajo& f);
std::ostream& operator <<(std::ostream& fs, const fajos& f);

fajos::const_iterator select_fajo(const fajos& C);
int min(int a , int b);
fajos reintegrar(const fajos& caja, unsigned int cantidad);

#endif