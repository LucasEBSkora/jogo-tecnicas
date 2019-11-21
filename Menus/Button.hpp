#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"

namespace DIM {
  namespace Menus {
      
    class Button {
    private:
      Utility::VectorF position;
      float width;
      float height;
      int my_id;
      std::string text;
      Managers::GraphicsManager* graphics_manager;
      Managers::EventManager* event_man;

    public:
      Button(Utility::VectorF Center = Utility::VectorF(), int w = 10, int h = 10, int id = 0, const std::string& txt = "");
      ~Button();

      void draw() const;
      void initialize(Managers::GraphicsManager& g, Managers::EventManager& e);
      
      bool isInside(Utility::VectorF pos) const;
      int getId() const;
    };

  }
}

#endif