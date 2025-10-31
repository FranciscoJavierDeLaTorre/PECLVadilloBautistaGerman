#include "Aficionado.hpp"
#include <iostream>
using namespace std;

// Constructor por defecto
Aficionado::Aficionado()
{
	this->ID = 0;
	this->hora_llegada = 0;
	this->es_socio = false;
}

// Constructor con parámetros
Aficionado::Aficionado(int ID, int hora_llegada)
{
	this->ID = ID;
	this->hora_llegada = hora_llegada;
	
	// Si el ID es par, es socio; si es impar, es simpatizante
	if(ID % 2 == 0)
		this->es_socio = true;
	else
		this->es_socio = false;
}

Aficionado::~Aficionado()
{
}

// Getters
int Aficionado::getHora()
{
	return this->hora_llegada;
}

bool Aficionado::esSocio()
{
	return this->es_socio;
}

int Aficionado::getID()
{
	return this->ID;
}

// Setters
void Aficionado::setID(int ID)
{
	this->ID = ID;
}

void Aficionado::setHora_llegada(int hora)
{
	this->hora_llegada = hora;
}

void Aficionado::setEs_socio(bool socio)
{
	this->es_socio = socio;
}

// Método para mostrar la información del aficionado
void Aficionado::mostrar()
{
	cout << "ID: " << ID 
	     << " | Hora: 18:" << (hora_llegada < 10 ? "0" : "") << hora_llegada 
	     << " | Tipo: " << (es_socio ? "Socio" : "Simpatizante") << endl;
}