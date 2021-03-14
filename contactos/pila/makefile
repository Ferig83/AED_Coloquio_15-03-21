pruebas: pruebas.o pila_enlazada.o pila_contigua.o 
	g++ pruebas.o pila_enlazada.o pila_contigua.o -o pruebas -std=c++17

pruebas.o: pruebas.cpp
	g++ -c pruebas.cpp

pila_enlazada.o: pila_enlazada.cpp
	g++ -c pila_enlazada.cpp

pila_contigua.o: pila_contigua.cpp
	g++ -c pila_contigua.cpp


clean:
	rm *.o pruebas 