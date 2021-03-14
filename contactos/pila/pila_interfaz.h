#ifndef __AYED_PILA_INTERFAZ__
#define __AYED_PILA_INTERFAZ__


#include "../contacto/contacto.h"

namespace ayed {

 class Pila { 
	public:

		virtual void push(const ayed::Undo &dato_a_agregar) = 0; 
         	virtual ayed::Undo pop() = 0;
		virtual ayed::Undo peek() = 0;
		virtual bool is_vacia() = 0;
	        virtual unsigned get_tamanio() = 0; 
		
		virtual ~Pila() { }  //= default;
   
 };  


}


#endif