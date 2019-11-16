#include "ThePenitent.hpp"
#include <iostream>
#include <cmath>
#include "../Levels/Level.hpp"

namespace DIM {

  ThePenitent::ThePenitent() : Mob(), movement_id(0), angle(0), radius(35) {
    id = std::string("Player2");  
  }

  ThePenitent::~ThePenitent() {
    if (movement_id != 0) {
      currentLevel->getEventManager()->removeKeyboardListener(movement_id);
      movement_id = 0;
    }
  }

  void ThePenitent::update(float elapsedTime) {
    VectorF p1_pos = currentLevel->getPlayer1Center();
    x = p1_pos.x + radius * std::cos(angle) - width / 2;
    y = p1_pos.y + radius * std::sin(angle) - height / 2;
  }

  void ThePenitent::draw() const {
    if (currentLevel != nullptr) {
      currentLevel->getGraphicsManager()->draw("assets/ThePenitent.png", VectorF(x, y));
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void ThePenitent::initializeSpecific() {
    currentLevel->getGraphicsManager()->loadAsset("assets/ThePenitent.png");
    VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset("assets/ThePenitent.png");
    width = size.x;
    height = size.y;
    //std::cout << "bom dia com [e]ventos e " << current_level << std::endl;
    movement_id = currentLevel->getEventManager()->addMouseListener(
      [this] (EventManager::Event e) {
        if (e.getType() == EventManager::EventType::MouseWheelScrolledUp) {
          angle -= 0.2;
        } else if (e.getType() == EventManager::EventType::MouseWheelScrolledDown) {
          angle += 0.2;
        }
      }
    );
  }

  void ThePenitent::collided(std::string Id, VectorF position, VectorF size) {
    
  }

  std::string ThePenitent::getID() const {
    return id;
  }
}