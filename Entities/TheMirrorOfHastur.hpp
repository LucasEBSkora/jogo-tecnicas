#ifndef THEMIRROROFHASTUR_HPP
#define THEMIRROROFHASTUR_HPP

#include "PhysicalEntity.hpp"

namespace DIM {

  class TheMirrorOfHastur : public PhysicalEntity {
    
    private:
      bool boundToPlayer;
      VectorF initialPosition;
      static const char* path;

    public:
      TheMirrorOfHastur();
      ~TheMirrorOfHastur();

      void initializeSpecific() override;
      void update(float elapsedTime) override;
      void collided(std::string id, VectorF positionOther, VectorF size) override;
      void draw() const override;

  };
  
} // namespace DIM

#endif