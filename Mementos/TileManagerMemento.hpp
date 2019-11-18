#ifndef TILEMANAGERMEMENTO_HPP
#define TILEMANAGERMEMENTO_HPP

#include "Memento.hpp"

namespace DIM
{
  class TileManagerMemento : public Memento {
  private:
    TileManagerMemento();

  public:
    ~TileManagerMemento();

    void saveToFile(std::ostream& file) override;
    friend class TileManager;
  };
  
} // namespace DIM

#endif