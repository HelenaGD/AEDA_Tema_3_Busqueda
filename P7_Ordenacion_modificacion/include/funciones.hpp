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
void Print(std::vector<Clave>* secuencia, int size_secuencia) {
  std::cout << "\nSecuencia: ";
  for (int i = 0; i < size_secuencia; ++i) {
    std::cout << secuencia->at(i).tipo_de_documento << secuencia->at(i).numero_de_documento
    << secuencia->at(i).letra << " ";
  }
  std::cout << "\n";
}

//x -> at(i)
template <class Clave>
void Insercion (std::vector<Clave>* secuencia, int size_secuencia, bool traza) {
  Clave aux;
  for (int i = 1; i < size_secuencia; ++i) {
    int j = i - 1;
    aux = secuencia->at(i);
    while ((j >= 0) && (aux.string_numeros < secuencia->at(j).string_numeros) && (j < size_secuencia)) {
      if ( traza) {
        if ((j < size_secuencia) && (j>0))
        std::cout << "\nComparacion: " << aux.string_numeros << " < " << secuencia->at(j).string_numeros << " : true";
      }
      secuencia->at(j+1) = secuencia->at(j);
      //secuencia->at(j) = aux;
      if(traza) {
        Print(secuencia, size_secuencia);
      }
      --j;
    }

    secuencia->at(j+1) = aux;
    //secuencia->insert(j+1,secuencia->at(i));
    //secuencia->erase(i+1);

    if (traza) {
      if (j < size_secuencia) {
        std::cout << "\nComparacion: " << aux.string_numeros << " < " << secuencia->at(j).string_numeros << " : false";
      } else {
        std::cout << "\nComparacion: " << aux.string_numeros << " < " << secuencia->at(j+1).string_numeros << " : false";
      }
      Print(secuencia, size_secuencia);
    }
  }
}

template <class Clave>
void QSort (std::vector<Clave>* secuencia, int inicio, int fin, bool traza, int size_secuencia) {
  int i = inicio;
  int f = fin;
  Clave aux = secuencia->at( (i + f) / 2 );
  if (traza) {
    std::cout << "PIVOTE: " << aux.string_numeros << "\n\n";
  }
  while (i <= f) {
    while (secuencia->at(i).string_numeros < aux.string_numeros) {
      if (traza) {
        std::cout << "\nComparacion: " << secuencia->at(i).string_numeros << " < " << aux.string_numeros << " : true";
        Print(secuencia, size_secuencia);
      }
      ++i;
    }
      if (traza) {
        std::cout << "\nComparacion: " << secuencia->at(i).string_numeros << " < " << aux.string_numeros << " : false";
        Print(secuencia, size_secuencia);
      }
    while (secuencia->at(f).string_numeros > aux.string_numeros) {
      if (traza) {
        std::cout << "\nComparacion: " << secuencia->at(f).string_numeros << " > " << aux.string_numeros << " : true";
        Print(secuencia, size_secuencia);
      }
      --f;
    }
      if (traza) {
        std::cout << "\nComparacion: " << secuencia->at(i).string_numeros << " < " << aux.string_numeros << " : false";
        Print(secuencia, size_secuencia);
      }
    if ( i <= f) {
      std::swap(secuencia->at(i), secuencia->at(f));
      if (traza) {
        std::cout << "\nComparacion: " << i << " <= " << f << " : true -> swap ( " << secuencia->at(i).string_numeros << " " << secuencia->at(f).string_numeros << " )";
        Print(secuencia, size_secuencia);
      }
      ++i;
      --f;
    }
  }
  if (inicio < f) {
    if (traza) {
      std::cout << "\nComparacion: inicio (" << inicio << ") < iterador f (" << f << ") : true";
      Print(secuencia, size_secuencia);
    }
    QSort(secuencia, inicio, f, traza, size_secuencia);
  }
  if (i < fin) {
    if (traza) {
      std::cout << "\nComparacion: iterador i(" << i << ") < fin (" << fin << ") : true";
      Print(secuencia, size_secuencia);
    }
    QSort(secuencia, i, fin, traza, size_secuencia);
  }
}

template <class Clave>
void QuickSort (std::vector<Clave>* secuencia, int size_secuencia, bool traza) {
  int inicio = 0;
  int fin = size_secuencia - 1;
  QSort(secuencia, inicio, fin, traza, size_secuencia);
}

template<class Clave>
void deltasort (int del, std::vector<Clave>* secuencia, int size_secuencia, bool traza) {
  for (int i = del; i < size_secuencia; ++i) {
    Clave aux = secuencia->at(i);
    int j = i;
    bool flag = false;
    bool flag2 = false;
    while ((j >= del) && (aux.string_numeros < secuencia->at( j - del).string_numeros)) {
      flag = false;
      flag2 = false;
      if (traza) {
        std::cout << "\nComparacion: " << aux.string_numeros << " < " << secuencia->at( j - del).string_numeros << " : true";
        flag = true;
      }
      secuencia->at(j) = secuencia->at( j - del);
      if (traza) {
        Print(secuencia, size_secuencia);
        flag2 = true;
      }
      j = j - del;
    }
      if (traza) {
        if (!flag) {
          if ((j >= del)) {
            std::cout << "\nComparacion: " << aux.string_numeros << " < " << secuencia->at( j -del ).string_numeros << " : false";
          } else {
            std::cout << "\nComparacion: iterador j (" << j << ") >= (" << del << ") : false";
          }
        }     
      }
    secuencia->at(j) = aux;
      if (traza) {
        if ((!flag) || flag2) {
          Print(secuencia, size_secuencia);
        }  
      }
  }
}

template <class Clave>
void ShellSort (std::vector<Clave>* secuencia, int size_secuencia, bool traza) {
  int del = size_secuencia;
  while (del > 1) {
    del = del /2;
    deltasort(del, secuencia, size_secuencia, traza);
  }
}