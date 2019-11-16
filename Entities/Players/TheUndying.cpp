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
    if (movement_id != 0) {
      currentLevel->getEventManager()->removeKeyboardListener(movement_id);
      movement_id = 0;
    }
  }

  void TheUndying::update(float elapsedTime) {
    // if (jumping) {
      vy += 500 * elapsedTime;
      // std::cout << vy << " kk ue " << std::endl;
    // } else {
      // vy = 0;
    // }
    if (std::abs(vx) > max_speed_x) {
      vx = max_speed_x * (vx > 0 ? 1 : -1);
    }
    if (std::abs(vy) > max_speed_y) {
      vy = max_speed_y * (vy > 0 ? 1 : -1);
    }
    x += vx * elapsedTime;
    y += vy * elapsedTime;
    // std::cout << x << ' ' << y << std::endl;
  }

  void TheUndying::draw() const {
    if (currentLevel != nullptr) {
      currentLevel->getGraphicsManager()->draw("assets/TheUndying.png", VectorF(x, y));
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
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
              // vy -= max_speed_y;
              break;
            case EventManager::Key::A:
              pressed[1] = true;
              vx -= max_speed_x;
              break;
            case EventManager::Key::S:
              pressed[2] = true;
              // vy += max_speed_y;
              break;
            case EventManager::Key::D:
              pressed[3] = true;
              vx += max_speed_x;
              break;
            case EventManager::Key::Space:
              if (!jumping) {
                jumping = true;
                vy -= 2 * max_speed_y;
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
                // vy += max_speed_y;
              }
              break;
            case EventManager::Key::A:
              if (pressed[1]) {
                pressed[1] = false;
                vx += max_speed_x;
              }
              break;
            case EventManager::Key::S:
              if (pressed[2]) {
                pressed[2] = false;
                // vy -= max_speed_y;
              }
              break;
            case EventManager::Key::D:
              if (pressed[3]) {
                pressed[3] = false;
                vx -= max_speed_x;
              }
              break;
            default:
              break;
          }
        }
      }
    );
  }

  void TheUndying::collided(std::string other_id, VectorF position, VectorF size) {
    if (other_id != "Wall") std::cout << other_id << std::endl;
    if (other_id == "Spike" || other_id == "Bullet") {
      
      std::cout << "you are dead!";
      if (deathCounter > 0) std::cout << " (again)";
      std::cout << std::endl;
      VectorF spawn = currentLevel->getPlayer1Spawn();

      x = spawn.x;
      y = spawn.y;

      ++deathCounter;
      
    } else if (other_id == "Wall" || other_id == "Spawn") {
      float dist_x = (static_cast<float>(width) + size.x) / 2 - std::abs(x + static_cast<float>(width) / 2 - position.x - size.x / 2);
      float dist_y = (static_cast<float>(height) + size.y) / 2 - std::abs(y + static_cast<float>(height) / 2 - position.y - size.y / 2);
      
      if (dist_x * dist_y > .001 * width * height) { // passa a ignorar colisões ignoráveis (bem as problemáticas)
        if (dist_x < dist_y) {
          // colisão em X
          if (dist_x > std::abs(adjusts.x)) {
            adjusts.x = dist_x * (x + static_cast<float>(width) / 2 > position.x + size.x / 2 ? 1 : -1);
          }
        } else {
          // colisão em Y
          if (dist_y > std::abs(adjusts.y)) {
            adjusts.y = dist_y * (y + static_cast<float>(height) / 2 > position.y + size.y / 2 ? 1 : -1);
          }
        }
      }
    }
  }

  void TheUndying::adjust() {
    if (adjusts.y < 0) { // quase funciona
      jumping = false;
      vy = 0;
    } else if (adjusts.y > 0) {
      vy = 0;
    }
    PhysicalEntity::adjust();
  }

  std::string TheUndying::getID() const {
    return id;
  }
}

