#include "./cola_contigua.h"
#include <iostream>  // cerr, cout

//------------------------------------------------------------------------------

ayed::Cola_Contigua::Cola_Contigua(const ayed::Paciente &dato_a_agregar, const std::size_t tamanio) {

   try  {
      arreglo = new ayed::Paciente[tamanio];
   }

   catch (std::bad_alloc& ba) {
      std::cerr << "Error en reserva de memoria: " << ba.what() << "\n";
   }

   this->tamanio = tamanio;
   queue(dato_a_agregar);
//   arreglo[0] = dato_a_agregar;
//   this->tamanio = tamanio;
//   cantidad_elementos++;

}

//------------------------------------------------------------------------------

ayed::Cola_Contigua::Cola_Contigua(std::size_t tamanio) {
   try  {
      arreglo = new ayed::Paciente[tamanio];
   }

   catch (std::bad_alloc& ba) {
      std::cerr << "Error en reserva de memoria: " << ba.what() << "\n";
   }

   this->tamanio = tamanio;
}

//------------------------------------------------------------------------------

ayed::Cola_Contigua::~Cola_Contigua() { 
  delete[] arreglo;
  std::cout << "\nCola Contigua borrada desde el destructor";
}

//------------------------------------------------------------------------------

void ayed::Cola_Contigua::queue(const ayed::Paciente &dato_a_agregar) {
    if (cantidad_elementos >= tamanio) {
    std::cerr << "No hay mas elementos disponibles (cola a tope)"; 
   }
   else {
	
	if (cantidad_elementos != 0) { 

 	  for (long i = cantidad_elementos-1; i >= 0; i--) {
		arreglo[i+1] = arreglo[i];
	  }
  	}
   	arreglo[0] = dato_a_agregar;
	cantidad_elementos++;
   }

}

//------------------------------------------------------------------------------

ayed::Paciente ayed::Cola_Contigua::unqueue() {
     if (cantidad_elementos <= 0) std::cerr << "No hay mas elementos";
     return cantidad_elementos > 0 ? arreglo[--cantidad_elementos] : ayed::PACIENTE_NULO;
} 	

//------------------------------------------------------------------------------

ayed::Paciente ayed::Cola_Contigua::frente() {
     return cantidad_elementos > 0 ? arreglo[cantidad_elementos-1] : ayed::PACIENTE_NULO;
}

//------------------------------------------------------------------------------

bool ayed::Cola_Contigua::is_vacia() {
  return cantidad_elementos == 0;
}

//------------------------------------------------------------------------------

unsigned ayed::Cola_Contigua::get_tamanio() {
  return cantidad_elementos;
}         	

//------------------------------------------------------------------------------