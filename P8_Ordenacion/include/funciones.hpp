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
    std::cout << secuencia->at(i) << " ";
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
    while ((j >= 0) && (aux < secuencia->at(j)) && (j < size_secuencia)) {
      if ( traza) {
        std::cout << "\nComparacion: " << aux << " < " << secuencia->at(j) << " : true";
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
        std::cout << "\nComparacion: " << aux << " < " << secuencia->at(j) << " : false";
      } else {
        std::cout << "\nComparacion: " << aux << " < " << secuencia->at(j+1) << " : false";
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
    std::cout << "PIVOTE: " << aux << "\n\n";
  }
  while (i <= f) {
    while (secuencia->at(i) < aux) {
      if (traza) {
        std::cout << "\nComparacion: " << secuencia->at(i) << " < " << aux << " : true";
        Print(secuencia, size_secuencia);
      }
      ++i;
    }
      if (traza) {
        std::cout << "\nComparacion: " << secuencia->at(i) << " < " << aux << " : false";
        Print(secuencia, size_secuencia);
      }
    while (secuencia->at(f) > aux) {
      if (traza) {
        std::cout << "\nComparacion: " << secuencia->at(f) << " > " << aux << " : true";
        Print(secuencia, size_secuencia);
      }
      --f;
    }
      if (traza) {
        std::cout << "\nComparacion: " << secuencia->at(i) << " < " << aux << " : false";
        Print(secuencia, size_secuencia);
      }
    if ( i <= f) {
      std::swap(secuencia->at(i), secuencia->at(f));
      if (traza) {
        std::cout << "\nComparacion: " << i << " <= " << f << " : true -> swap ( " << secuencia->at(i) << " " << secuencia->at(f) << " )";
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
    while ((j >= del) && (aux < secuencia->at( j - del))) {
      flag = false;
      flag2 = false;
      if (traza) {
        std::cout << "\nComparacion: " << aux << " < " << secuencia->at( j - del) << " : true";
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
            std::cout << "\nComparacion: " << aux << " < " << secuencia->at( j -del ) << " : false";
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

template <class Clave>
void Seleccion (std::vector<Clave>* secuencia, int size_secuencia, bool traza) {
  Clave aux;
  int minimo = 0;
  for (int i = 1; i < (size_secuencia - 1); ++i) {
    for (int i = 1; i < (size_secuencia - 1); ++i) {
      minimo = i;
      for (int j = (i + 1); j < size_secuencia; ++j) {
        if (secuencia->at(j) < secuencia->at(minimo)) {
          if (traza) {
            std::cout << "Comparacion: " << secuencia->at(j) << " < " << secuencia->at(minimo) << " : true";
          }
          minimo = j;
          if (traza) {
            Print(secuencia, size_secuencia);
          }
        }

        if (traza) {
          std::cout << "Comparacion: " << secuencia->at(j) << " < " << secuencia->at(minimo) << " : false";
          Print(secuencia, size_secuencia);
        }
      }
      aux = secuencia->at(minimo);
      secuencia->at(minimo) = secuencia->at(i);
      secuencia->at(i) = aux;
    }
  }
}

template <class Clave>
void Mezcla (std::vector<Clave>* secuencia, int inicio, int centro, int fin, bool traza) {
  std::vector<Clave> aux;
  aux.resize(secuencia->size());
  int i = inicio;
  int k = inicio;
  int j = centro + 1;
  while ((i <= centro) && (j <= fin)) {
    if (secuencia->at(i) < secuencia->at(j)) {
      aux.at(k) = secuencia->at(i);
      ++i;
    } else {
      aux.at(k) = secuencia->at(j);
      ++j;
    }
    ++k;
  }
  if ( i > centro) {
    while (j <= fin) {
      aux.at(k) = secuencia->at(j);
      ++j;
      ++k;
    } 
  } else {
      while (i <= centro) {
        aux.at(k) = secuencia->at(i);
        ++i;
        ++k;
      }
  }
  for (int m = inicio; m <= fin; ++m ) {
    secuencia->at(m) = aux.at(m);
  }
}

template <class Clave>
void Msort (std::vector<Clave>* secuencia, int inicio, int fin, bool traza) {
  int centro = 0;
  if (inicio < fin) {
    centro = (inicio + fin) / 2;
    Msort(secuencia, inicio, centro, traza);
    Msort(secuencia, centro + 1, fin, traza);
    Mezcla(secuencia, inicio, centro, fin, traza);
  }
}


template <class Clave>
void MergeSort (std::vector<Clave>* secuencia, int size_secuencia, bool traza) {
  int inicio = 0, fin = size_secuencia - 1;
  Msort(secuencia, inicio, fin, traza);
}

template <class Clave>
void HeapSort (std::vector<Clave>* secuencia, int size_secuencia, bool traza) {

}