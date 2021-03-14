#include "pila_enlazada.h"


ayed::Pila_Enlazada::Pila_Enlazada(const ayed::Undo &dato_a_agregar) {

	push(dato_a_agregar);

}

//-----------------------------------------------------------------------------


ayed::Pila_Enlazada::Pila_Enlazada() {
   primer_nodo = nullptr;
}


//-----------------------------------------------------------------------------


ayed::Pila_Enlazada::~Pila_Enlazada() {

   while (primer_nodo != nullptr) {
      pop();
      std::cout << "\nNodo de pila borrado desde el destructor";
   }
}


//-----------------------------------------------------------------------------


void ayed::Pila_Enlazada::push(const ayed::Undo &dato_a_agregar) {


   Nodo_Undo* nodo_nuevo;

   try  {
      nodo_nuevo = new Nodo_Undo; 
   }

   catch (std::bad_alloc& ba) {
      std::cerr << "Error en reserva de memoria: " << ba.what() << "\n";
   }

   if (primer_nodo == nullptr) {

     primer_nodo = nodo_nuevo;
     primer_nodo->dato = dato_a_agregar;
     primer_nodo->siguiente_nodo = nullptr;

   } else {
   
		   
     nodo_nuevo->siguiente_nodo = primer_nodo;
     nodo_nuevo->dato = dato_a_agregar;
     primer_nodo = nodo_nuevo;
   
   }

   cantidad_nodos++;
}

//-----------------------------------------------------------------------------

ayed::Undo ayed::Pila_Enlazada::pop () {

    Nodo_Undo* nodo_a_borrar = primer_nodo;
    ayed::Undo dato_pop;


    if (primer_nodo == nullptr) { 
	std::cerr << "No hay nodos";
	return ayed::UNDO_NULO;

    } 

    dato_pop = primer_nodo->dato;
    primer_nodo = primer_nodo->siguiente_nodo;
    delete nodo_a_borrar;
    cantidad_nodos--;
    return dato_pop;
} 	



//-----------------------------------------------------------------------------


ayed::Undo ayed::Pila_Enlazada::peek () {

    return primer_nodo->dato;
  
} 	

//-----------------------------------------------------------------------------


bool ayed::Pila_Enlazada::is_vacia () {

    return cantidad_nodos == 0;
  
} 	

//-----------------------------------------------------------------------------


unsigned ayed::Pila_Enlazada::get_tamanio () {

    return cantidad_nodos;
} 	
