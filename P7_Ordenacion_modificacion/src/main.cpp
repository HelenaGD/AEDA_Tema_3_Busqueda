#include <iostream>
#include <vector>
#include <ctime>
#include <string>

#include "funciones.hpp"

#define INFINITO 999999
#define MAXIMO 1000
#define MINIMO 1

struct modificacion {
	std::string tipo_de_documento;
	std::string numero_de_documento;
	char letra;
	std::string string_numeros;
	//long long string_numeros;

/*
	void conversion_para_traza() {
		int caracter_como_numero = 0;
		for (int i = 0; i < tipo_de_documento.length(); ++i) {
			caracter_como_numero = tipo_de_documento[i];
			if (i == 0) {
				string_numeros = std::to_string(caracter_como_numero);
			} else {
				string_numeros += std::to_string(caracter_como_numero);
			}
		}
		// Ahora añado el numero
		string_numeros += std::to_string(numero_de_documento);

		// Por ultimo la letra
		int letra_int = letra;
		string_numeros += std::to_string(letra_int);
		/*
		for (int i = 0; i < string_ASCII.length(); ++i) {

		}*/
		//string_numeros = std::stoll(string_ASCII);*/

		void conversion_para_traza() {
			string_numeros = tipo_de_documento + numero_de_documento + letra;
			//std::cout << "Secuencia: " << string_numeros << "\n";
		} 
	
};

using Clave = modificacion;

int main() {

	int tipo_algoritmo = 0;
	int size_secuencia = 0;
	int opcion_traza = 0;
	bool mostrar_traza = false;
	int generar_valores = 0;
	int eleccion_documento = 0;

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
			std::cout << "\nTipo de documento: ";
			std::cout << "\n(1) DNI\n(2)NIE\n";
			eleccion_documento = RecogerCantidadPositiva(2);
			switch (eleccion_documento) {
				case 1:
					secuencia->at(i).tipo_de_documento = {"DNI"};
					break;
				case 2:
					secuencia->at(i).tipo_de_documento = {"NIE"};
					break;
			}

      std::cout << "\nNumero de documento: ";
      std::cin >> secuencia->at(i).numero_de_documento;

			std::cout << "\nLetra del documento: ";
			std::cin >> secuencia->at(i).letra;
			
    }
		if (mostrar_traza) {
			std::cout << std::endl;
		}
  } else {
    srand(time(NULL));
    for (int i = 0; i < secuencia->size(); ++i) {
      secuencia->at(i).numero_de_documento = rand() % (MAXIMO - MINIMO - 1) + MINIMO;
    }
		Print(secuencia, size_secuencia);
  }

	for (int i = 0; i < size_secuencia; ++i) {
		secuencia->at(i).conversion_para_traza();
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

	if(!mostrar_traza) {
		Print(secuencia, size_secuencia);
	}

	//system("clear");
}