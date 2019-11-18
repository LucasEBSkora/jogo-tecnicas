#ifndef CAVERNLEVEL_HPP
#define CAVERNLEVEL_HPP

#include "Level.hpp"

namespace DIM {
  class CavernLevel : public Level {
  private:
    int key_event_id;
  public:
    CavernLevel();
    ~CavernLevel();
    void init(GraphicsManager& g, EventManager& e) override;
    void playFromStart() override;
  };

}

#endif