#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../Entities/Entity.hpp"

namespace DIM {
  class Button : public Entity {
  private:
    int width;
    int height;
  public:
    Button(int cx = 0, int cy = 0, int w = 10, int h = 10);
    ~Button();

    void update(float elapsedTime) override;
    void draw() const override;
    void initializeSpecific() override;
  };

}

#endif