#include "NodoPila.hpp"
#include <iostream>
#include "Aficionado.hpp"
using namespace std;

class Pila
{
public:
    Pila();
    ~Pila();
    void insertar(Aficionado afic);
    Aficionado extraer();
    Aficionado cima();
    void mostrar();
    int getLongitud();

private:
    pnodoPila ultimo;
    int longitud;
};