#ifndef THECHAINEDMEMENTO_HPP
#define THECHAINEDMEMENTO_HPP

#include "Memento.hpp"

namespace DIM {

  namespace Entities {
    namespace Mobs {
      class TheChained;
    }
  }

  namespace Mementos {
    
    class TheChainedMemento : public Memento {
    private:
      TheChainedMemento(float t = 0);

      float time;

      float getTime() const;

    public:
      ~TheChainedMemento();
      
      void saveToFile(std::ostream& file) override;
      static TheChainedMemento loadFromFile(std::istream& file);

      friend class Entities::Mobs::TheChained;
    };

  }
}

#endif