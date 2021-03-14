#ifndef __AYED_LISTA_ENLAZADA__
#define __AYED_LISTA_ENLAZADA__

#include "./lista_interfaz.h"

#include <iostream>



namespace ayed {


 class Lista_Enlazada : public Lista {

	public:

	        Lista_Enlazada();

		void agregar_al_final(const ayed::Contacto &dato_a_agregar);
		void agregar_en(const ayed::Contacto &dato_a_agregar, unsigned posicion);   
         	void set_posicion(const ayed::Contacto &dato_a_agregar, unsigned posicion);
		void borrar_posicion (unsigned posicion); 	
		ayed::Contacto get_posicion (unsigned posicion);
		unsigned get_tamanio();
		bool is_vacia();                	

	        ~Lista_Enlazada();
 
	private: 

		Nodo_Contacto* primer_nodo = nullptr;
	        unsigned cantidad_nodos = 0;
		
		
 };
}


#endif