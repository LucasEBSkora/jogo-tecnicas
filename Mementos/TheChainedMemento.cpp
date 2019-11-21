#include "TheChainedMemento.hpp"

namespace DIM {
  namespace Mementos {
  
    TheChainedMemento::TheChainedMemento(float t) {
      time = t;
    }

    float TheChainedMemento::getTime() const {
      return time;
    }
    
    TheChainedMemento::~TheChainedMemento() {

    }

    void TheChainedMemento::saveToFile(std::ostream& file) {
      file << time << '\n';
    }

    TheChainedMemento TheChainedMemento::loadFromFile(std::istream& file) {
      TheChainedMemento memento;
      file >> memento.time;
      return memento;
    }

  }
}