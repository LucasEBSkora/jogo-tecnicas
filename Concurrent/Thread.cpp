#include "Thread.hpp"

#include <iostream>

namespace DIM {
  namespace Concurrent {

    pthread_mutex_t Thread::mutex = PTHREAD_MUTEX_INITIALIZER;

    Thread::Thread() {
      
    }

    Thread::~Thread() {

    }
    
    void* Thread::runThread(void* pThread) {
      Thread* thread = static_cast<Thread*>(pThread);

      if (thread != nullptr) {
        thread->run();
      } else {
        std::cout << "thread inexistente" << std::endl;
      }
      
      return nullptr;
    }
    
    void Thread::start() {
      pthread_create(&threadID, nullptr, runThread, static_cast<void*>(this));
    }

    void Thread::join() {
      pthread_join(threadID, nullptr);
    }

    void Thread::yield() {
      sched_yield();
    }

    void Thread::lock() {
      pthread_mutex_lock(&mutex);
    }
    
    void Thread::unlock() {
      pthread_mutex_unlock(&mutex);
    }

  }
}