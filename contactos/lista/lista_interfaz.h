#ifndef __AYED_LISTA_INTERFAZ__
#define __AYED_LISTA_INTERFAZ__


#include "../contacto/contacto.h"

namespace ayed {

 class Lista { 

	public:


		virtual void agregar_al_final(const ayed::Contacto &dato_a_agregar) = 0;
		virtual void agregar_en(const ayed::Contacto &dato_a_agregar, unsigned posicion) = 0;   
         	virtual void set_posicion(const ayed::Contacto &dato_a_agregar, unsigned posicion) = 0;
		virtual void borrar_posicion (unsigned posicion) = 0; 	
		virtual ayed::Contacto get_posicion (unsigned posicion) = 0;
		virtual unsigned get_tamanio() = 0;
		virtual bool is_vacia() = 0;                	

	        virtual ~Lista() { }


   
 };  


}


#endif