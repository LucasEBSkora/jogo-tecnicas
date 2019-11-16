#include "PhysicalEntity.hpp"

#include "../Vector.hpp"

namespace DIM {

  PhysicalEntity::PhysicalEntity() : Entity(), width(0), height(0), adjusts(0, 0) {
    
  }

  PhysicalEntity::~PhysicalEntity() {

  }

  void PhysicalEntity::adjust() {
    x += adjusts.x;
    y += adjusts.y;
    adjusts = VectorF(0, 0);
  }

  VectorF PhysicalEntity::getPos() const {
    return VectorF(x, y);
  }

  void PhysicalEntity::setPos(VectorF pos) {
    x = pos.x;
    y = pos.y;
  }

  VectorF PhysicalEntity::getSize() const {
    return VectorF(width, height);
  }

}