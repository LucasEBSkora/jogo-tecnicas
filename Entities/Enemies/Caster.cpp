#include "Caster.hpp"

#include <iostream>

#include "../../Levels/Level.hpp"
#include "../Projectiles/Spell.hpp"
#include "../../Utils/RandomValueGenerator.hpp"

namespace DIM {
  namespace Entities {
    namespace Mobs {

      const float Caster::spellSpeed{50};  

      Caster::Caster() : Enemy("assets/Caster.png"), delay(4000 + Utils::RandomValueGenerator::getInstance()->getRandomIntInRange(200, 1400)) {
        id = std::string("Caster");
        max_speed_x = 20 + Utils::RandomValueGenerator::getInstance()->getRandomFloatInRange(-8, 8);
        max_speed_y = 40 + Utils::RandomValueGenerator::getInstance()->getRandomFloatInRange(-15, 15);
      }

      Caster::~Caster() {
          
      }

      void Caster::update(float elapsedTime) {

        Utils::VectorF player = currentLevel->getPlayer1Center();

        velocity.x = ((player.x < position.x + width / 2) ? -1 : 1) * max_speed_x;

        
        if (position.y - player.y > - 120) velocity.y = -max_speed_y;
        else if (position.y - player.y < -140) velocity.y = max_speed_y;


        if (delay != 0) {
          
          --delay;
        } else {
      
          delay = Utils::RandomValueGenerator::getInstance()->getRandomIntInRange(1200, 2800);

          Utils::VectorF direction = (player - position -  getSize() * (0.5));
      
          if (direction.module() < 300) {
            
            currentLevel->addPhysicalEntity(new Projectiles::Spell(position + getSize() * 0.5, direction.unitVector() * spellSpeed));
          }

        }

        position += velocity * elapsedTime * Utils::RandomValueGenerator::getInstance()->getRandomFloatInRange(0.5, 1.5); 
        
      }

      void Caster::collided(std::string other_id, Utils::VectorF positionOther, Utils::VectorF size) {

        if (other_id == "Wall" || other_id == "Spawn" || other_id == "Spike") {
          float dist_x = (static_cast<float>(width) + size.x) / 2 - std::abs(position.x + static_cast<float>(width) / 2 - positionOther.x - size.x / 2);
          float dist_y = (static_cast<float>(height) + size.y) / 2 - std::abs(position.y + static_cast<float>(height) / 2 - positionOther.y - size.y / 2);
          
          if (dist_x * dist_y > .001 * width * height) {
            if (dist_x < dist_y) {
              // colisão em X
              if (dist_x > std::abs(adjusts.x)) {
                adjusts.x = dist_x * (position.x + static_cast<float>(width) / 2 > positionOther.x + size.x / 2 ? 1 : -1);
              }
            } else {
              // colisão em Y
              if (dist_y > std::abs(adjusts.y)) {
                adjusts.y = dist_y * (position.y + static_cast<float>(height) / 2 > positionOther.y + size.y / 2 ? 1 : -1);
              }
            }
          }
        }
      }

      void Caster::adjust() {
        if (adjusts.y < 0) {
          velocity = Utils::VectorF();
          velocity.y = 0;
          velocity.x = 0;
        } else if (adjusts.y > 0) {
          velocity.y = 0;
        }
        PhysicalEntity::adjust();
      }

      Mementos::CasterMemento Caster::createMemento() const {
        Mementos::CasterMemento memento(position, velocity, delay, max_speed_x, max_speed_y);
        return memento;
      }

      void Caster::loadMemento(Mementos::CasterMemento memento) {
        position = memento.getPosition();
        velocity = memento.getVelocity();
        delay = memento.getDelay();
        max_speed_x = memento.getMaxSpeedX();
        max_speed_y = memento.getMaxSpeedY();
      }
    }

  }
}