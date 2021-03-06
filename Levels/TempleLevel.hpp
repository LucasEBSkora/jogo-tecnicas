#ifndef TEMPLELEVEL_HPP
#define TEMPLELEVEL_HPP

#include "Level.hpp"

namespace DIM {
  namespace Levels {

    class TempleLevel : public Level {
    private:
      
      int key_event_id;
    public:
      TempleLevel();
      ~TempleLevel();

      void init(Managers::GraphicsManager& g, Managers::EventManager& e) override;
    };

  }
}

#endif