pruebas: pruebas.o cola_enlazada.o cola_contigua.o 
	g++ pruebas.o cola_enlazada.o cola_contigua.o -o pruebas -std=c++17

pruebas.o: pruebas.cpp
	g++ -c pruebas.cpp

cola_enlazada.o: cola_enlazada.cpp
	g++ -c cola_enlazada.cpp

cola_contigua.o: cola_contigua.cpp
	g++ -c cola_contigua.cpp


clean:
	rm *.o pruebas