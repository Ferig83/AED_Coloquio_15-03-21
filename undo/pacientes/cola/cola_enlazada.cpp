#include "cola_enlazada.h"
#include <iostream> // cerr , cout


ayed::Cola_Enlazada::Cola_Enlazada(const ayed::Paciente &dato_a_agregar) {

   queue(dato_a_agregar);

}

//-----------------------------------------------------------------------------

ayed::Cola_Enlazada::Cola_Enlazada() {
   primer_nodo = nullptr;
}


//-----------------------------------------------------------------------------

ayed::Cola_Enlazada::~Cola_Enlazada() {

   Nodo_Paciente* arreglo_nodo = primer_nodo;

   while (arreglo_nodo != nullptr) {
      Nodo_Paciente* nodo_a_borrar;
      nodo_a_borrar = arreglo_nodo;
      arreglo_nodo = arreglo_nodo->siguiente_nodo;
      delete nodo_a_borrar;
      std::cout << "\nNodo de cola borrado desde el destructor";
   }
}


//-----------------------------------------------------------------------------

void ayed::Cola_Enlazada::queue(const ayed::Paciente &dato_a_agregar) {


   Nodo_Paciente* nodo_nuevo;

   try  {
      nodo_nuevo = new Nodo_Paciente; 
   }

   catch (std::bad_alloc& ba) {
      std::cerr << "Error en reserva de memoria: " << ba.what() << "\n";
   }

   nodo_nuevo->siguiente_nodo = nullptr;
   nodo_nuevo->dato = dato_a_agregar;
    
   if (primer_nodo == nullptr) {
      primer_nodo = nodo_nuevo;
   } else {
      Nodo_Paciente* arreglo_nodo = primer_nodo;
      while (arreglo_nodo->siguiente_nodo != nullptr) {
         arreglo_nodo = arreglo_nodo->siguiente_nodo;
      }

      arreglo_nodo->siguiente_nodo = nodo_nuevo;  
   }

   cantidad_nodos++;

}



//--- Definiciones ------------------------------------------------------------


ayed::Paciente ayed::Cola_Enlazada::unqueue() {


    if (primer_nodo == nullptr) { 
	std::cerr << "No hay nodos";
	return ayed::PACIENTE_NULO;
    }

   ayed::Paciente dato_unqueue;
   ayed::Nodo_Paciente *nodo_a_borrar = primer_nodo;

   dato_unqueue = primer_nodo->dato;
   primer_nodo = primer_nodo->siguiente_nodo;
   delete nodo_a_borrar;
   cantidad_nodos--;
   return dato_unqueue;

}


//-----------------------------------------------------------------------------

bool ayed::Cola_Enlazada::is_vacia () {

    return (cantidad_nodos == 0);
  
} 	

//-----------------------------------------------------------------------------


unsigned ayed::Cola_Enlazada::get_tamanio () {

    return cantidad_nodos;
} 	

//-----------------------------------------------------------------------------


ayed::Paciente ayed::Cola_Enlazada::frente() {

    return primer_nodo->dato;
} 	

