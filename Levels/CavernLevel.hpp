#ifndef CAVERNLEVEL_HPP
#define CAVERNLEVEL_HPP

#include "Level.hpp"

namespace DIM {
  namespace Levels {

    class CavernLevel : public Level {
    private:
      int key_event_id;
    public:
      CavernLevel();
      ~CavernLevel();
      void init(Managers::GraphicsManager& g, Managers::EventManager& e) override;
      void playFromStart() override;
    };

  }
}

#endif