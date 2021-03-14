#include "../pacientes.h"
#include <cassert>
#include <memory>
#include <iostream>


int main() {

	ayed::Paciente primero{"1", "1"};
	ayed::Paciente segundo{"2", "2"};
	ayed::Paciente tercero{"3", "3"};



//----- Colas Enlazadas -------------------------

	
	// --- con valor inicial ---
       {
	std::unique_ptr<ayed::Cola> cola(new ayed::Cola_Enlazada(primero));
	cola->queue(segundo);
	cola->queue(tercero);
	assert (!cola->is_vacia());
	assert (cola->get_tamanio() == 3);
	assert (cola->frente() == primero);
	assert (cola->unqueue() == primero);
	assert (cola->unqueue() == segundo);
	assert (cola->unqueue() == tercero);
	assert (cola->is_vacia());
	assert (cola->unqueue() == ayed::PACIENTE_NULO);
	cola->queue(primero);
	cola->queue(segundo);
	cola->queue(tercero);

       }     

	std::cout << "\nCola enlazada con valor inicial OK\n";

	
	// --- sin valor inicial ---
       {
	std::unique_ptr<ayed::Cola> cola(new ayed::Cola_Enlazada()); 
	cola->queue(primero);
	cola->queue(segundo);
	cola->queue(tercero);
	assert (!cola->is_vacia());
	assert (cola->get_tamanio() == 3);
	assert (cola->frente() == primero);
	assert (cola->unqueue() == primero);
	assert (cola->unqueue() == segundo);
	assert (cola->unqueue() == tercero);
	assert (cola->is_vacia());
	assert (cola->unqueue() == ayed::PACIENTE_NULO);
	cola->queue(primero);
	cola->queue(segundo);
	cola->queue(tercero);
       }     

	std::cout << "\nCola enlazada sin valor inicial OK\n";


//----- Colas contiguas -------------------------



	// --- con valor inicial ---
       {		
	std::unique_ptr<ayed::Cola> cola(new ayed::Cola_Contigua(primero,3)); 
	cola->queue(segundo);
	cola->queue(tercero);
	assert (!cola->is_vacia());
	assert (cola->get_tamanio() == 3);
	assert (cola->frente() == primero);
	assert (cola->unqueue() == primero);
	assert (cola->unqueue() == segundo);
	assert (cola->unqueue() == tercero);
	assert (cola->is_vacia());
	assert (cola->unqueue() == ayed::PACIENTE_NULO);
	cola->queue(primero);
	cola->queue(segundo);
	cola->queue(tercero);
       }

	std::cout << "\nCola contigua con valor inicial OK\n";



	// --- Sin valor inicial ---
       {		
	std::unique_ptr<ayed::Cola> cola(new ayed::Cola_Contigua(3)); 
	cola->queue(primero);
	cola->queue(segundo);
	cola->queue(tercero);
	assert (!cola->is_vacia());
	assert (cola->get_tamanio() == 3);
	assert (cola->frente() == primero);
	assert (cola->unqueue() == primero);
	assert (cola->unqueue() == segundo);
	assert (cola->unqueue() == tercero);
	assert (cola->is_vacia());
	assert (cola->unqueue() == ayed::PACIENTE_NULO);
	cola->queue(primero);
	cola->queue(segundo);
	cola->queue(tercero);
       }

	std::cout << "\nCola contigua sin valor inicial OK\n";


     
}
