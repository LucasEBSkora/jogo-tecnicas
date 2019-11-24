#include "ThePenitent.hpp"
#include <iostream>
#include <cmath>
#include "../Levels/Level.hpp"

namespace DIM {
  namespace Entities {

    ThePenitent::ThePenitent() : Mob(), movement_id(0), angle(0), radius(35) {
      id = std::string("Player2");  
    }

    ThePenitent::~ThePenitent() {
      if (movement_id != 0) {
        if (currentLevel != nullptr && currentLevel->getEventManager() != nullptr) {
          currentLevel->getEventManager()->removeMouseListener(movement_id);
        }
        movement_id = 0;
      }
    }

    void ThePenitent::update(float elapsedTime) {
      Utils::VectorF p1_pos = currentLevel->getPlayer1Center();
      
      position = p1_pos + Utils::VectorF(std::cos(angle), std::sin(angle)) * radius - Utils::VectorF(width, height) * (0.5);
    }

    void ThePenitent::draw() const {
      if (currentLevel != nullptr) {
        currentLevel->getGraphicsManager()->draw("assets/ThePenitent.png", position);
      } else {
        std::cout << "desenhando objeto nao inicializado\n";
      }
    }

    void ThePenitent::initializeSpecific() {
      currentLevel->getGraphicsManager()->loadAsset("assets/ThePenitent.png");
      Utils::VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset("assets/ThePenitent.png");
      width = size.x;
      height = size.y;
      
      movement_id = currentLevel->getEventManager()->addMouseListener(
        [this] (Managers::EventManager::Event e) {
          if (e.getType() == Managers::EventManager::EventType::MouseWheelScrolledUp) {
            angle -= 0.2;
          } else if (e.getType() == Managers::EventManager::EventType::MouseWheelScrolledDown) {
            angle += 0.2;
          }
        }
      );
    }

    void ThePenitent::collided(std::string Id, Utils::VectorF positionOther, Utils::VectorF size) {
      
    }

    Mementos::ThePenitentMemento ThePenitent::createMemento() const {
      Mementos::ThePenitentMemento memento(position, angle, radius);
      return memento;
    }

    void ThePenitent::loadMemento(Mementos::ThePenitentMemento memento) {
      position = memento.getPosition();
      angle = memento.getAngle();
      radius = memento.getRadius();
    }

  }
}