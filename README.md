## TP - Coloquio

---

### Análisis del problema

#### Enunciado
 Crear contenedores (enlazados y continuos), realizar las pruebas pertinentes y dar ejemplos de uso.
 
#### Restricciones

* No se han establecido restricciones

#### Léxico e Hipótesis de trabajo

Los contenedores son tipos de datos o estructuras que contienen en si mismos otro tipo de objetos (ya sean estructuras, tipos de datos atómicos, otros contenedores, etc). Por ejemplo, se puede diseñar un contenedor como una pila que funcione como tal y maneje en su estructura cualquier tipo de dato (inclusive otra pila). 

En C++ podemos encontrar muchos contenedores implementados bajo la forma de "templates" (y una biblioteca llamada Standard Template Library que los incluye), como por ejemplo std::array que permite manejar un array continuo utilizando como objetos del array el tipo de dato o estructura que queramos. Este tipo de contenedores son genéricos por poder ponerse dentro cualquier tipo de dato, pero los que presentaremos tendrán tipos de datos concretos.

En esta presentación diseñamos tres tipos de contenedores:

* Pila  (conteniendo el tipo de dato "Undo")
* Lista  (conteniendo el tipo de dato "Contacto")
* Cola  (conteniendo el tipo de dato "Paciente")


#### PILA

Dado un conjunto de datos:

A = {Dato_1, Dato_2, Dato_3, ... , Dato_n-1}

n(A) = n

   
Sea PILA una sucesión de n elementos del conjunto A, por ejemplo:

PILA = {Dato_3, Dato_2, Dato_2, Dato_4}
n(PILA) = 4

Se establecen las siguientes funciones:

* void -> __is_vacia__ -> booleano B : B es "verdadero" si el cardinal de PILA es 0, y "falso" si el cardinal de PILA es distinto de cero

* void -> __get_tamanio__ -> natural N : N es el cardinal del conjunto PILA

* void -> __peek__ -> __a__ perteneciente al conjunto A : __a__ sea el n-ésimo elemento     

* __a__ perceneciente al conjunto A -> __push__ -> PILA' : n(PILA') = n(PILA)+1  ^  PILA'_n = __a__

* void -> __pop__ -> (__a__ perteneciente al conjunto A : __a__ sea el n-ésimo elemento de PILA) X (PILA' : n(PILA') = n(PILA) - 1)
  
#### LISTA

Dado un conjunto de datos:

A = {Dato_1, Dato_2, Dato_3, ... , Dato_n-1}

n(A) = n

   
Sea LISTA una sucesión de n elementos del conjunto A, por ejemplo:

LISTA = {Dato_3, Dato_2, Dato_2, Dato_4}
n(LISTA) = 4

Se establecen las siguientes funciones:

* void -> __is_vacia__ -> booleano B : B es "verdadero" si el cardinal de LISTA es 0, y "falso" si el cardinal de LISTA es distinto de cero

* void -> __get_tamanio__ -> natural N : N es el cardinal del conjunto LISTA

* natural N -> __get_posicion__ -> __a__ perteneciente al conjunto A : __a__ = LISTA_N

* (__a__ perteneciente al conjunto A) X (natural N) -> __set_posicion__ -> LISTA' : LISTA'_N = __a__

* __a__ perteneciente al conjunto A -> agregar_al_final -> LISTA' : n(LISTA') = n(LISTA) + 1 ^ LISTA'_n = __a__
 
* (__a__ perteneciente al conjunto A) x (natural N) -> agregar_en -> LISTA' : n(LISTA') = n(LISTA) + 1 ^ LISTA_m = COLA_m+1 con m > N ^ LISTA_1 = __a__




#### COLA



Dado un conjunto de datos:

A = {Dato_1, Dato_2, Dato_3, ... , Dato_n-1}

n(A) = n

   
Sea COLA una sucesión de n elementos del conjunto A, por ejemplo:

COLA = {Dato_3, Dato_2, Dato_2, Dato_4}
n(COLA) = 4


Se establecen las siguientes funciones:

