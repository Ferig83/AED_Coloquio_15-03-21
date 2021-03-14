
#include "./pila_contigua.h"
#include <cstddef> // std::size_t

//-----------------------------------------------------------------------------

ayed::Pila_Contigua::Pila_Contigua(const ayed::Undo &dato_a_agregar, std::size_t cantidad_total) {

   try  {
      arreglo = new ayed::Undo[cantidad_total];
   }

   catch (std::bad_alloc& ba) {
      std::cerr << "Error en reserva de memoria: " << ba.what() << "\n";
   }

   arreglo[0] = dato_a_agregar;
   cantidad_elementos_total = cantidad_total;
   cantidad_elementos++;
}

//-----------------------------------------------------------------------------

ayed::Pila_Contigua::Pila_Contigua(std::size_t cantidad_total) {
   try  {
      arreglo = new ayed::Undo[cantidad_total];
   }

   catch (std::bad_alloc& ba) {
      std::cerr << "Error en reserva de memoria: " << ba.what() << "\n";
   }

   cantidad_elementos_total = cantidad_total;
}


//-----------------------------------------------------------------------------

ayed::Pila_Contigua::~Pila_Contigua() {
  delete[] arreglo;
  std::cout << "\nPila contigua borrada desde el destructor";
}


//-----------------------------------------------------------------------------

void ayed::Pila_Contigua::push(const ayed::Undo &dato_a_agregar) {

   if (cantidad_elementos >= cantidad_elementos_total) {
    std::cerr << "No hay mas elementos disponibles (pila a tope)"; 
   }
   else {
    arreglo[cantidad_elementos++] = dato_a_agregar;
   }
}

//-----------------------------------------------------------------------------

ayed::Undo ayed::Pila_Contigua::pop () {

     if (cantidad_elementos <= 0) std::cerr << "No hay mas elementos";
     return cantidad_elementos > 0 ? arreglo[--cantidad_elementos] : ayed::UNDO_NULO;
} 	



//-----------------------------------------------------------------------------


ayed::Undo ayed::Pila_Contigua::peek() {

    return arreglo[cantidad_elementos-1];
  
} 	

//-----------------------------------------------------------------------------


bool ayed::Pila_Contigua::is_vacia () {

    return cantidad_elementos == 0;
  
} 	

//-----------------------------------------------------------------------------


unsigned ayed::Pila_Contigua::get_tamanio () {

    return cantidad_elementos;
} 	
