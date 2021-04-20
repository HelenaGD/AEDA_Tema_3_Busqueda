#include "funcionordenacion.hpp"
#include "foinsercion.hpp"

#include <iostream>

#define INFINITO 999999

using Clave = int;

int RecogerCantidadPositiva(int cantidad_max = INFINITO) {
	int cantidad = 0;
	do {
		std::cout << "\nInput: ";
		std::cin >> cantidad;
	} while ((cantidad <= 0) && (cantidad > cantidad_max));
	return cantidad;
}

int main() {
	FuncionOrdenacion<Clave> *fo;

	int tipo_algoritmo = 0;
	int size_secuencia = 0;
	int opcion_traza = 0;
	bool mostrar_traza = false;
	int generar_valores = 0;

	std::cout << "\nIndique el algoritmo a ejecutar:\n"
						<< "(1) Inserción\n(2) QuickSort\n" 
						<< "(3) ShellSort\n";
	tipo_algoritmo = RecogerCantidadPositiva(3);

	std::cout << "\nIndique el tamaño de la secuencia a ordenar: ";
	size_secuencia = RecogerCantidadPositiva();

	std::cout << "\n¿Quiere mostrar la traza de ejecucion?\n"
						<< "(1) Sí\n(2) No";
	opcion_traza = RecogerCantidadPositiva(2);
	if (opcion_traza == 1) {
		mostrar_traza = true;
	};

	std::cout << "Desea\n(1) Introducir los valores manualmente\n"
						<< "(2) Generar los valores de manera aleatoria\n";
	generar_valores = RecogerCantidadPositiva(2);

	switch (tipo_algoritmo) {
		case 1:
			fo = new foInsercion<Clave>(size_secuencia, generar_valores, mostrar_traza);
			break;
		case 2:
			//fo = new foQuickSort<Clave>(size_secuencia, mostrar_traza);
			break;
		case 3:
			//fo = new foShellSort<Clave>(size_secuencia, mostrar_traza);
			break;
	}

	fo->ordenacion();

	delete fo;
	//system("clear");
}