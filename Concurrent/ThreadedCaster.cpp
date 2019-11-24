#include "ThreadedCaster.hpp"
#include <iostream>
#include <chrono>

namespace DIM {
  namespace Concurrent {

    void ThreadedCaster::run() {
      keep_going = true;
      while (keep_going) {
        if (!paused) {
          lock();
          delay = 0; // sempre que chega aqui atira
          update(0.0f); // não sai do lugar mas atira

          // espera por 1 segundo antes de soltar o mutex
          std::chrono::duration<double> wait_for = std::chrono::milliseconds(1000);
          auto wait_start = std::chrono::steady_clock::now();
          while (wait_for > std::chrono::milliseconds(0)) {
            // se estiver pausado o tempo não passa
            if (!paused && keep_going) {
              wait_for -= std::chrono::steady_clock::now() - wait_start;
            }
            wait_start = std::chrono::steady_clock::now();
            yield();
          }
          unlock();

          // espera por mais 100 ms para que dê tempo de algum outro pegar o mutex
          wait_for = std::chrono::milliseconds(100);
          wait_start = std::chrono::steady_clock::now();
          while (wait_for > std::chrono::milliseconds(0)) {
            if (!paused && keep_going) {
              wait_for -= std::chrono::steady_clock::now() - wait_start;
            }
            wait_start = std::chrono::steady_clock::now();
            yield();
          }

        } else {
          // quando estiver pausado minimiza o uso do processador
          yield();
        }
      }
    }

    ThreadedCaster::ThreadedCaster(Utils::VectorF pos) : keep_going{true}, paused{false} {
      position = pos;
    }

    ThreadedCaster::~ThreadedCaster() {
        
    }

    void ThreadedCaster::stopRunning() {
      keep_going = false;
    }

    void ThreadedCaster::setPaused(bool pause) {
      paused = pause;
    }

  }
}