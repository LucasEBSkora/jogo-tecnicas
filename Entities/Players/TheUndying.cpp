#include "TheUndying.hpp"
#include <iostream>

namespace DIM {
  TheUndying::TheUndying() : Mob(), movement_id(0), pressed() {
    id = std::string("Player1");
    max_speed = 50;
  }

  TheUndying::~TheUndying() {
    if (movement_id != 0) {
      event_man->removeKeyboardListener(movement_id);
      movement_id = 0;
    }
  }

  void TheUndying::update(float elapsedTime) {
    if (std::abs(vx) > max_speed) {
      vx = max_speed * (vx > 0 ? 1 : -1);
    }
    if (std::abs(vy) > max_speed) {
      vy = max_speed * (vy > 0 ? 1 : -1);
    }
    x += vx * elapsedTime;
    y += vy * elapsedTime;
    // std::cout << x << ' ' << y << std::endl;
  }

  void TheUndying::draw() const {
    if (graphics_manager != nullptr) {
      graphics_manager->draw("assets/TheUndying.png", VectorF(x, y));
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void TheUndying::initializeSpecific() {
    graphics_manager->loadAsset("assets/TheUndying.png");
    VectorF size = graphics_manager->getSizeOfAsset("assets/TheUndying.png");
    width = size.x;
    height = size.y;
    movement_id = event_man->addKeyboardListener(
      [this] (EventManager::Event e) {
        if (e.getType() == EventManager::EventType::KeyPressed) {
          switch (e.getKey()) {
            case EventManager::Key::W:
              pressed[0] = true;
              vy -= max_speed;
              break;
            case EventManager::Key::A:
              pressed[1] = true;
              vx -= max_speed;
              break;
            case EventManager::Key::S:
              pressed[2] = true;
              vy += max_speed;
              break;
            case EventManager::Key::D:
              pressed[3] = true;
              vx += max_speed;
              break;
            default:
              break;
          }
        } else if (e.getType() == EventManager::EventType::KeyReleased) {
          switch (e.getKey()) {
            case EventManager::Key::W:
              if (pressed[0]) {
                pressed[0] = false;
                vy += max_speed;
              }
              break;
            case EventManager::Key::A:
              if (pressed[1]) {
                pressed[1] = false;
                vx += max_speed;
              }
              break;
            case EventManager::Key::S:
              if (pressed[2]) {
                pressed[2] = false;
                vy -= max_speed;
              }
              break;
            case EventManager::Key::D:
              if (pressed[3]) {
                pressed[3] = false;
                vx -= max_speed;
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

    float dist_x = (static_cast<float>(width) + size.x) / 2 - std::abs(x + static_cast<float>(width) / 2 - position.x - size.x / 2);
    float dist_y = (static_cast<float>(height) + size.y) / 2 - std::abs(y + static_cast<float>(height) / 2 - position.y - size.y / 2);

    if (other_id == "Wall" || other_id == "Spawn" || other_id == "Spike") { // rever ids dessas tiles (não servem pro propósito que foram criadas)
      if (dist_x < dist_y) {
        // colisão em X
        adjusts.x += dist_x * (x + static_cast<float>(width) / 2 > position.x + size.x / 2 ? 1 : -1);
      } else {
        // colisão em Y
        adjusts.y += dist_y * (y + static_cast<float>(height) / 2 > position.y + size.y / 2 ? 1 : -1);
      }
    }
  }

  std::string TheUndying::getID() const {
    return id;
  }
}

