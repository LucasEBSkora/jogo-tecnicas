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
    if (!jumping && player.y < y + height / 2) {
      if (delay != 0) {
        --delay;
      } else {
        delay = RandomValueGenerator::getInstance()->getRandomIntInRange(800, 1200);
        jumping = true;
        vx = max_speed_x * (player.x > x + width / 2 ? 1 : -1);
        vy -= 2 * max_speed_y;
      }
    }
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

  void Leaper::draw() const {
    if (currentLevel != nullptr) {
      currentLevel->getGraphicsManager()->draw("assets/Leaper.png", VectorF(x, y));
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

  void Leaper::collided(std::string other_id, VectorF position, VectorF size) {

    if (other_id == "Wall" || other_id == "Spawn" || other_id == "Spike") {
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

  void Leaper::adjust() {
    if (adjusts.y < 0) {
      jumping = false;
      vy = 0;
      vx = 0;
    } else if (adjusts.y > 0) {
      vy = 0;
    }
    PhysicalEntity::adjust();
  }

  std::string Leaper::getID() const {
    return id;
  }
}

