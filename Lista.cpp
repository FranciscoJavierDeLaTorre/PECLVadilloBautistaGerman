#include "Lista.hpp"
#include <iostream>
using namespace std;

Lista::Lista()
{
    primero = NULL;
    longitud = 0;
}

void Lista::insertarOrdenado(Aficionado afic)
{
    pnodoLista nuevo = new NodoLista(afic);
    pnodoLista actual = primero;
    pnodoLista anterior = NULL;
    
    // Buscar la posición correcta para insertar
    // Ordenado por hora de llegada (menor a mayor)
    while(actual != NULL && actual->aficionado.getHora() < afic.getHora())
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    // Insertar al principio
    if(anterior == NULL)
    {
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    // Insertar en medio o al final
    else
    {
        anterior->siguiente = nuevo;
        nuevo->siguiente = actual;
    }
    
    longitud++;
}

void Lista::mostrar()
{
    pnodoLista aux = primero;
    
    if(!aux)
    {
        cout << "\tLa lista está vacía." << endl;
        return;
    }
    cout << "\n\tContenido de la lista de aficionados:" << endl;
    cout << "\t" << string(60, '-') << endl;
    
    int contador = 1;
    while(aux)
    {
        cout << "\t" << contador << ". ";
        aux->aficionado.mostrar();
        aux = aux->siguiente;
        contador++;
    }
    cout << "\t" << string(60, '-') << endl;
    cout << "\tTotal de aficionados en la lista: " << longitud << endl;
}

int Lista::getLongitud()
{
    return longitud;
}

bool Lista::estaVacia()
{
    return primero == NULL;
}

void Lista::vaciar()
{
    pnodoLista aux;
    while(primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    longitud = 0;
}

Aficionado Lista::getPrimero()
{
    if(primero)
        return primero->aficionado;
    
    // Retornar un aficionado vacío si la lista está vacía
    return Aficionado();
}

Aficionado Lista::getUltimo()
{
    if(!primero)
        return Aficionado();
    
    pnodoLista aux = primero;
    while(aux->siguiente)
    {
        aux = aux->siguiente;
    }
    
    return aux->aficionado;
}

Aficionado Lista::getUltimoSocio()
{
    if(!primero)
        return Aficionado();
    
    pnodoLista aux = primero;
    Aficionado ultimoSocio;
    bool encontrado = false;
    
    // Recorrer la lista buscando el último socio
    while(aux)
    {
        if(aux->aficionado.esSocio())
        {
            ultimoSocio = aux->aficionado;
            encontrado = true;
        }
        aux = aux->siguiente;
    }
    
    if(encontrado)
        return ultimoSocio;
    
    return Aficionado();
}

Aficionado Lista::getPrimerSimpatizante()
{
    if(!primero)
        return Aficionado();
    
    pnodoLista aux = primero;
    
    // Recorrer la lista buscando el primer simpatizante
    while(aux)
    {
        if(!aux->aficionado.esSocio())
        {
            return aux->aficionado;
        }
        aux = aux->siguiente;
    }
    
    return Aficionado();
}

Lista::~Lista()
{
    vaciar();
}