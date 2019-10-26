#ifndef THEUNDYING_HPP
#define THEUNDYING_HPP

#include "FISW/Model.hpp"
#include "FISW/ModelDrawer.hpp"
#include "FISW/EventListeners.hpp"

//Player 1
class TheUndying : public FISW::Model {

  private:

  public:
  TheUndying();
  ~TheUndying();
  
  FISW::ModelDrawer* generateModelDrawer() const override;
  void subscribe() override;

  
  void onKeyboardEvent(sf::Event* e);
  
  void animate();
  
};

#endif