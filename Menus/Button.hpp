#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../Entities/Entity.hpp"

namespace DIM {
  class Button : public Entity {
  private:
    int width;
    int height;
    int my_id;
    std::string text;
  public:
    Button(int cx = 0, int cy = 0, int w = 10, int h = 10, int id = 0, const std::string& txt = "");
    ~Button();

    void update(float elapsedTime) override;
    void draw() const override;
    void initializeSpecific() override;
    
    bool isInside(VectorF pos) const;
    int getId() const;
  };

}

#endif