#include "./lista_contigua.h"


//-----------------------------------------------------------------------------

ayed::Lista_Contigua::Lista_Contigua(std::size_t tamanio) {

   try  {
      arreglo = new ayed::Contacto[tamanio];
   }

   catch (std::bad_alloc& ba) {
      std::cerr << "Error en reserva de memoria: " << ba.what() << "\n";
   }

   this->tamanio = tamanio; 
}

//-----------------------------------------------------------------------------

ayed::Lista_Contigua::~Lista_Contigua() {
	
	delete[] arreglo;
	std::cout << "\nLista contigua borrada desde el destructor";
}


//-----------------------------------------------------------------------------


void ayed::Lista_Contigua::set_posicion(const ayed::Contacto &dato_a_agregar, unsigned posicion) {

   arreglo[posicion] = dato_a_agregar;
}

//-----------------------------------------------------------------------------


void ayed::Lista_Contigua::agregar_al_final(const ayed::Contacto &dato_a_agregar) {

	if (cantidad_elementos >= tamanio) {
	  std::cerr << "No se pueden agregar más elementos (lista llena)";	
	} else {
	  arreglo[cantidad_elementos++] = dato_a_agregar;
	}
}

//-----------------------------------------------------------------------------


void ayed::Lista_Contigua::agregar_en(const ayed::Contacto &dato_a_agregar, unsigned posicion) { 

    if (cantidad_elementos >= tamanio) {
      std::cerr << "No hay mas elementos disponibles (cola a tope)"; 
    }
    else {
	
	if (cantidad_elementos != 0) { 

 	  for (long i = cantidad_elementos-1; i >= posicion; i--) {
		arreglo[i+1] = arreglo[i];
	  }
  	}
   	arreglo[posicion] = dato_a_agregar;
	cantidad_elementos++;
   }
}



//-----------------------------------------------------------------------------

void ayed::Lista_Contigua::borrar_posicion (unsigned posicion) {

    if (cantidad_elementos <= 0 || posicion > cantidad_elementos-1) {
      std::cerr << "La lista ya está vacía o no existe el elemento\n"; 
    }
    else {
	
 	  if (posicion != cantidad_elementos - 1) {
	   long i = posicion;
	   do {
		arreglo[i] = arreglo[i+1];
		i++;
	   } while (i < cantidad_elementos -1);
  	  }


 	  cantidad_elementos--;
    } 

} 	


//-----------------------------------------------------------------------------


ayed::Contacto ayed::Lista_Contigua::get_posicion(unsigned posicion) {

   return arreglo[posicion];
}


//-----------------------------------------------------------------------------

unsigned ayed::Lista_Contigua::get_tamanio () {

    return cantidad_elementos;
} 

//-----------------------------------------------------------------------------


bool ayed::Lista_Contigua::is_vacia() {
	return (cantidad_elementos == 0);

}