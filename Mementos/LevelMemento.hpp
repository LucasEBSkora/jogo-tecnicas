#ifndef LEVELMEMENTO_HPP
#define LEVELMEMENTO_HPP

#include "Memento.hpp"
#include "TileManagerMemento.hpp"
#include "TheUndyingMemento.hpp"
#include "ThePenitentMemento.hpp"
#include <vector>
#include <utility>
#include <string>

namespace DIM {

  namespace Tile {
    class TileManager;
  }

  namespace Entities {
    class TheUndying;
    class ThePenitent;
  }

  namespace Managers {
    class CollisionManager;
  }

  namespace Levels {
    class Level;
  }
  
  namespace Mementos {

    class LevelMemento : Memento {
    private:
      TileManagerMemento* tileManagerMemento;
      TheUndyingMemento* player1Memento;
      ThePenitentMemento* player2Memento;
      std::vector<std::pair<std::string, Memento*>> otherMementos;
      LevelMemento();
      LevelMemento(Tile::TileManager* const tileManager, Entities::TheUndying* const p1, Entities::ThePenitent* const p2, const Managers::CollisionManager* collisionManager);

      TileManagerMemento getTileManagerMemento() const;
      TheUndyingMemento getPlayer1Memento() const;
      ThePenitentMemento getPlayer2Memento() const;
      std::vector<std::pair<std::string, Memento*>> getOtherEntitiesMemento() const;
      bool savedPlayer2() const;
    public:
      ~LevelMemento();

      void saveToFile(std::ostream& file) override;
      static LevelMemento loadFromFile(std::istream& file);

      friend class Levels::Level;
    };

  }
}

#endif