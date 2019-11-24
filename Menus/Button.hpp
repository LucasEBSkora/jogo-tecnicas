#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include "../Managers/GraphicsManager.hpp"
#include "../Managers/EventManager.hpp"

namespace DIM {
  namespace Menus {
      
    class Button {
    private:
      Utils::VectorF position;
      float width;
      float height;
      int my_id;
      std::string text;
      Managers::GraphicsManager* graphics_manager;

    public:
      Button(Utils::VectorF Center = Utils::VectorF(), int w = 10, int h = 10, int id = 0, const std::string& txt = "");
      ~Button();

      void draw() const;
      void initialize(Managers::GraphicsManager& g);
      
      bool isInside(Utils::VectorF pos) const;
      int getId() const;
    };

  }
}

#endif