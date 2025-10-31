#include <iostream>
#include "Aficionado.hpp"
using namespace std;


class NodoPila
{
public:
    NodoPila(Aficionado afic, NodoPila* sig = NULL);
    ~NodoPila();

private:
    Aficionado valor;
    NodoPila* siguiente;
    friend class Pila;
};

typedef NodoPila* pnodoPila;