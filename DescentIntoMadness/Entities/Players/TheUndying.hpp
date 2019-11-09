#ifndef THEUNDYING_HPP
#define THEUNDYING_HPP

#include "HasturEngine/Entity.hpp"
#include "HasturEngine/EntityDrawable.hpp"
#include "HasturEngine/EventListeners.hpp"

//Player 1
class TheUndying : public HE::Entity {

  private:

  public:
  TheUndying();
  ~TheUndying();
  
  HE::EntityDrawable* generateEntityDrawable() const override;
  void subscribe() override;

  
  void onKeyboardEvent(sf::Event* e);
  
  void animate();
  
};

#endif