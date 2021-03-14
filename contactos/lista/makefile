pruebas: pruebas.o lista_enlazada.o lista_contigua.o
	g++ pruebas.o lista_enlazada.o lista_contigua.o -o pruebas -std=c++17

pruebas.o: pruebas.cpp
	g++ -c pruebas.cpp

lista_enlazada.o: lista_enlazada.cpp
	g++ -c lista_enlazada.cpp


lista_contigua.o: lista_contigua.cpp
	g++ -c lista_contigua.cpp


clean:
	rm *.o pruebas