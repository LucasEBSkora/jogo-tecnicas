#include "PhysicalEntity.hpp"

namespace DIM {

  PhysicalEntity::PhysicalEntity() : width(0), height(0) {
    
  }

  PhysicalEntity::~PhysicalEntity() {

  }


  VectorF PhysicalEntity::getPos() const {
    return VectorF(x, y);
  }

  VectorF PhysicalEntity::getSize() const {
    return VectorF(width, height);
  }

}