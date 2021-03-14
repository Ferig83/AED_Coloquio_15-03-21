#include "../contactos.h"
#include <cassert>
#include <memory>
#include <iostream>


int main() {

	
	ayed::Undo primero{"1","1","1","1",0};
        ayed::Undo segundo{"2","2","2","2",0};
	ayed::Undo tercero{"3","3","3","3",0};


//----- Pilas Enlazadas -------------------------


       //--- Con valor inicial --- 

       {
	std::unique_ptr<ayed::Pila> pila(new ayed::Pila_Enlazada(primero)); 
        pila->push(segundo);
        pila->push(tercero);
        assert(!pila->is_vacia());
	assert(pila->get_tamanio() == 3);
	assert(pila->peek() == tercero);
        assert(pila->pop() == tercero);
        assert(pila->peek() == segundo);
        assert(pila->pop() == segundo);
        assert(pila->pop() == primero);
        assert(pila->is_vacia());
	assert(pila->pop() == ayed::UNDO_NULO);

	
	// Corroboro que se activen los destructores

        pila->push(primero);
        pila->push(segundo);
        pila->push(tercero);
       }

	std::cout << "\nPila enlazada con valor inicial OK\n";


       //--- Sin valor inicial --- 

       {
	std::unique_ptr<ayed::Pila> pila(new ayed::Pila_Enlazada()); 
        pila->push(primero);
        pila->push(segundo);
        pila->push(tercero);
	assert(!pila->is_vacia());
	assert(pila->get_tamanio() == 3);
	assert(pila->peek() == tercero);
        assert(pila->pop() == tercero);
        assert(pila->peek() == segundo);
        assert(pila->pop() == segundo);
        assert(pila->pop() == primero);
        assert(pila->is_vacia());
	assert(pila->pop() == ayed::UNDO_NULO);


	// Corroboro que se activen los destructores

        pila->push(primero);
        pila->push(segundo);
        pila->push(tercero);
       }

	std::cout << "\nPila enlazada sin valor inicial OK\n";



//----- Pilas Contiguas -------------------------


       //--- Con valor inicial --- 

       {
	std::unique_ptr<ayed::Pila> pila(new ayed::Pila_Contigua(primero,3)); 
        pila->push(segundo);
        pila->push(tercero);
	assert(!pila->is_vacia());
	assert(pila->get_tamanio() == 3);
	assert(pila->peek() == tercero);
        assert(pila->pop() == tercero);
        assert(pila->peek() == segundo);
        assert(pila->pop() == segundo);
        assert(pila->pop() == primero);
        assert(pila->is_vacia());
	assert(pila->pop() == ayed::UNDO_NULO);

        pila->push(primero);
        pila->push(segundo);
        pila->push(tercero);
       }

	std::cout << "\nPila contigua con valor inicial OK\n";


       //--- Sin valor inicial --- 

       {
	std::unique_ptr<ayed::Pila> pila(new ayed::Pila_Contigua(3)); 
        pila->push(primero);
        pila->push(segundo);
        pila->push(tercero);
	assert(!pila->is_vacia());
	assert(pila->get_tamanio() == 3);
	assert(pila->peek() == tercero);
        assert(pila->pop() == tercero);
        assert(pila->peek() == segundo);
        assert(pila->pop() == segundo);
        assert(pila->pop() == primero);
        assert(pila->is_vacia());
	assert(pila->pop() == ayed::UNDO_NULO);

        pila->push(primero);
        pila->push(segundo);
        pila->push(tercero);
       }

	std::cout << "\nPila contigua sin valor inicial OK\n";

	
}     
