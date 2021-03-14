#ifndef __AYED_PILA_CONTIGUA__
#define __AYED_PILA_CONTIGUA__

#include "./pila_interfaz.h"

#include <iostream>


namespace ayed {

 class Pila_Contigua : public ayed::Pila {

    public:
	
	Pila_Contigua(const ayed::Undo &dato_a_agregar, std::size_t cantidad_total);
	Pila_Contigua(std::size_t cantidad_total);
	~Pila_Contigua();

	void push(const ayed::Undo &dato_a_agregar);
	ayed::Undo pop();
	ayed::Undo peek();

	bool is_vacia();
	unsigned get_tamanio();

     private:
	
	ayed::Undo* arreglo = nullptr;
	unsigned cantidad_elementos = 0;	
	std::size_t cantidad_elementos_total = 0;


};

	
}


#endif