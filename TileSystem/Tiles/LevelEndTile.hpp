#ifndef LEVELENDTILE_HPP
#define LEVELENDTILE_HPP

#include "Tile.hpp"

namespace DIM {
  class LevelEndTile : public Tile {
  private:

  public:
    LevelEndTile();
    virtual ~LevelEndTile();
    
    //Quem notifica o jogo?
    //void collided(std::string id, VectorF positionOther, VectorU positionMine) override;
  };

}

#endif