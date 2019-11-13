#include "ThePenitent.hpp"
#include <iostream>
#include <cmath>

namespace DIM {

  ThePenitent::ThePenitent() : Mob(), movement_id(0), angle(0), radius(35) {
    id = std::string("Player2");  
  }

  ThePenitent::~ThePenitent() {
    if (movement_id != 0) {
      event_man->removeKeyboardListener(movement_id);
      movement_id = 0;
    }
  }

  void ThePenitent::update(float elapsedTime) {
    float cx = 50;
    float cy = 50; // pegar do jogador 1
    x = cx + radius * std::cos(angle);
    y = cy + radius * std::sin(angle);
  }

  void ThePenitent::draw() const {
    if (graphics_manager != nullptr) {
      graphics_manager->draw("assets/ThePenitent.png", VectorF(x, y));
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void ThePenitent::initializeSpecific() {
    graphics_manager->loadAsset("assets/ThePenitent.png");
    VectorF size = graphics_manager->getSizeOfAsset("assets/ThePenitent.png");
    width = size.x;
    height = size.y;
    std::cout << "bom dia com [e]ventos" << std::endl;
    movement_id = event_man->addMouseListener(
      [this] (EventManager::Event e) {
        if (e.getType() == EventManager::EventType::MouseWheelScrolled) {
          angle += 0.2;
        }
      }
    );
  }

  void ThePenitent::collided(std::string Id, VectorF position) {
    
  }

  std::string ThePenitent::getID() const {
    return id;
  }
}