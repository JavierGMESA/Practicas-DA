#include "damas.hpp"
#include <cassert>
#include <algorithm>

Tablero::Tablero(int n): columna_dama(n, n), 
                         columna_amenazada(n, false), 
                         diagonal_decreciente_amenazada(2*n-1, false), 
                         diagonal_creciente_amenazada(2*n-1, false),
                         n(n)
{

}

bool Tablero::amenazada(int i, int j) const
{
    //assert(valida(i, j));
    bool amenaza = false;
    if(columna_dama[i] != n) amenaza = true;
    else if(columna_amenazada[j]) amenaza = true;
    else if(diagonal_creciente_amenazada[i + j]) amenaza = true;
    else if(diagonal_decreciente_amenazada[i + n - 1 - j]) amenaza = true;
    return amenaza;
}

bool Tablero::valida(int k) const
{
    return (k >= 0 && k < n);
}

bool Tablero::valida(int i, int j) const
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void Tablero::coloca(int i, int j)
{
    assert(valida(i, j) && !amenazada(i, j));
    columna_dama[i] = j;
    columna_amenazada[j] =
        diagonal_creciente_amenazada[i + j] =
            diagonal_decreciente_amenazada[i + n - 1 - j] = true;
}

void Tablero::elimina(int i, int j)
{
    assert(valida(i, j));
    if(columna_dama[i] == j)
    {
        columna_dama[i] = n;
        columna_amenazada[j] = false;
        diagonal_creciente_amenazada[i + j] = false;
        diagonal_decreciente_amenazada[i + n -1 - j] = false;
    }
}

int Tablero::operator [](int i) const
{
    assert(valida(i));
    return columna_dama[i];
}

std::ostream& operator <<(std::ostream& fs, const Tablero& t)
{
    int dim = t.dimension();
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            if(t[i] != j)
            {
                fs << "-";
            }
            else
            {
                fs << "x";
            }
        }
        fs << std::endl;
    }
    return fs;
}

bool tablero_solucion(Tablero& t)
{
    int n_damas = 0;
    for(int i = 0; i < t.dimension(); ++i)
    {
        if(t[i] != t.dimension()) ++n_damas;
    }
    return (n_damas == t.dimension());
}

bool vuelta_atras1(std::vector<Tablero>& s, int k, std::list<Tablero>& soluciones)
{
    int n = s[k-1].dimension();
    //for(int i = 0; i < n; ++i)        //IMPORTANTE: NO HAY QUE COMPROBAR EN CADA FILA PUES SOLO HABRÁ UNA REINA POR FILA  
    bool solucion = false; 
    int j = 0;         
    while(j < n && !solucion)
    {
        if(!s[k-1].amenazada(k-1, j))
        {
            s[k] = s[k-1];
            s[k].coloca(k-1, j);

            if(tablero_solucion(s[k]))
            {
                //if(std::find(soluciones.begin(), soluciones.end(), s[k]) == soluciones.end())
                soluciones.push_back(s[k]);
                solucion = true;
            }
            else
            {
                solucion = vuelta_atras1(s, k + 1, soluciones);
            }
        }
        ++j;
    }
    return solucion;
}

void vuelta_atras2(std::vector<Tablero>& s, int k, std::list<Tablero>& soluciones)
//IMPORTANTE: NO SE DEBE LLEVAR UN CONTROL DE ESTADOS REPETIDOS PUES EL amenaza() Y EL completable() SE ENCARGAN DE PODAR
{
    int n = s[k-1].dimension();
    //for(int i = 0; i < n; ++i)        //IMPORTANTE: NO HAY QUE COMPROBAR EN CADA FILA PUES SOLO HABRÁ UNA REINA POR FILA            
    for(int j = 0; j < n; ++j)
    {
        if(!s[k-1].amenazada(k-1, j))
        {
            s[k] = s[k-1];
            s[k].coloca(k-1, j);

            if(tablero_solucion(s[k]))
            {
                if(std::find(soluciones.begin(), soluciones.end(), s[k]) == soluciones.end())
                soluciones.push_back(s[k]);
            }
            else
            {
                vuelta_atras2(s, k + 1, soluciones);
            }
        }
    }
}

std::list<Tablero> damas(Tablero& t)
{
    std::list<Tablero> soluciones;
    std::vector<Tablero> s(t.dimension() + 1, t);
    vuelta_atras2(s, 1, soluciones);
    return soluciones;
}

std::list<Tablero> damas2(Tablero& t)
{
    std::list<Tablero> soluciones;
    std::vector<Tablero> s(t.dimension() + 1, t);
    vuelta_atras1(s, 1, soluciones);
    return soluciones;
}

