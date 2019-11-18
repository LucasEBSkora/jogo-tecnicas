#ifndef THEUNDYINGMEMENTO_HPP
#define THEUNDYINGMEMENTO_HPP

#include "Memento.hpp"

namespace DIM
{
  class TheUndyingMemento : public Memento {
  private:
    TheUndyingMemento();

  public:
    ~TheUndyingMemento();

    void saveToFile(std::ostream& file) override;
    friend class TheUndying;
  };
  
} // namespace DIM

#endif