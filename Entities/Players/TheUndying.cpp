#include "TheUndying.hpp"
#include <iostream>

#include "../../Levels/TempleLevel.hpp"

namespace DIM {
  TheUndying::TheUndying() : Mob(), movement_id(0), pressed(), jumping(false), deathCounter{0} {
    id = std::string("Player1");
    max_speed_x = 80;
    max_speed_y = 330;
  }

  TheUndying::~TheUndying() {

  }

  void TheUndying::unsubscribe() {
    if (movement_id != 0) {
      currentLevel->getEventManager()->removeKeyboardListener(movement_id);
      movement_id = 0;
    }
  }

  void TheUndying::update(float elapsedTime) {
    // if (jumping) {
    if (std::abs(velocity.y) <= 5) jumping = false;
    else jumping = true;
      velocity.y += 500 * elapsedTime;
      // std::cout << velocity.y << " kk ue " << std::endl;
    // } else {
      // velocity.y = 0;
    // }
    if (std::abs(velocity.x) > max_speed_x) {
      velocity.x = max_speed_x * (velocity.x > 0 ? 1 : -1);
    }
    if (std::abs(velocity.y) > max_speed_y) {
      velocity.y = max_speed_y * (velocity.y > 0 ? 1 : -1);
    }
    position += velocity * elapsedTime;
  }

  void TheUndying::draw() const {
    if (currentLevel != nullptr) {
      currentLevel->getGraphicsManager()->draw("assets/TheUndying.png", position);
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
    std::cout << position << std::endl;
  }

  void TheUndying::initializeSpecific() {
    currentLevel->getGraphicsManager()->loadAsset("assets/TheUndying.png");
    VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset("assets/TheUndying.png");
    width = size.x;
    height = size.y;
    movement_id = currentLevel->getEventManager()->addKeyboardListener(
      [this] (EventManager::Event e) {
        if (e.getType() == EventManager::EventType::KeyPressed) {
          switch (e.getKey()) {
            case EventManager::Key::W:
              pressed[0] = true;
              // velocity.y -= max_speed_y;
              break;
            case EventManager::Key::A:
              pressed[1] = true;
              velocity.x -= max_speed_x;
              break;
            case EventManager::Key::S:
              pressed[2] = true;
              // velocity.y += max_speed_y;
              break;
            case EventManager::Key::D:
              pressed[3] = true;
              velocity.x += max_speed_x;
              break;
            case EventManager::Key::Space:
              if (!jumping) {
                jumping = true;
                velocity.y -= 2 * max_speed_y;
              }
              break;
            default:
              break;
          }
        } else if (e.getType() == EventManager::EventType::KeyReleased) {
          switch (e.getKey()) {
            case EventManager::Key::W:
              if (pressed[0]) {
                pressed[0] = false;
                // velocity.y += max_speed_y;
              }
              break;
            case EventManager::Key::A:
              if (pressed[1]) {
                pressed[1] = false;
                velocity.x += max_speed_x;
              }
              break;
            case EventManager::Key::S:
              if (pressed[2]) {
                pressed[2] = false;
                // velocity.y -= max_speed_y;
              }
              break;
            case EventManager::Key::D:
              if (pressed[3]) {
                pressed[3] = false;
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

  void TheUndying::collided(std::string other_id, VectorF positionOther, VectorF size) {
    
    if (other_id == "Spike" || other_id == "Bullet" || other_id == "Spell" || other_id == "Caster" || other_id == "Leaper" || other_id == "Hole") {
      
      std::cout << "you are dead!";
      ++deathCounter;
      if (deathCounter > 0) std::cout << " (" << deathCounter << " times)";
      std::cout << std::endl;
      VectorF spawn = currentLevel->getPlayer1Spawn();

      position = spawn;
      velocity = VectorF();
      for (int i = 0; i < 5; ++i) {
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
    if (adjusts.y < 0) { // quase funciona
      jumping = false;

      velocity.y = 0;
    } else if (adjusts.y > 0) {
      velocity.y = 0;
    }
    PhysicalEntity::adjust();
  }

}

