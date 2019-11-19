#ifndef THECHAINEDMEMENTO_HPP
#define THECHAINEDMEMENTO_HPP

#include "Memento.hpp"

namespace DIM {
  
  class TheChainedMemento : public Memento {
  private:
    TheChainedMemento(float t = 0);

    float time;

    float getTime() const;

  public:
    TheChainedMemento(const TheChainedMemento&) = default;
    ~TheChainedMemento();
    
    void saveToFile(std::ostream& file) override;
    static TheChainedMemento loadFromFile(std::istream& file);

    friend class TheChained;
  };

}

#endif