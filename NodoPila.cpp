#include "NodoPila.hpp"

NodoPila::NodoPila(Aficionado afic, NodoPila* sig)
{
    valor = afic;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
}