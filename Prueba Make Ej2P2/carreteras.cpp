#include "carreteras.hpp"

#include <iterator>

using namespace std;

const double MatrizPesos::INFINITO = std::numeric_limits<double>::max();

ostream& operator <<(ostream& os, const std::map<std::size_t, std::string>& m)
{
    for(auto a: m)
    {
        os << a.first << "\t" << a.second << endl;
    }
    return os; //IMPORTANTE: NO OLVIDARSE CARAJO
}

ostream& operator <<(ostream& os, const std::list<std::string> l)
{
    copy(begin(l), end(l), ostream_iterator<string>(os, "\n"));
}

double suma(double a, double b)
{
    if(a == MatrizPesos::INFINITO || b == MatrizPesos::INFINITO)
    {
        return MatrizPesos::INFINITO;
    }
    else
    {
        return a + b;
    }
}

MatrizCaminos Floyd(MatrizPesos& p)
{
    MatrizCaminos c(p.Grado());
    int n = p.Grado();
    for(int i = 0; i < n; ++i)
    {
        p[i][i] = 0;
        c[i] = std::vector<int>(p.Grado(), i); //INICIALIZAMOS TODA LA FILA AL INICIO
    }
    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                double ikj = suma(p[i][k], p[k][j]);
                if(ikj < p[i][j])
                {
                    p[i][j] = ikj;
                    c[i][j] = k;
                }
            }
        }
    }
    return c;
}

Camino CaminoMinimo(const MatrizCaminos& c, std::size_t i, std::size_t j)
{
    Camino l1, l2;
    int u = c[i][j];
    if(u != i)      //IMPORTANTE: SI c[i][j] == i SIGNIFICA QUE ES CAMINO DIRECTO, PUES NO HAY NODO INTERMEDIO
                    //(EL ÚLTIMO NODO QUE SE RECORRE HASTA LLEGAR A j ES i)
    {
        l1 = CaminoMinimo(c, i, u);
        l1.push_back(u);
        l2 = CaminoMinimo(c, u, j);
        l1.splice(l1.end(), l2);
    }
    return l1;
}