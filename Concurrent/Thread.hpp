#ifndef THREAD_HPP
#define THREAD_HPP

#include <pthread.h>

// Classe thread baseada nos slides encontrados no site do prof. Jean Simão

namespace DIM {
  namespace Concurrent {

    class Thread {
    private:
      pthread_t threadID;
      static pthread_mutex_t mutex;

      static void* runThread(void* pThread);
      virtual void run() = 0;
    public:
      Thread();
      virtual ~Thread();

      void start();
      void join();
      void yield();

      void lock();
      void unlock();
    };

  }
}

#endif