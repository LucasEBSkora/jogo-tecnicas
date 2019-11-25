#include "TheUndying.hpp"
#include <iostream>

#include "../../Levels/TempleLevel.hpp"

namespace DIM {
  namespace Entities {
    namespace Mobs {

      TheUndying::TheUndying() : Mob("assets/TheUndying.png"), movement_id(0), pressed(), jumping(false), deathCounter{0} {
        max_speed_x = 80;
        max_speed_y = 330;
        id = "Player1";
      }

      TheUndying::~TheUndying() {
        if (movement_id != 0) {
          if (currentLevel != nullptr && currentLevel->getEventManager() != nullptr) {
            currentLevel->getEventManager()->removeKeyboardListener(movement_id);
          }
          movement_id = 0;
        }
      }

      void TheUndying::update(float elapsedTime) {
        // if (jumping) {
        if (std::abs(velocity.y) <= 5) jumping = false;
        else jumping = true;
          velocity.y += 500 * elapsedTime;
        if (std::abs(velocity.x) > max_speed_x) {
          velocity.x = max_speed_x * (velocity.x > 0 ? 1 : -1);
        }
        if (std::abs(velocity.y) > max_speed_y) {
          velocity.y = max_speed_y * (velocity.y > 0 ? 1 : -1);
        }
        position += velocity * elapsedTime;
      }



      void TheUndying::initializeSpecific() {
        currentLevel->getGraphicsManager()->loadAsset("assets/TheUndying.png");
        Utils::VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset("assets/TheUndying.png");
        width = size.x;
        height = size.y;
        movement_id = currentLevel->getEventManager()->addKeyboardListener(
          [this] (Managers::EventManager::Event e) {
            if (e.getType() == Managers::EventManager::EventType::KeyPressed) {
              switch (e.getKey()) {
                case Managers::EventManager::Key::A:
                  pressed[0] = true;
                  velocity.x -= max_speed_x;
                  break;
                case Managers::EventManager::Key::D:
                  pressed[1] = true;
                  velocity.x += max_speed_x;
                  break;
                case Managers::EventManager::Key::Space:
                  if (!jumping) {
                    jumping = true;
                    velocity.y -= 2 * max_speed_y;
                  }
                  break;
                default:
                  break;
              }
            } else if (e.getType() == Managers::EventManager::EventType::KeyReleased) {
              switch (e.getKey()) {
                case Managers::EventManager::Key::A:
                  if (pressed[0]) {
                    pressed[0] = false;
                    velocity.x += max_speed_x;
                  }
                  break;
                case Managers::EventManager::Key::D:
                  if (pressed[1]) {
                    pressed[1] = false;
                    velocity.x -= max_speed_x;
                  }
                  break;
                default:
                  break;
              }
            }
          }
        );
      }

      void TheUndying::collided(std::string other_id, Utils::VectorF positionOther, Utils::VectorF size) {
        

        if (other_id == "Spike" || other_id == "Bullet" || other_id == "Spell" || other_id == "Caster" || other_id == "Leaper" || other_id == "Hole") {
          
          std::cout << "you are dead!";
          ++deathCounter;
          if (deathCounter > 0) std::cout << " (" << deathCounter << " times)";
          std::cout << std::endl;
          Utils::VectorF spawn = currentLevel->getPlayer1Spawn();

          position = spawn;
          velocity = Utils::VectorF();
          for (int i = 0; i < 2; ++i) {
            pressed[i] = false;
          }

          
        } else if (other_id == "Wall" || other_id == "Spawn") {
          float dist_x = (static_cast<float>(width) + size.x) / 2 - std::abs(position.x + static_cast<float>(width) / 2 - positionOther.x - size.x / 2);
          float dist_y = (static_cast<float>(height) + size.y) / 2 - std::abs(position.y + static_cast<float>(height) / 2 - positionOther.y - size.y / 2);
          
          if (dist_x * dist_y > .001 * width * height) { // passa a ignorar colisões ignoráveis (bem as problemáticas)
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
        } else if (other_id == "End") {
          currentLevel->endLevel();
        }
      }

      void TheUndying::adjust() {
        if (adjusts.y < 0) {
          jumping = false;

          velocity.y = 0;
        } else if (adjusts.y > 0) {
          velocity.y = 0;
        }
        PhysicalEntity::adjust();
      }

      Mementos::TheUndyingMemento TheUndying::createMemento() const {
        Mementos::TheUndyingMemento memento(position, velocity, max_speed_x, max_speed_y, jumping, deathCounter);
        return memento;
      }

      void TheUndying::loadMemento(Mementos::TheUndyingMemento memento) {
        position = memento.getPosition();
        velocity = memento.getVelocity();
        max_speed_x = memento.getMaxSpeedX();
        max_speed_y = memento.getMaxSpeedY();
        jumping = memento.getJumping();
        deathCounter = memento.getDeathCounter();
      }

      const unsigned int TheUndying::getDeathCounter() const {
        return deathCounter;
      }
    }
  }
}

