#include "../contactos.h"
#include <cassert>


int main() {

	ayed::Contacto primero{"1","1","1","1"};
        ayed::Contacto segundo{"2","2","2","2"};
	ayed::Contacto tercero{"3","3","3","3"};

	//--- Lista Enlazada ---
	{
	ayed::Lista* lista = new ayed::Lista_Enlazada();
	lista->agregar_al_final(primero);
        assert (lista->get_posicion(0) == primero);
	lista->agregar_al_final(segundo);
	assert(lista->get_tamanio() == 2);
	lista->set_posicion(tercero,0);
	assert (lista->get_posicion(1) == segundo);
       	assert (lista->get_posicion(0) == tercero);
	
	lista->agregar_en(segundo, 1);
       	assert (lista->get_posicion(1) == segundo);
	lista->borrar_posicion(0);
       	assert (lista->get_posicion(0) == segundo);
	delete lista;
	}

	//--- Lista Enlazada ---
	{
	ayed::Lista* lista = new ayed::Lista_Contigua(3);
	lista->agregar_al_final(primero);
        assert (lista->get_posicion(0) == primero);
	lista->agregar_al_final(segundo);
	assert(lista->get_tamanio() == 2);
	lista->set_posicion(tercero,0);
	assert (lista->get_posicion(1) == segundo);
       	assert (lista->get_posicion(0) == tercero);
	
	lista->agregar_en(segundo, 1);
       	assert (lista->get_posicion(1) == segundo);
	lista->borrar_posicion(0);
       	assert (lista->get_posicion(0) == segundo);
	delete lista;
	}



     
}




