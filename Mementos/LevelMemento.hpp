#ifndef LEVELMEMENTO_HPP
#define LEVELMEMENTO_HPP

#include "Memento.hpp"
#include "TileManagerMemento.hpp"
#include "TheUndyingMemento.hpp"
#include "ThePenitentMemento.hpp"
#include <vector>
#include <utility>
#include <string>

namespace DIM
{
  class TileManager;
  class TheUndying;
  class ThePenitent;
  class CollisionManager;

  class LevelMemento : Memento {
  private:
    TileManagerMemento* tileManagerMemento;
    TheUndyingMemento* player1Memento;
    ThePenitentMemento* player2Memento;
    std::vector<std::pair<std::string, Memento*>> otherMementos;
    LevelMemento();
    LevelMemento(TileManager* const tileManager, TheUndying* const p1, ThePenitent* const p2, const CollisionManager* collisionManager);

    TileManagerMemento getTileManagerMemento() const;
    TheUndyingMemento getPlayer1Memento() const;
    ThePenitentMemento getPlayer2Memento() const;
    std::vector<std::pair<std::string, Memento*>> getOtherEntitiesMemento() const;
    bool savedPlayer2() const;
  public:
    ~LevelMemento();

    void saveToFile(std::ostream& file) override;
    static LevelMemento loadFromFile(std::istream& file);

    friend class Level;
    // friend class TempleLevel;
    // friend class CavernLevel;
  };

} // namespace DIM

#endif