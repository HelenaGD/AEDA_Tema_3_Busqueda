#include "lista.hpp"
#include "tablahash.hpp"
#include "funciondispersion.hpp"
#include "fdmodulo.hpp"
#include "fdpseudoaleatoria.hpp"

#include "iostream"

class Testclass {
 public:
  bool ConstructorTablaHash () {
    bool test = false;

    int size_tabla = 1;
    fdModulo<int> *fd1 = new fdModulo<int> (size_tabla);
    fdPseudoaleatoria<int> *fd2 = new fdPseudoaleatoria<int> (size_tabla);

    TablaHash<int> tabla1(size_tabla, fd1);
    TablaHash<int> tabla2(size_tabla, fd2);

    test = (tabla1.get_sizeTabla() == size_tabla);
    test = (tabla2.get_sizeTabla() == size_tabla);
    return test;
  }
};

int main(void) {
  Testclass test;
  bool funcionamiento = false;

  funcionamiento = test.ConstructorTablaHash();
  std::cout << "Test Constructor de la Tabla Hash: ";
  std::cout << ((funcionamiento) ? "ok" : "fallo") << std::endl; 

  return 0;
}