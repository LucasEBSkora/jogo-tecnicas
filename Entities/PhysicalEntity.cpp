#include "PhysicalEntity.hpp"

#include "../GeometricVector.hpp"

namespace DIM {
  namespace Entities {

    PhysicalEntity::PhysicalEntity() : Entity(), width(0), height(0), adjusts(0, 0) {
      
    }

    PhysicalEntity::~PhysicalEntity() {

    }

    void PhysicalEntity::adjust() {
      position += adjusts;
      adjusts = Utility::VectorF(0, 0);
    }

    Utility::VectorF PhysicalEntity::getPos() const {
      return position;
    }

    void PhysicalEntity::setPos(Utility::VectorF pos) {
      position = pos;
    }

    Utility::VectorF PhysicalEntity::getSize() const {
      return Utility::VectorF(width, height);
    }

    std::string PhysicalEntity::getID() const {
      return id;
    }

    Levels::Level* PhysicalEntity::getLevel() const {
      return currentLevel;
    }

  }
}