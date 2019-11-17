#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"

namespace DIM {
  class Button {
  private:
    VectorF position;
    float width;
    float height;
    int my_id;
    std::string text;
    GraphicsManager* graphics_manager;
    EventManager* event_man;

  public:
    Button(VectorF Center = VectorF(), int w = 10, int h = 10, int id = 0, const std::string& txt = "");
    ~Button();

    void draw() const;
    void initialize(GraphicsManager& g, EventManager& e);
    
    bool isInside(VectorF pos) const;
    int getId() const;
  };

}

#endif