#include "Leaper.hpp"
#include <iostream>

#include "../../Levels/Level.hpp"
#include "../../RandomValueGenerator.hpp"

namespace DIM {
  Leaper::Leaper() : Enemy(), jumping(false), delay(0) {
    id = std::string("Leaper");
    max_speed_x = 60 + RandomValueGenerator::getInstance()->getRandomFloatInRange(-25, 10);
    max_speed_y = 230 + RandomValueGenerator::getInstance()->getRandomFloatInRange(-40, 40);
  }

  Leaper::~Leaper() {
      
  }

  void Leaper::update(float elapsedTime) {
    VectorF player = currentLevel->getPlayer1Center();

    // if (jumping) {
    // }
    if (!jumping) {
      if (delay != 0) {
        --delay;
      } else {
        delay = RandomValueGenerator::getInstance()->getRandomIntInRange(800, 1200);
        jumping = true;
        velocity.x = max_speed_x * (player.x > position.x + width / 2 ? 1 : -1);
        velocity.y -= 2 * max_speed_y;
      }
    }
    // if (jumping) {
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
    // std::cout << x << ' ' << y << std::endl;
  }

  void Leaper::draw() const {
    if (currentLevel != nullptr) {
      currentLevel->getGraphicsManager()->draw("assets/Leaper.png", position);
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void Leaper::initializeSpecific() {
    currentLevel->getGraphicsManager()->loadAsset("assets/Leaper.png");
    VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset("assets/Leaper.png");
    width = size.x;
    height = size.y;
  }

  void Leaper::collided(std::string other_id, VectorF positionOther, VectorF size) {

    if (other_id == "Wall" || other_id == "Spawn" || other_id == "Spike") {
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
    } else if (other_id == "Hole") {
      currentLevel->markForDelete(this);

    }
  }

  void Leaper::adjust() {
    if (adjusts.y < 0) {
      jumping = false;
      velocity = VectorF();
    } else if (adjusts.y > 0) {
      velocity.y = 0;
    }
    PhysicalEntity::adjust();
  }

}

