#include "./lista_enlazada.h"


ayed::Lista_Enlazada::Lista_Enlazada() {
  primer_nodo = nullptr;
}

//-----------------------------------------------------------------------------

ayed::Lista_Enlazada::~Lista_Enlazada() {

   while (cantidad_nodos != 0) {
      borrar_posicion(0);   
      std::cout << "\nNodo lista enlazada borrado desde el destructor";
   }

}

//-----------------------------------------------------------------------------

void ayed::Lista_Enlazada::agregar_al_final(const ayed::Contacto &dato_a_agregar) {

  agregar_en(dato_a_agregar, cantidad_nodos);
   
}


void ayed::Lista_Enlazada::agregar_en(const ayed::Contacto &dato_a_agregar, unsigned posicion) {

   ayed::Nodo_Contacto* nodo_nuevo = new ayed::Nodo_Contacto; 
   nodo_nuevo->dato = dato_a_agregar;

   if (primer_nodo == nullptr) {
      primer_nodo = nodo_nuevo;
      nodo_nuevo->siguiente_nodo = nullptr;     
   } else {

      if (posicion == 0) {
         nodo_nuevo->siguiente_nodo = primer_nodo;
         primer_nodo = nodo_nuevo;

      } else {

        Nodo_Contacto* nodo_siguiente_al_nuevo; 
        Nodo_Contacto* arreglo_nodo = primer_nodo;
        for (unsigned i = 0; i < posicion-1; ++i) {
           arreglo_nodo = arreglo_nodo->siguiente_nodo;
        } 
        nodo_siguiente_al_nuevo = arreglo_nodo->siguiente_nodo;
        nodo_nuevo->siguiente_nodo = nodo_siguiente_al_nuevo;
        arreglo_nodo->siguiente_nodo = nodo_nuevo;   
      }
   }   
   ++cantidad_nodos;

}

void ayed::Lista_Enlazada::set_posicion(const ayed::Contacto &dato_a_agregar, unsigned posicion) {

   Nodo_Contacto* arreglo_nodo = primer_nodo;
   for (unsigned i = 0; i < posicion; ++i) {
      arreglo_nodo = arreglo_nodo->siguiente_nodo;
   }
   arreglo_nodo->dato = dato_a_agregar;

}

void ayed::Lista_Enlazada::borrar_posicion(unsigned numero_del_nodo) {

   if (primer_nodo != nullptr) {
      Nodo_Contacto* nodo_a_borrar;
    
      if (numero_del_nodo == 0) {
        nodo_a_borrar = primer_nodo;
        primer_nodo = primer_nodo->siguiente_nodo;


      } else {

        Nodo_Contacto* arreglo_nodo = primer_nodo;
            
        for (unsigned i = 0; i < numero_del_nodo-1; ++i) {
           arreglo_nodo = arreglo_nodo->siguiente_nodo;
        } 

        nodo_a_borrar = arreglo_nodo->siguiente_nodo;
        arreglo_nodo->siguiente_nodo = nodo_a_borrar->siguiente_nodo;
      }
        delete nodo_a_borrar; 
        cantidad_nodos--;
 
   }
} 	
	        

ayed::Contacto ayed::Lista_Enlazada::get_posicion(unsigned posicion) {

   Nodo_Contacto* arreglo_nodo = primer_nodo;
  
   for (unsigned i = 0; i < posicion; ++i) {
      arreglo_nodo = arreglo_nodo->siguiente_nodo;
   }
   return arreglo_nodo->dato;
}	


unsigned ayed::Lista_Enlazada::get_tamanio() {

   return cantidad_nodos;
}


bool ayed::Lista_Enlazada::is_vacia() {

	return cantidad_nodos == 0;

}
