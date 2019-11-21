#include "Button.hpp"
#include <iostream>
#include "../Levels/Level.hpp"
#include "../GeometricVector.hpp"

namespace DIM {

  Button::Button(VectorF center, int w, int h, int id, const std::string& txt) {
    position = center - VectorF(w, h) * 0.5;
    width = w;
    height = h;
    my_id = id;
    text = txt;
    graphics_manager = nullptr;
    event_man = nullptr;
  }
  
  Button::~Button() {

  }

  void Button::draw() const {
    if (graphics_manager != nullptr) {
      graphics_manager->drawRect(position, VectorF(width, height), 80, 80, 80);
      graphics_manager->drawTextCentered(text, position + VectorF(width, height) * 0.5 - VectorF(1.0f, 3.0f), height*.7);
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void Button::initialize(GraphicsManager& g, EventManager& e) {
    graphics_manager = &g;
    event_man = &e;
  }
  
  bool Button::isInside(VectorF pos) const {
    // std::cout << x << ' ' << y << ' ' << pos.x << ' ' << pos.y << ' ' << width << ' ' << height << std::endl;
    return (position.x <= pos.x && pos.x <= position.x + width &&
            position.y <= pos.y && pos.y <= position.y + height);
  }

  int Button::getId() const {
    return my_id;
  }

}