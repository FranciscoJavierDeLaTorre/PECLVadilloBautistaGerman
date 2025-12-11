#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Aficionado.hpp"
#include "Arbol.hpp"
#include <cstdlib>
#include <ctime>

class Gestor
{
public:
    Gestor();
    ~Gestor();
    
    // Métodos para obtener cantidades
    int AficionadosEnPila();
    int SociosEnCola();
    int SimpatizantesEnCola();
    int AficionadosEnLista();
    
    // Opción A: Generar 10 aficionados aleatorios
    void genera10Aficionados();
    
    // Opción B: Mostrar aficionados de la pila
    void muestraAficionados();
    
    // Opción C: Borrar aficionados de la pila
    void borraAficionadosPila();
    
    // Opción D: Encolar aficionados (de pila a colas)
    void encolarAficionados();
    
    // Opción E: Mostrar cola de socios
    void muestraSociosCola();
    
    // Opción F: Mostrar cola de simpatizantes
    void muestraSimpatizantesCola();
    
    // Opción G: Borrar aficionados de ambas colas
    void borraAficionadosColas();
    
    // Opción H: Enlistar aficionados (de colas a lista ordenada)
    void enlistarAficionados();
    
    // Opción I: Buscar aficionados específicos en la lista
    void buscarAficionados();
    
    // Opción J: Reiniciar el programa
    void reiniciar();
    
    // Opción K: Crear y dibujar ABB
    void crearYdibujarABB();
    
    // Opción L: Mostrar socios ordenados por ID
    void mostrarSociosOrdenadosID();
    
    // Opción M: Mostrar simpatizantes ordenados por ID
    void mostrarSimpatizantesOrdenadosID();
    
    // Opción N: Mostrar todos en inorden
    void mostrarInOrden();
    
    // Opción O: Buscar aficionados especiales en ABB
    void buscarAficionadosABB();
    
    // Opción P: Contar IDs pares
    void contarIDsPares();
    
    // Opción Q: Mostrar hojas del ABB
    void mostrarHojasABB();
    
    // Opción R: Eliminar aficionado del ABB
    void eliminarAficionadoABB();

private:
    Pila* pilaAficionados;
    Cola* colaSocios;
    Cola* colaSimpatizantes;
    Lista* listaAficionados;
    Arbol* arbolAficionados;
    
    int contadorGeneracion;
};

#endif // GESTOR_HPP