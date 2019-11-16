#include "Button.hpp"
#include <iostream>

namespace DIM {

  Button::Button(int cx, int cy, int w, int h, int id, const std::string& txt) {
    x = cx - w / 2;
    y = cy - h / 2;
    width = w;
    height = h;
    my_id = id;
    text = txt;
  }
  
  Button::~Button() {

  }

  void Button::update(float elapsedTime) {
    
  }

  void Button::draw() const {
    if (graphics_manager != nullptr) {
      graphics_manager->drawRect(VectorF(x, y), VectorF(width, height), 80, 80, 80);
      graphics_manager->drawTextCentered(text, VectorF(x + width / 2. - 1, y + height / 2. - 3), height*.7);
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void Button::initializeSpecific() {
    
  }
  
  bool Button::isInside(VectorF pos) const {
    std::cout << x << ' ' << y << ' ' << pos.x << ' ' << pos.y << ' ' << width << ' ' << height << std::endl;
    return (x <= pos.x && pos.x <= x + width &&
            y <= pos.y && pos.y <= y + height);
  }

  int Button::getId() const {
    return my_id;
  }

}