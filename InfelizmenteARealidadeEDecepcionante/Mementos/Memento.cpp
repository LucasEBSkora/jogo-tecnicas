#include "Memento.hpp"

#include <iostream>

namespace DIM {

  Memento::Memento() {
    
  }

  Memento::~Memento() {

  }

  Memento::loadFromFile(std::istream& file) {
    // nunca deve ser chamada
    std::cout << "tchauzinho\n";
    exit(123);
  }

}
