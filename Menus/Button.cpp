#include "Button.hpp"
#include <iostream>
#include "../Levels/Level.hpp"
#include "../Utils/GeometricVector.hpp"

namespace DIM {
  namespace Menus {

    Button::Button(Utils::VectorF center, int w, int h, int id, const std::string& txt) {
      position = center - Utils::VectorF(w, h) * 0.5;
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
        graphics_manager->drawRect(position, Utils::VectorF(width, height), 80, 80, 80);
        graphics_manager->drawTextCentered(text, position + Utils::VectorF(width, height) * 0.5 - Utils::VectorF(1.0f, 3.0f), height*.7);
      } else {
        std::cout << "desenhando objeto nao inicializado\n";
      }
    }

    void Button::initialize(Managers::GraphicsManager& g, Managers::EventManager& e) {
      graphics_manager = &g;
      event_man = &e;
    }
    
    bool Button::isInside(Utils::VectorF pos) const {
      return (position.x <= pos.x && pos.x <= position.x + width &&
              position.y <= pos.y && pos.y <= position.y + height);
    }

    int Button::getId() const {
      return my_id;
    }

  }
}