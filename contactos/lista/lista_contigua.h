#ifndef __AYED_LISTA_CONTIGUA__
#define __AYED_LISTA_CONTIGUA__


#include <iostream>
#include <cstddef> // std::size_t
#include "./lista_interfaz.h"


namespace ayed {

 class Lista_Contigua : public Lista {


	public:

	        Lista_Contigua(std::size_t tamanio);

		void agregar_al_final(const ayed::Contacto &dato_a_agregar);
		void agregar_en(const ayed::Contacto &dato_a_agregar, unsigned posicion);   
		void borrar_posicion (unsigned posicion); 	
		bool is_vacia();                	


	       	void set_posicion(const ayed::Contacto &dato_a_agregar, unsigned posicion);
		ayed::Contacto get_posicion(unsigned posicion);
		unsigned get_tamanio();
		              	
	        ~Lista_Contigua();
 
	private: 

		ayed::Contacto* arreglo = nullptr;
		unsigned cantidad_elementos = 0;
		std::size_t tamanio = 0;
		
 };

}


#endif