#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "../contactos/contactos.h"


//-----------------------------------------------------------------------------

ayed::Contacto get_entrada () {

   ayed::Contacto contacto;

   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Para ignorar los saltos de linea que se hayan dado antes
   std::cout << "Ingrese el nuevo nombre: ";
   std::getline(std::cin, contacto.nombre);
   std::cout << "Ingrese el apellido: ";
   std::getline(std::cin, contacto.apellido);
   std::cout << "Ingrese la direccion: ";
   std::getline(std::cin, contacto.direccion);
   std::cout << "Ingrese el numero de telefono: ";
   std::getline(std::cin, contacto.telefono);
   return contacto;
}


//-----------------------------------------------------------------------------

void cargar_agenda (std::fstream &agenda, ayed::Lista* entrada) {

   while (!agenda.eof()) {
	ayed::Contacto contacto;
	std::string espacio;

        std::getline(agenda, contacto.nombre);
        std::getline(agenda, contacto.apellido);
        std::getline(agenda, contacto.direccion);
        std::getline(agenda, contacto.telefono);
        std::getline(agenda, espacio);

	entrada->agregar_al_final(contacto);
   }

}


//-----------------------------------------------------------------------------

int main () {

	  std::fstream agenda("agenda_pila.dat");
	  ayed::Lista* entradas = new ayed::Lista_Enlazada();
	  unsigned respuesta = 0;
	  ayed::Pila* undos = new ayed::Pila_Enlazada();
	  ayed::Undo undo_a_realizar;

	  cargar_agenda(agenda, entradas);

	  while (respuesta != 6) {


	     system("CLS");

   	     std::cout << "Agenda\n-------\n\n";

	     for (unsigned i = 0; i < entradas->get_tamanio(); ++i) {
		std::cout << "Ficha numero: "<< i+1 << std::endl;
		std::cout << entradas->get_posicion(i).nombre << std::endl;
		std::cout << entradas->get_posicion(i).apellido << std::endl;
		std::cout << entradas->get_posicion(i).direccion << std::endl;
		std::cout << entradas->get_posicion(i).telefono << "\n\n";

	     }

	     std::cout << "\n  Ingrese (1...4) para editar los campos;  (5) Para deshacer ; (6) Para salir\n";
	     std::cin >> respuesta;
	
		

	     switch (respuesta) {
		case 5: 
                  if (undos->is_vacia()) { std::cout << "\nNo hay elementos\n"; break; }

		  undo_a_realizar = undos->pop();
		  entradas->set_posicion(undo_a_realizar.contacto, undo_a_realizar.posicion_previa);
		  break;
	        case 6: break;
	        default:  
		    if (respuesta >= 1 && respuesta <= 4) { 
			undos->push({entradas->get_posicion(respuesta-1), respuesta-1});
			entradas->set_posicion(get_entrada(), respuesta-1);

		    } else {  std::cout << "\nERROR: Comando erroneo\n";  } break;
 	

	      }	

  	}

	// Grabo las modificaciones en el archivo
        
	agenda.clear();
        agenda.seekg (0, agenda.beg);
	
        for (unsigned i = 0; i < entradas->get_tamanio();) {
		agenda << entradas->get_posicion(i).nombre << std::endl;
		agenda << entradas->get_posicion(i).apellido << std::endl;
		agenda << entradas->get_posicion(i).direccion << std::endl;
		agenda << entradas->get_posicion(i).telefono;
		agenda << (++i == entradas->get_tamanio() ? "\n--------------------" : "\n--------------------\n");
	}

      
	agenda.close();
	delete undos;
	delete entradas;     

}





