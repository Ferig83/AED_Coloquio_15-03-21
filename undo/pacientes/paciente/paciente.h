#ifndef __AYED_PACIENTE__
#define __AYED_PACIENTE__

#include <string>


namespace ayed {

 class Paciente {


	  public:
	
	  std::string nombre = "";
	  std::string apellido = "";
	  bool operator == (const Paciente& paciente) {
           return (nombre == paciente.nombre) && (apellido == paciente.apellido);	
          }

  };

 const Paciente PACIENTE_NULO;

 class Nodo_Paciente {


	private:

		Nodo_Paciente() { }
		Nodo_Paciente* siguiente_nodo;
		ayed::Paciente dato;
		friend class Cola_Enlazada;
		


 };


 


}



#endif