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
      adjusts = Utils::VectorF(0, 0);
    }

    Utils::VectorF PhysicalEntity::getPos() const {
      return position;
    }

    void PhysicalEntity::setPos(Utils::VectorF pos) {
      position = pos;
    }

    Utils::VectorF PhysicalEntity::getSize() const {
      return Utils::VectorF(width, height);
    }

    std::string PhysicalEntity::getID() const {
      return id;
    }

    Levels::Level* PhysicalEntity::getLevel() const {
      return currentLevel;
    }

  }
}