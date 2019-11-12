#ifndef SPIKEOBSTACLE_HPP
#define SPIKEOBSTACLE_HPP

#include "Tile.hpp"

namespace DIM {
  class SpikeObstacle : public Tile {
  private:

  public:
    SpikeObstacle(const char* Path = "");
    virtual ~SpikeObstacle();
  };

}

#endif