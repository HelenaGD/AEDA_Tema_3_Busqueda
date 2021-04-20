#pragma once
#include "funcionordenacion.hpp"

template< class Clave>
class foQuickSort: public FuncionOrdenacion<Clave> {
  public:
    foQuickSort (const int numero_elementos, const bool aleatorios, const bool traza) : FuncionOrdenacion(numero_elementos, aleatorios, traza) {}
    void ordenacion() const {

    }
};