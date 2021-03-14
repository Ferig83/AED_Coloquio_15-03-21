#ifndef __AYED_COLA_ENLAZADA__
#define __AYED_COLA_ENLAZADA__


#include "./cola_interfaz.h"
#include <memory>

namespace ayed {


 class Cola_Enlazada : public ayed::Cola {

	public:

	        Cola_Enlazada(const ayed::Paciente &dato_a_agregar);
	        Cola_Enlazada();

		void queue(const ayed::Paciente &dato_a_agregar);
         	ayed::Paciente unqueue();
		ayed::Paciente frente();  
		bool is_vacia();
	        unsigned get_tamanio();              	

	        ~Cola_Enlazada();

 
	private: 

		Nodo_Paciente* primer_nodo = nullptr;
	        unsigned cantidad_nodos = 0;	
		
 };



}


//-----------------------------------------



#endif