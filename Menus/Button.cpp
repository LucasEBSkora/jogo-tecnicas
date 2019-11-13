#include "Button.hpp"
#include <iostream>

namespace DIM {

  Button::Button(int cx, int cy, int w, int h) {
    x = cx - w / 2;
    y = cy - h / 2;
    width = w;
    height = h;
  }
  
  Button::~Button() {

  }

  void Button::update(float elapsedTime) {
    
  }

  void Button::draw() const {
    if (graphics_manager != nullptr) {
      graphics_manager->drawRect(VectorF(x, y), VectorF(width, height), 80, 80, 80);
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void Button::initializeSpecific() {
    
  }

}