#ifndef LISTA_HPP
#define LISTA_HPP
#include "Aficionado.hpp"
#include "NodoLista.hpp"

class Lista
{
public:
    Lista();
    ~Lista();
    
    void insertarOrdenado(Aficionado afic);
    void mostrar();
    int getLongitud();
    bool estaVacia();
    void vaciar();
    
    // Métodos para buscar aficionados específicos (Opción I)
    Aficionado getPrimero();
    Aficionado getUltimo();
    Aficionado getUltimoSocio();
    Aficionado getPrimerSimpatizante();

private:
    pnodoLista primero;
    int longitud;
};

#endif // LISTA_HPP