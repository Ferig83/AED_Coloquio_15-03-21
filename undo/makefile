undo: undo.o pila_enlazada.o pila_contigua.o lista_enlazada.o lista_contigua.o
	g++ undo.o pila_enlazada.o pila_contigua.o lista_enlazada.o lista_contigua.o -o undo -std=c++17

undo.o: undo.cpp
	g++ -c undo.cpp

pila_enlazada.o: ../contactos/pila/pila_enlazada.cpp
	g++ -c ../contactos/pila/pila_enlazada.cpp

pila_contigua.o: ../contactos/pila/pila_contigua.cpp
	g++ -c ../contactos/pila/pila_contigua.cpp


lista_enlazada.o: ../contactos/lista/lista_enlazada.cpp
	g++ -c ../contactos/lista/lista_enlazada.cpp

lista_contigua.o: ../contactos/lista/lista_contigua.cpp
	g++ -c ../contactos/lista/lista_contigua.cpp


clean:
	rm *.o undo