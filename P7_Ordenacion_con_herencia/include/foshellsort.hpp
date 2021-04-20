#pragma once
#include "funcionordenacion.hpp"

template< class Clave>
class foShellSort: public FuncionOrdenacion<Clave> {
  public:
    foShellSort (const int numero_elementos, const bool aleatorios, const bool traza) : FuncionOrdenacion(numero_elementos, aleatorios, traza) {}
    void ordenacion() const {

    }
};