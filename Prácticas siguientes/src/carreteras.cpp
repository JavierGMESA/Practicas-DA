#include "carreteras.hpp"

#include <iterator>

using namespace std;
ostream& operator <<(ostream& os, const std::map<std::size_t, std::string>& m)
{
    for(auto a: m)
    {
        os << a.first << "\t" << a.second << endl;
    }
}

ostream& operator <<(ostream& os, const std::list<std::string> l)
{
    copy(begin(l), end(l), ostream_iterator<string>(os, "\n"));
}

MatrizCaminos Floyd(MatrizPesos& p)
{
    MatrizCaminos c(p.Grado());
    for(int i = 0; i < p.Grado(); ++i)
    {
        c[i] = std::vector<int>(p.Grado(), i); //INICIALIZAMOS TODA LA FILA AL INICIO
    }
    
}

Camino CaminoMinimo(const MatrizCaminos& c, std::size_t i, std::size_t j)
{
    Camino l1, l2;
    int u = c[i][j];
    if(u != j)
    {
        l1 = CaminoMinimo(c, i, u);
        l1.push_back(u);
        l2 = CaminoMinimo(c, u, j);
        l1.splice(l1.end(), l2);
    }
    return l1;
}