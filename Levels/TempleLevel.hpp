#ifndef TEMPLELEVEL_HPP
#define TEMPLELEVEL_HPP

#include "Level.hpp"

namespace DIM {
  class TempleLevel : public Level {

  private:
    bool keep_going;
    int key_event_id;
  public:
    TempleLevel(Mob* p1 = nullptr, Mob* p2 = nullptr);
    ~TempleLevel();

    void init(GraphicsManager& g, EventManager& e) override;

    void exec() override;
  };

}

#endif