#ifndef CASTERMEMENTO_HPP
#define CASTERMEMENTO_HPP

#include "Memento.hpp"

namespace DIM
{
  class CasterMemento : public Memento {
  private:

  public:
    CasterMemento();
    ~CasterMemento();
  };
  
} // namespace DIM

#endif