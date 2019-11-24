#ifndef THECHAINED_HPP
#define THECHAINED_HPP

#include "Enemy.hpp"
#include "../TheMirrorOfHastur.hpp"
#include "../Mementos/TheChainedMemento.hpp"

namespace DIM {
  namespace Entities {
  
    class TheChained : public Enemy {
    private:
      const Utils::VectorF spellSpeed;
      TheMirrorOfHastur* mirror;
      const float delay;
      float time;
      const unsigned nProjectiles;

    public:
      TheChained(TheMirrorOfHastur* m = nullptr);
      ~TheChained();
      void initializeSpecific() override;

      void update(float elapsedTime) override;
      void collided(std::string other_id, Utils::VectorF positionOther, Utils::VectorF size) override;

      void setMirror(TheMirrorOfHastur* m);

      Mementos::TheChainedMemento createMemento() const;
      void loadMemento(Mementos::TheChainedMemento memento);
    };

  }
}

#endif