* void -> __is_vacia__ -> booleano B : B es "verdadero" si el cardinal de LISTA es 0, y "falso" si el cardinal de LISTA es distinto de cero

* void -> __get_tamanio__ -> natural N : N es el cardinal del conjunto LISTA

* __a__ perteneciente al conjunto A -> __queue__ -> COLA' : n(COLA') = n(COLA)+1  ^  COLA_n = COLA_n+1 ^ COLA_1 = __a__

* void -> __unqueue__ -> (__a__ perteneciente al conjunto A : __a__ sea el n-ésimo elemento de COLA) X (COLA' : n(COLA') = n(COLA) - 1)

* void -> __frente__ -> __a__ perteneciente al conjunto A : __a__ sea el n-ésimo elemento     


__ADVERTENCIA__: Para todos los contenedores, cuando no haya datos que recuperar, se devolverá un valor indefinido o nulo (estructura inicializada en "cero" y/o con cadenas nulas)



## Ejemplos de implementación:

### Sistema básico de turnos segun llegada - Uso de Cola

Se necesita una aplicación para ingresar pacientes que llegan a la recepción de un consultorio médico y mostrar por un display (ajeno al std::cout) su nombre y apellido segun vayan ingresando.

### Modelo IPO y resolución del problema:

Se requiere que los pacientes que han llegado primero a la recepción sean los primeros en atenderse en el consultorio, por lo tanto se ve conveniente el uso de nuestro tipo de dato "Cola" ya que el tipo de almacenaje y acceso cumple con el sistema FIFO (First In First Out : primero en ingresar es el  primero en salir). Como no existe una cantidad fija de pacientes (más allá de que podemos estimar un límite), podemos ver conveniente utilizar una pila con elementos enlazados, en la cual la reserva de memoria se hará en tiempo de ejecución.

El modelo IPO puede consistir en:

* Entrada: Ingreso de pacientes en la cola mediante teclado
* Procesamiento: Dar formato al nombre para su salida y adherir un mensaje de "Pase, por favor"
* Salida: Enviar el flujo de datos a través de un archivo que representaría el buffer del display, con posterior borrado del elemento

La aplicación es muy simple pero demuestra de una manera sencilla el sistema FIFO y cómo la Cola diseñada actúa como contenedor de la clase Paciente (la cual tiene nombre y apellido como cadenas).


### Sistema básico de UNDO (deshacer) - Uso de Lista_Enlazada y Pila

Se necesita una aplicación base que consiste en una agenda con cuatro celdas de almacenamiento y se desea poder visualizarlas y editarlas. A su vez, tiene como opcion deshacer los cambios que vayamos realizando.

### Modelo IPO y resolución del problema:

La agenda misma consiste en un archivo donde se tienen todos los datos pero para conveniencia se almacenarán todos en memoria apenas se inicia la aplicación. Este almacenamiento requerirá de poder editar cualquier nodo de la lista donde se guarde, por lo que se ve conveniente  utilizar nuestro contenedor "Lista", que contendrá la estructura "Contacto" (la cual contiene nombre, apellido, dirección y teléfono). Sin embargo, también debemos escribir un sistema para deshacer los cambios en el caso de que el usuario se haya equivocado, y este tipo de sistemas cumple muy bien con el método de almacenamiento LIFO (Last In First Out - Último en Entrar, Primero en Salir) haciendo ideal el uso de la Pila (los últimos cambios son los que se deben deshacer primero).

El modelo IPO puede consistir en:

Para edición de datos:

* Entrada: Ingreso de datos de personas y un número N 
* Procesamiento: Reemplazar (en memoria) la entrada en la posición N por el ingreso solicitado en la entrada
* Salida: Base de datos modificada

Para deshacer cambios:

* Entrada: Base de datos con una última modificación
* Procesamiento: Reemplazar la última modificación por una anterior
* Salida: Base de datos sin la última modificación

La aplicación es un ejemplo combinado de Lista y Pila, y representa una agenda muy simplificada para demostrar de manera sencilla el posible uso de ambos contenedores.
