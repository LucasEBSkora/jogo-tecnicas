#include "Enemy.hpp"

#include <iostream>

#include "../../Levels/Level.hpp"

namespace DIM {

  Enemy::Enemy(const std::string path) : path{path} {
    
  }

  Enemy::~Enemy() {

  }

  void Enemy::draw() const {
    if (currentLevel != nullptr) {
      currentLevel->getGraphicsManager()->draw(path, position);
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void Enemy::initializeSpecific() {
    currentLevel->getGraphicsManager()->loadAsset(path);
    VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset(path);
    width = size.x;
    height = size.y;
  }
}