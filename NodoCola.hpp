#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include "Aficionado.hpp"

class NodoCola
{
public:
    NodoCola(Aficionado afic, NodoCola* sig = nullptr);
    ~NodoCola();

private:
    Aficionado aficionado;
    NodoCola* siguiente;
    friend class Cola;
};

typedef NodoCola* pnodoCola;

#endif // NODOCOLA_HPP