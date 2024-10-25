#include "fajo.hpp"

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;
istream& operator >>(istream& fe, fajo& f)
{
    return fe >> f.valor() >> f.unidades();
}

istream& operator >>(istream& fe, fajos& f)
{
    istream_iterator<fajo> ife(fe), fin;
    copy(ife, fin, back_inserter(f)); //inserto al final del vector
    return fe;
}

ostream& operator <<(ostream& fs, const fajo& f)
{
    return fs << f.unidades() << " billete"
        << (f.unidades() == 1 ? "" : "s") << " de " << f.valor(); //Si hay más de una unidad pongo una 's' en "billete"
}

ostream& operator <<(ostream& fs, const fajos& f)
{
    copy(begin(f), end(f), ostream_iterator<fajo>(fs, "\n"));
    return fs;
}

fajos::const_iterator select_fajo(const fajos& C)
{
    fajos::const_iterator i, res;
    res = C.begin();
    for(i = C.begin(); i != C.end(); ++i)
    {  
        if((*i).valor() >  (*res).valor())
        {
            res = i;
        }
    }
    return res;
}

int min(int a , int b)
{
    if(a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


fajos reintegrar(const fajos& caja, unsigned int cantidad)
{
    fajos S;
    unsigned int cambio, n_monedas;
    fajo a;
    cambio = cantidad;
    std::priority_queue<fajo> c(caja.begin(), caja.end());
    while(cambio != 0 && !c.empty())
    {
        a = c.top();
        c.pop();
        n_monedas = min(cambio/a.valor(), a.unidades());
        if(n_monedas > 0)
        {
            S.push_back(fajo(a.valor(), n_monedas));
            cambio -= (a.valor()) * n_monedas;
        }
    }
    if(cambio != 0)
    {
        return fajos(); //Si no se ha conseguido devolver el cambio se devuelve vacío para representarlo
    }
    else
    {
        return S;
    }
}