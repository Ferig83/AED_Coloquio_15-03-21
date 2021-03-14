#ifndef __AYED_COLA_CONTIGUA__
#define __AYED_COLA_CONTIGUA__

#include "./cola_interfaz.h"
#include <cstddef> // std::size_t

namespace ayed {

class Cola_Contigua : public ayed::Cola {

	public:

	        Cola_Contigua(const ayed::Paciente &dato_a_agregar, const std::size_t cantidad_total);
	        Cola_Contigua(std::size_t cantidad_total);

		void queue(const ayed::Paciente &dato_a_agregar);
         	ayed::Paciente unqueue();
		ayed::Paciente frente();  
		bool is_vacia();
	        unsigned get_tamanio();              	

	        ~Cola_Contigua();
 
	private: 

		ayed::Paciente* arreglo = nullptr;
		unsigned cantidad_elementos = 0;	
		std::size_t tamanio = 0;
		
 };


}




#endif