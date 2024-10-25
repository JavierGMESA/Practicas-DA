#ifndef PARTICION
#define PARTICION

#include <vector>

class Particion
{
public:
    Particion(int n);
    int buscar(int i) const;
    void unir(int i, int j);
private:
    std::vector<int> p;
};

#endif