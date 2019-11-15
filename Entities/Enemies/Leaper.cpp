#include "Leaper.hpp"
#include <iostream>

#include "../../Levels/Level.hpp"

namespace DIM {
  Leaper::Leaper() : Enemy(), jumping(false), delay(0) {
    id = std::string("Leaper");
    max_speed_x = 60;
    max_speed_y = 230;
  }

  Leaper::~Leaper() {
      
  }

  void Leaper::update(float elapsedTime) {
    VectorF player = current_level->getPlayer1Center();

    if (jumping) {
      vx = max_speed_x * (player.x > x + width / 2 ? 1 : -1);
    }
    if (!jumping && player.y < y + height / 2) {
      if (delay != 0) {
        --delay;
      } else {
        delay = 1000;
        jumping = true;
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
    if (graphics_manager != nullptr) {
      graphics_manager->draw("assets/Leaper.png", VectorF(x, y));
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void Leaper::initializeSpecific() {
    graphics_manager->loadAsset("assets/Leaper.png");
    VectorF size = graphics_manager->getSizeOfAsset("assets/Leaper.png");
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

