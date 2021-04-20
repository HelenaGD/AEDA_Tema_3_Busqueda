#pragma once

#include <vector>
#include <ctime>
#include <iostream>

#define MAXIMO 1000
#define MINIMO 1

template <class Clave>
class FuncionOrdenacion {
 public:
  FuncionOrdenacion(const int& numero_elementos, const bool& aleatorios,const bool& traza);
  ~FuncionOrdenacion() {}
  virtual void ordenacion() const = 0;
  //virtual unsigned operator() (const Clave& k) const = 0;
 protected:
  std::vector<Clave> secuencia_;
  bool traza_;
};

template <class Clave>
FuncionOrdenacion<Clave>::FuncionOrdenacion(const int& numero_elementos, const bool& aleatorios, const bool& traza) {
  traza_ = traza;
  secuencia_.resize(numero_elementos);
  if (!aleatorios) {
    for (int i = 0; i < secuencia_.size(); ++i) {
      std::cout << "Elemento: ";
      std::cin >> secuencia_.at(i);
    }
  } else {
    srand(time(NULL));
    for (int i = 0; i < secuencia_.size(); ++i) {
      secuencia_.at(i) = rand() % (MAXIMO - MINIMO - 1) + MINIMO;
    }
  }
}

