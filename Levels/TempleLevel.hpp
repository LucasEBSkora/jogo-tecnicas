#ifndef TEMPLELEVEL_HPP
#define TEMPLELEVEL_HPP

#include "Level.hpp"

namespace DIM {
  class TempleLevel : public Level {

  private:
    
    int key_event_id;
  public:
    TempleLevel();
    ~TempleLevel();

    void init(GraphicsManager& g, EventManager& e) override;
  };

}

#endif