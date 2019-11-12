#ifndef TEMPLELEVEL_HPP
#define TEMPLELEVEL_HPP

#include "Level.hpp"

namespace DIM {
  class TempleLevel : public Level {
  private:

  public:
    TempleLevel();
    ~TempleLevel();

    void init(GraphicsManager* g) override;

    void exec() override;
  };

}

#endif