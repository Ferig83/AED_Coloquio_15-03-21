#ifndef __AYED_PILA_ENLAZADA__
#define __AYED_PILA_ENLAZADA__

#include "./pila_interfaz.h"

#include <iostream>


namespace ayed {


 class Pila_Enlazada : public ayed::Pila {

	public:

	        Pila_Enlazada(const ayed::Undo &dato_a_agregar);
	        Pila_Enlazada();

		void push(const ayed::Undo &dato_a_agregar);
         	ayed::Undo pop();
		ayed::Undo peek();  
		bool is_vacia();
	        unsigned get_tamanio();              	

	        ~Pila_Enlazada();
 
	private: 

		Nodo_Undo* primer_nodo = nullptr;
	        unsigned cantidad_nodos = 0;	
		
 };

}

//-----------------------------------------------------------------------------

#endif


