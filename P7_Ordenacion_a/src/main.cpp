#include <iostream>
#include <vector>
#include <ctime>

#include "funciones.hpp"

#define INFINITO 999999
#define MAXIMO 1000
#define MINIMO 1

using Clave = int;
/*
int RecogerCantidadPositiva(int cantidad_max = INFINITO);

template <class Clave>
void Insercion (std::vector<Clave>* secuencia, int size_secuencia, bool traza);

template <class Clave>
void QuickSort (std::vector<Clave>* secuencia, int size_secuencia, bool traza);

template <class Clave>
void ShellSort (std::vector<Clave>* secuencia, int size_secuencia, bool traza);

template <class Clave>
void print(std::vector<Clave>* secuencia);*/

int main() {

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

	std::cout << "\nDesea\n(1) Introducir los valores manualmente\n"
						<< "(2) Generar los valores de manera aleatoria\n";
	generar_valores = RecogerCantidadPositiva(2);

	std::vector<Clave>* secuencia = new std::vector<Clave>;
  secuencia->resize(size_secuencia);
  if (generar_valores == 1) {
    for (int i = 0; i < secuencia->size(); ++i) {
      std::cout << "\nElemento: ";
      std::cin >> secuencia->at(i);
    }
		std::cout << std::endl;
  } else {
    srand(time(NULL));
    for (int i = 0; i < secuencia->size(); ++i) {
      secuencia->at(i) = rand() % (MAXIMO - MINIMO - 1) + MINIMO;
    }
		Print(secuencia);
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
	}

	//system("clear");
}