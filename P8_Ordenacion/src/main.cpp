#include <iostream>
#include <vector>
#include <ctime>

#include "funciones.hpp"

#define INFINITO 999999
#define MAXIMO 1000
#define MINIMO 1

using Clave = int;

int main() {

	std::vector<Clave>* secuencia = new std::vector<Clave>;
	std::vector<Clave>* secuencia1 = new std::vector<Clave>;
	std::vector<Clave>* secuencia2 = new std::vector<Clave>;
	std::vector<Clave>* secuencia3 = new std::vector<Clave>;

	int tipo_algoritmo = 0;
	int size_secuencia = 0;
	int opcion_traza = 0;
	bool mostrar_traza = false;
	int generar_valores = 0;

	std::cout << "\nIndique el algoritmo a ejecutar:\n"
						<< "(1) Inserción\n(2) QuickSort\n" 
						<< "(3) ShellSort\n"
						<< "(4) Seleccion\n(5) MergeSort\n(6) HeapSort\n"
						<< "(7) Métodos 4, 5 y 6\n";
	tipo_algoritmo = RecogerCantidadPositiva(5);

	std::cout << "\nIndique el tamaño de la secuencia a ordenar: ";
	size_secuencia = RecogerCantidadPositiva();

	std::cout << "\n¿Quiere mostrar la traza de ejecucion?\n"
						<< "(1) Sí\n(2) No";
	opcion_traza = RecogerCantidadPositiva(2);
	if (opcion_traza == 1) {
		mostrar_traza = true;
	};

	std::cout << "\nDesea\n(1) Introducir los valores manualmente\n"
						<< "(2) Generar los valores de manera aleatoria\n";
	generar_valores = RecogerCantidadPositiva(2);

	
  secuencia->resize(size_secuencia);
  if (generar_valores == 1) {
    for (int i = 0; i < secuencia->size(); ++i) {
      std::cout << "\nElemento: ";
      std::cin >> secuencia->at(i);
    }
		if (mostrar_traza) {
			std::cout << std::endl;
		}
  } else {
    srand(time(NULL));
    for (int i = 0; i < secuencia->size(); ++i) {
      secuencia->at(i) = rand() % (MAXIMO - MINIMO - 1) + MINIMO;
    }
		Print(secuencia, size_secuencia);
  }

	switch (tipo_algoritmo) {
		case 1:
			Insercion(secuencia, size_secuencia, mostrar_traza);
			break;
		case 2:
			QuickSort(secuencia, size_secuencia, mostrar_traza);
			break;
		case 3:
			ShellSort(secuencia, size_secuencia, mostrar_traza);
			break;
		case 4:
			Seleccion(secuencia, size_secuencia, mostrar_traza);
			break;
		case 5:
			MergeSort(secuencia, size_secuencia, mostrar_traza);
			break;
		case 6:
			HeapSort(secuencia, size_secuencia, mostrar_traza);
			break;
		case 7:
			secuencia1 = secuencia;
			secuencia2 = secuencia;
			secuencia3 = secuencia;
			std::cout << "METODO SELECCION\n";
			Seleccion(secuencia1, size_secuencia, mostrar_traza);
			if (!mostrar_traza) {
				Print(secuencia1, size_secuencia);
			}
			std::cout << "METODO MERGESORT\n";
			MergeSort(secuencia2, size_secuencia, mostrar_traza);
			if (!mostrar_traza) {
				Print(secuencia2, size_secuencia);
			}
			std::cout << "METODO HEAPSORT\n";
			HeapSort(secuencia3, size_secuencia, mostrar_traza);
			if (!mostrar_traza) {
				Print(secuencia3, size_secuencia);
			}
			break;
	}

	if ((!mostrar_traza) && (tipo_algoritmo != 7)) {
		Print(secuencia, size_secuencia);
	}

	//system("clear");
}