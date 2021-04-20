#pragma once

#include <iostream>

#include "funcionordenacion.hpp"

template< class Clave>
class foInsercion: public FuncionOrdenacion<Clave> {
  public:
    foInsercion (const int& numero_elementos, const bool& aleatorios, const bool& traza); //: FuncionOrdenacion(numero_elementos, aleatorios, traza) {}
    void print() const;
    void ordenacion() const {
      for (int i = 1; i < this->secuencia_.size(); ++i) {
        int j = i - 1;
        while ((this->secuencia_.at(i) < this->secuencia_.at(j)) && (j > 0)) {
          if (this->traza_) {
            std::cout << "Comparacion " << this->secuencia_.at(i) << " < " << this->secuencia_.at(j) << ": true";
            this->print();
          }
          --j;
        }

        if (this->traza_) {
          std::cout << "Comparacion " << this->secuencia_.at(i) << " < " << this->secuencia_.at(j) << ": false";
          this->print();
        }

        this->secuencia_.insert(j+1,this->secuencia_.at(i));
        this->secuencia_.erase(i+1);
      }
    }
};

template<class Clave>
foInsercion<Clave>::foInsercion(const int& numero_elementos, const bool& aleatorios, const bool& traza) 
: FuncionOrdenacion<Clave>(numero_elementos, aleatorios, traza) {}

template <class Clave>
void foInsercion<Clave>::print() const{
  std::cout << "Secuencia: ";
  for (int i = 0; i < this->secuencia_.size(); ++i) {
    std::cout << this->secuencia_.at(i);
  }
  std::cout << std::endl;
}