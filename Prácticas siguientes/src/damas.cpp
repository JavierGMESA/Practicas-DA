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

std::list<Tablero> vuelta_atras(Tablero& t, std::list<Tablero>& cerrados)
{
    int n = t.dimension();
    std::list<Tablero> soluciones;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {

            //std::cout << "fila " << i << " columna " << j << std::endl;

            Tablero nuevo(t);
            if(!nuevo.amenazada(i, j))
            {
                nuevo.coloca(i, j);
                bool cerrado = false;
                //std::list<Tablero>::iterator it = cerrados.begin();
                //while(it != cerrados.end() && !cerrado)
                //{
                //    int k = 0;
                //    bool coincidencia = true;
                //    while(k < n && coincidencia)
                //    {
                //        if((*it)[k] != nuevo[k]) coincidencia = false;
                //        ++k;
                //    }
                //    if(coincidencia)
                //    {
                //        cerrado = true;
                //    }
                //    ++it;
                //}

                std::list<Tablero>::iterator it = std::find(cerrados.begin(), cerrados.end(), nuevo);
                if(it == cerrados.end())
                {
                    cerrados.push_back(nuevo);

                    std::cout << nuevo << std::endl;

                    if(tablero_solucion(nuevo))
                    {
                        soluciones.push_back(nuevo);
                    }
                    else
                    {
                        std::list<Tablero> sol = vuelta_atras(nuevo, cerrados);
                        soluciones.splice(soluciones.end(), sol);
                    }
                }
            }
        }
    }
    return soluciones;
}

std::list<Tablero> damas(Tablero& t)
{
    std::list<Tablero> cerrados;
    return vuelta_atras(t, cerrados);
}

