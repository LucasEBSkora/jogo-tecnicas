#include "TheChained.hpp"

#include <iostream>

#include "../../RandomValueGenerator.hpp"
#include "../../Levels/Level.hpp"
#include "../Projectiles/Spell.hpp"
#include "../TheMirrorOfHastur.hpp"

namespace DIM {
  namespace Entities {

    TheChained::TheChained(TheMirrorOfHastur* m) : Enemy("assets/TheChained.png"), spellSpeed{-100.0f, 0.0f}, mirror{m}, delay{0.1f}, time{0.0f}, nProjectiles{15} {
      id = std::string("Boss");
    }

    TheChained::~TheChained() {
        
    }

    void TheChained::initializeSpecific() {
      Enemy::initializeSpecific();
      position = currentLevel->getBossSpawn() - Utility::VectorF(width, height) * 0.5;
    }

    void TheChained::update(float elapsedTime) {
      
      time += elapsedTime;

      if (time >= delay) {
        
        time = 0;

        if (!mirror->isBound() && (currentLevel->getPlayer1Center() - position).module() < 250.0f ) {
          for (unsigned int i = 0; i < nProjectiles; ++i) {
            currentLevel->addPhysicalEntity(new Spell(position + Utility::VectorF(-8, -32.0f + 8 * (i)), spellSpeed));
          }
        }
      }
      
    }

    void TheChained::collided(std::string other_id, Utility::VectorF positionOther, Utility::VectorF size) {
        //doesn't actually collide
    }

    void TheChained::setMirror(TheMirrorOfHastur* m) {
      mirror = m;
    }

    Mementos::TheChainedMemento TheChained::createMemento() const {
      Mementos::TheChainedMemento memento(time);
      return memento;
    }

    void TheChained::loadMemento(Mementos::TheChainedMemento memento) {
      time = memento.getTime();
    }

  }
}