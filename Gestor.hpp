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
	
	// Métodos para obtener cantidades (para mostrar en el menú)
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
	void CrearydibujarABB();
	// OPCIÓN L: Mostrar los datos de todos los socios ordenados por sus IDs de menor a mayor
	void MostrarABBSociosOrdenado();
	//Opción M: Mostrar los datos de todos los simpatizantes ordenados por sus IDs de menor a mayor (sin
	//incluir el aficionado almacenado en nodo ficticio).
	void mostrarSimpatizantesOrden();
	void mostrarSimpatizantesOrden(pnodoAbb nodo);
	//Opción N: Mostrar los datos de todos los aficionados recorriendo el ABB en inorden.
	void inOrden();
	void inOrden(pnodoAbb nodo);

	//Opción O: Buscar en el ABB y mostrar los siguientes 4 aficionados:
	//- El primer aficionado en acceder al estadio
	//- El último socio en acceder al estadio.
	//- El primer simpatizante en acceder al estadio.
	//- El último aficionado en acceder al estadio.
	void buscarEspeciales(
        Aficionado &primero,
        Aficionado &ultimoSocio,
        Aficionado &primerSimpatizante,
        Aficionado &ultimo);

	//Opción P: Contar el número de aficionados almacenados en el ABB cuyos ID’s son pares.
	void mostrarHojas();
	void mostrarHojas(pnodoAbb nodo);

	//Opción Q: mostrar los aficionados que se encuentran almacenados en un nodo hoja
	void eliminar(int id);

	//Opción R: Eliminar un aficionado indicado por su ID (que se pide desde consola). Mostrar el árbol antes
	//y después tras la eliminación de dicho aficionado.
	void 

private:
	Pila* pilaAficionados;
	Cola* colaSocios;
	Cola* colaSimpatizantes;
	Lista* listaAficionados;
	
	int contadorGeneracion;  // Para controlar el rango de IDs generados
};

#endif // GESTOR_HPP