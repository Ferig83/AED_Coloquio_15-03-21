#ifndef __AYED_CONTACTO__
#define __AYED_CONTACTO__

#include <string>

namespace ayed {


 class Contacto {

	  public:	

	  std::string nombre = "";
	  std::string apellido = "";
	  std::string telefono = "";
	  std::string direccion = "";
          bool operator == (const Contacto& contacto) {
	    return (nombre == contacto.nombre) && (apellido == contacto.apellido) && (telefono == contacto.telefono) && (direccion == contacto.direccion);	
	  }
	
  };

 const Contacto CONTACTO_NULO;

 class Nodo_Contacto {

	private:

	  Nodo_Contacto() { }
	  Nodo_Contacto* siguiente_nodo;
	  ayed::Contacto dato;
	  friend class Lista_Enlazada;
	  friend class Pila_Enlazada;


 };




class Undo {

	public:
		void cargar_undo(ayed::Contacto &contacto, unsigned posicion_previa) {
		  this->contacto = contacto;
		  this->posicion_previa = posicion_previa;
		} 


          bool operator == (const Undo& undo) {
	    return (contacto == undo.contacto) && (posicion_previa == undo.posicion_previa);	
	  }


		ayed::Contacto contacto;
		unsigned posicion_previa = 0;
	
			
};

 const Undo UNDO_NULO;



 class Nodo_Undo {

	private:

		Nodo_Undo() { }
		Nodo_Undo* siguiente_nodo;
		ayed::Undo dato;
		friend class Pila_Enlazada;
	

 };



}



#endif