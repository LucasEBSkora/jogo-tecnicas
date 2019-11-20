#include "PhysicalEntity.hpp"

#include "../Vector.hpp"

namespace DIM {

  PhysicalEntity::PhysicalEntity() : Entity(), width(0), height(0), adjusts(0, 0) {
    
  }

  PhysicalEntity::~PhysicalEntity() {

  }

  void PhysicalEntity::adjust() {
    position += adjusts;
    adjusts = VectorF(0, 0);
  }

  VectorF PhysicalEntity::getPos() const {
    return position;
  }

  void PhysicalEntity::setPos(VectorF pos) {
    position = pos;
  }

  VectorF PhysicalEntity::getSize() const {
    return VectorF(width, height);
  }

  std::string PhysicalEntity::getID() const {
    return id;
  }

  Level* PhysicalEntity::getLevel() const {
    return currentLevel;
  }

}