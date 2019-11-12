#include "TheUndying.hpp"
#include <iostream>

namespace DIM {
  TheUndying::TheUndying() : Mob()  {
  
  }

  TheUndying::~TheUndying() {

  }

  void TheUndying::update(float elapsedTime) {
    
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
  }
}

