#ifndef EXTRALEVEL_HPP
#define EXTRALEVEL_HPP

#include "../Levels/Level.hpp"
#include "ThreadedCaster.hpp"

namespace DIM {
  namespace Concurrent {

    class ExtraLevel : public Levels::Level {
    private:
      int key_event_id;
      std::vector<ThreadedCaster*> casters;
    public:
      ExtraLevel();
      ~ExtraLevel();
      void init(Managers::GraphicsManager& g, Managers::EventManager& e) override;
      void playFromStart() override;
      int exec() override;
    };

  }
}

#endif