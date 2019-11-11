#ifndef THEUNDYING_HPP
#define THEUNDYING_HPP

#include "../Mob.hpp"

namespace DIM {
  //Player 1
  class TheUndying : public Mob {
  private:

  public:
    TheUndying();
    ~TheUndying();
    
    void subscribe() override;

    
    void onKeyboardEvent(sf::Event* e);
    
    void animate();
  
  };
}

#endif