#ifndef THREADEDCASTER_HPP
#define THREADEDCASTER_HPP

#include "../Entities/Enemies/Caster.hpp"
#include "Thread.hpp"

namespace DIM {
  namespace Concurrent {

    class ThreadedCaster : public Thread, public Entities::Mobs::Caster {
    private:
      bool keep_going;
      bool paused;
      void run();
    public:
      ThreadedCaster(Utils::VectorF pos);
      ~ThreadedCaster();

      void stopRunning();
      void setPaused(bool pause);
    };

  }
}

#endif