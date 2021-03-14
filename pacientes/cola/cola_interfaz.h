#ifndef __AYED_COLA_INTERFAZ__
#define __AYED_COLA_INTERFAZ__



#include "../paciente/paciente.h"

namespace ayed {

 class Cola { 
	public:

		virtual void queue(const ayed::Paciente &dato_a_agregar) = 0; 
         	virtual ayed::Paciente unqueue() = 0;
		virtual ayed::Paciente frente() = 0;
		virtual bool is_vacia() = 0;
	        virtual unsigned get_tamanio() = 0;
 
		virtual ~Cola() { };  
   
 };  


}


#endif