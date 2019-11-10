#ifndef TILEMANAGERMEMENTO_HPP
#define TILEMANAGERMEMENTO_HPP

#include "Memento.hpp"

namespace DIM
{
  class TileManagerMemento : public Memento {
  private:

  public:
    TileManagerMemento();
    ~TileManagerMemento();
  };
  
} // namespace DIM

#endif