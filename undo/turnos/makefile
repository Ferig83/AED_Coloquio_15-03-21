turnos: turnos.o cola_enlazada.o cola_contigua.o
	g++ turnos.o cola_enlazada.o cola_contigua.o -o turnos -std=c++17

turnos.o: turnos.cpp
	g++ -c turnos.cpp

cola_enlazada.o: ../pacientes/cola/cola_enlazada.cpp
	g++ -c ../pacientes/cola/cola_enlazada.cpp

cola_contigua.o: ../pacientes/cola/cola_contigua.cpp
	g++ -c ../pacientes/cola/cola_contigua.cpp

clean:
	rm *.o turnos