#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Aficionado.hpp"
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
	int AficionadosEnArbol();
	
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

private:
	Pila* pilaAficionados;
	Cola* colaSocios;
	Cola* colaSimpatizantes;
	Lista* listaAficionados;
	
	int contadorGeneracion;  // Para controlar el rango de IDs generados
};

#endif // GESTOR_HPP