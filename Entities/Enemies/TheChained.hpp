#ifndef THECHAINED_HPP
#define THECHAINED_HPP

#include "Enemy.hpp"
#include "../TheMirrorOfHastur.hpp"

namespace DIM {
  
  class TheChained : public Enemy {
    
    private:
      const VectorF spellSpeed;
      TheMirrorOfHastur* mirror;
      const float delay;
      float time;
      const unsigned nProjectiles;

    public:
      TheChained(TheMirrorOfHastur* m = nullptr);
      ~TheChained();
      void initializeSpecific() override;

      void update(float elapsedTime) override;
      void collided(std::string Id, VectorF position, VectorF size) override;
  };

}

#endif