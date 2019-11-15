#include "Bullet.hpp"
#include <iostream>

namespace DIM {
  Bullet::Bullet() : Projectile() {
    id = std::string("Bullet");
  }

  Bullet::~Bullet() {

  }

  void Bullet::update(float elapsedTime) {
    x += speed_x * elapsedTime;
    y += speed_y * elapsedTime;
  }

  void Bullet::draw() const {
    if (graphics_manager != nullptr) {
      graphics_manager->draw("assets/Bullet.png", VectorF(x, y));
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void Bullet::initializeSpecific() {
    graphics_manager->loadAsset("assets/Bullet.png");
    VectorF size = graphics_manager->getSizeOfAsset("assets/Bullet.png");
    width = size.x;
    height = size.y;
  }

  void Bullet::collided(std::string other_id, VectorF position, VectorF size) {
    // he's dead
    y -= 2000;
  }

  void Bullet::adjust() {

  }

  std::string Bullet::getID() const {
    return id;
  }
}