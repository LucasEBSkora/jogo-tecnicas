#ifndef LEVELMEMENTO_HPP
#define LEVELMEMENTO_HPP

#include "Memento.hpp"
#include <vector>

namespace DIM
{
  class LevelMemento : Memento {
  private:
    std::vector<Memento*> mementos;
    LevelMemento();
  public:
    ~LevelMemento();

    void saveToFile(std::ostream& file) override;
    friend class TempleLevel;
    friend class CavernLevel;
  };

} // namespace DIM

#endif