#ifndef THEMIRROROFHASTURMEMENTO_HPP
#define THEMIRROROFHASTURMEMENTO_HPP

#include "Memento.hpp"
#include "../Vector.hpp"

namespace DIM
{
  class TheMirrorOfHasturMemento : public Memento {
  private:
    TheMirrorOfHasturMemento(VectorF pos = VectorF(0, 0), VectorF vel = VectorF(0, 0), float dly = 0, float max_vx = 0, float max_vy = 0, bool jmp = false);

    VectorF position;
    VectorF velocity;
    float delay;
    float max_speed_x;
    float max_speed_y;
    bool jumping;

    VectorF getPosition() const;
    VectorF getVelocity() const;
    float getDelay() const;
    float getMaxSpeedX() const;
    float getMaxSpeedY() const;
    bool getJumping() const;

  public:
    TheMirrorOfHasturMemento(const TheMirrorOfHasturMemento&) = default;
    ~TheMirrorOfHasturMemento();

    void saveToFile(std::ostream& file) override;
    static TheMirrorOfHasturMemento loadFromFile(std::istream& file);

    // friend class TheMirrorOfHastur;
  };
  
} // namespace DIM

#endif