#include <iostream>
#include "NodoCola.hpp"

NodoCola::NodoCola(Aficionado afic, NodoCola* sig)
{
    aficionado = afic;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
}