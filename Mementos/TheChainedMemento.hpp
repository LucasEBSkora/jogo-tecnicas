#ifndef THECHAINEDMEMENTO_HPP
#define THECHAINEDMEMENTO_HPP

#include "Memento.hpp"

namespace DIM {
  
  class TheChainedMemento : public Memento {
  private:
    TheChainedMemento();

  public:
    ~TheChainedMemento();
    friend class TheChained;
  };

}

#endif