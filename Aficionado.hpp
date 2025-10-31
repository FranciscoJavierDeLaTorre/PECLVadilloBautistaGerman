#ifndef AFICIONADO_HPP
#define AFICIONADO_HPP

class Aficionado
{
public:
	Aficionado();
	Aficionado(int ID, int hora_llegada);
	~Aficionado();
	
	int getHora();
	bool esSocio();
	void mostrar();
	int getID();
	
	void setID(int ID);
	void setHora_llegada(int hora);
	void setEs_socio(bool socio);

private:
	int 	ID;
	int 	hora_llegada;
	bool	es_socio;
};

#endif // AFICIONADO_HPP