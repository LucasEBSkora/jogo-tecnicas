#include "TheUndying.hpp"
#include <iostream>

namespace DIM {
  TheUndying::TheUndying() : Mob() {
    id = std::string("Player1");
    max_speed = .02;
  }

  TheUndying::~TheUndying() {
    if (movement_id != 0) {
      event_man->removeKeyboardListener(movement_id);
      movement_id = 0;
    }
  }

  void TheUndying::update(float elapsedTime) {
    x += vx * elapsedTime;
    y += vy * elapsedTime;
  }

  void TheUndying::draw() const {
    if (manager != nullptr) {
      manager->draw("assets/TheUndying.png", VectorF(x, y));
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void TheUndying::initializeSpecific() {
    manager->loadAsset("assets/TheUndying.png");
    movement_id = event_man->addKeyboardListener(
      [this] (EventManager::Key k, EventManager::EventType t) {
        if (t == EventManager::EventType::Pressed) {
          switch (k) {
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
        } else if (t == EventManager::EventType::Released) {
          switch (k) {
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

