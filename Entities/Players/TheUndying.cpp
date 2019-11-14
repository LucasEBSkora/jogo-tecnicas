#include "TheUndying.hpp"
#include <iostream>

namespace DIM {
  TheUndying::TheUndying() : Mob(), movement_id(0) {
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
              vy -= max_speed;
              break;
            case EventManager::Key::A:
              vx -= max_speed;
              break;
            case EventManager::Key::S:
              vy += max_speed;
              break;
            case EventManager::Key::D:
              vx += max_speed;
              break;
            default:
              break;
          }
        } else if (e.getType() == EventManager::EventType::KeyReleased) {
          switch (e.getKey()) {
            case EventManager::Key::W:
              vy += max_speed;
              break;
            case EventManager::Key::A:
              vx += max_speed;
              break;
            case EventManager::Key::S:
              vy -= max_speed;
              break;
            case EventManager::Key::D:
              vx -= max_speed;
              break;
            default:
              break;
          }
        }
      }
    );
  }

  void TheUndying::collided(std::string Id, VectorF position) {
    
  }

  std::string TheUndying::getID() const {
    return id;
  }
}

