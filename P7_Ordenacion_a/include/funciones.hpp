#include <iostream>
#include <vector>

#define INFINITO 999999
#define MAXIMO 1000
#define MINIMO 1

int RecogerCantidadPositiva(int cantidad_max = INFINITO) {
	int cantidad = 0;
	do {
		std::cout << "\nInput: ";
		std::cin >> cantidad;
	} while ((cantidad <= 0) && (cantidad > cantidad_max));
	return cantidad;
}

template <class Clave>
void Print(std::vector<Clave>* secuencia) {
  std::cout << "\nSecuencia: ";
  for (int i = 0; i < secuencia->size(); ++i) {
    std::cout << secuencia->at(i) << " ";
  }
  std::cout << "\n\n";
}

//x -> at(i)
template <class Clave>
void Insercion (std::vector<Clave>* secuencia, int size_secuencia, bool traza) {
  Clave aux;
  for (int i = 1; i < secuencia->size(); ++i) {
    int j = i - 1;
    aux = secuencia->at(i);
    while ((j >= 0) && (aux < secuencia->at(j)) && (j < secuencia->size())) {
      if ( traza) {
        std::cout << "Comparacion " << aux << " < " << secuencia->at(j) << ": true";
      }
      secuencia->at(j+1) = secuencia->at(j);
      //secuencia->at(j) = aux;
      if(traza) {
        Print(secuencia);
      }
      --j;
    }

    secuencia->at(j+1) = aux;
    //secuencia->insert(j+1,secuencia->at(i));
    //secuencia->erase(i+1);

    if (traza) {
      if (j < secuencia->size()) {
        std::cout << "Comparacion " << aux << " < " << secuencia->at(j) << ": false";
      } else {
        std::cout << "Comparacion " << aux << " < " << secuencia->at(j+1) << ": false";
      }
      Print(secuencia);
    }
  }
}

template <class Clave>
void QuickSort (std::vector<Clave>* secuencia, int size_secuencia, bool traza) {

}

template <class Clave>
void ShellSort (std::vector<Clave>* secuencia, int size_secuencia, bool traza) {

}