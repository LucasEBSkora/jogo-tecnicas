#include "TheUndying.hpp"
#include <iostream>

namespace DIM {
  TheUndying::TheUndying() : Mob(), movement_id(0), pressed(), adjusts(0, 0) {
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

  void TheUndying::collided(std::string Id, VectorF position, VectorF size) {
    // vx = 0;
    // vy = 0;

    // VectorF center = getPos() + getSize() * .5;
    // float cte =.5;
    // vx += (center.x - position.x) * cte;
    // vy += (center.y - position.y) * cte;

    // if (x < position.x && position.x < x + width) {
    //   // colisão em y
    //   std::cout << "coliso Y" << std::endl;
    //   for (int i = 0; i < 4; i += 2) {
    //     pressed[i] = false;
    //   }
    //   vy = -vy;
    // } else {
    //   // colisão em x
    //   std::cout << "coliso X" << std::endl;
    //   for (int i = 1; i < 4; i += 2) {
    //     pressed[i] = false;
    //   }
    //   vx = -vx;
    // }

    // if (y > position.y && y + height < position.y + size.y) {
    //   // com certeza colisão em X
    //   std::cout << "coliso X ctz" << std::endl;
    //   vx = -vx;
    // } else if (x > position.x && x + width < position.x + size.x) {
    //   // com certeza colisão em Y
    //   std::cout << "coliso Y ctz" << std::endl;
    //   vy = -vy;
    // } else {
    //   std::cout << "eu nao fiz nada" << std::endl;
    //   std :: cout << x << ' ' << y << ' ' << position.x << ' ' << position.y << ' ' << width << ' ' << height << ' ' << size.x << ' ' << size.y << std::endl;
    // } melhor até agora

    // dx = (w1 + w2) / 2 - abs(x1 + w1 / 2 - x2 + w2 / 2)

    // VectorF c1 = VectorF(x, y) + VectorF(width, height) * .5;
    // VectorF c2 = pos2 + size2 * .5;

    // return (abs(c1.x - c2.x) < (size1.x + size2.x) / 2 &&
    //         abs(c1.y - c2.y) < (size1.y + size2.y) / 2);

    float dist_x = (static_cast<float>(width) + size.x) / 2 - std::abs(x + static_cast<float>(width) / 2 - position.x - size.x / 2);
    float dist_y = (static_cast<float>(height) + size.y) / 2 - std::abs(y + static_cast<float>(height) / 2 - position.y - size.y / 2);
    // std::cout << dist_x << ' ' << dist_y << std::endl;
    if (dist_x < dist_y) {
      // acho que colisão em X
      // std::cout << "coliso X ?" << ' ' << x + width / 2  << ' ' << position.x + size.x / 2 << std::endl;
      // std::cout << "coliso X ?" << ' ' << dist_x * (x + static_cast<float>(width) / 2 > position.x + size.x / 2 ? 1 : -1) << std::endl;
      // x += dist_x * (x + static_cast<float>(width) / 2 > position.x + size.x / 2 ? 1 : -1);
      adjusts.x += dist_x * (x + static_cast<float>(width) / 2 > position.x + size.x / 2 ? 1 : -1);
      // vx = -vx;
    } else {
      // acho que colisão em Y
      // std::cout << "coliso Y ?" << std::endl;
      // std::cout << "coliso Y ?" << ' ' << dist_y * (y + static_cast<float>(height) / 2 > position.y + size.y / 2 ? 1 : -1) << std::endl;
      // y += dist_y * (y + static_cast<float>(height) / 2 > position.y + size.y / 2 ? 1 : -1);
      adjusts.y += dist_y * (y + static_cast<float>(height) / 2 > position.y + size.y / 2 ? 1 : -1);
      // vy = -vy;
    } // funfo
    std::cout << "collided eith " << Id << std::endl;

    // for (int i = 0; i < 4; ++i) {
    //   pressed[i] = false;
    // }
  }

  void TheUndying::adjust() {
    x += adjusts.x;
    y += adjusts.y;
    adjusts = VectorF(0, 0);
  }

  std::string TheUndying::getID() const {
    return id;
  }
}

