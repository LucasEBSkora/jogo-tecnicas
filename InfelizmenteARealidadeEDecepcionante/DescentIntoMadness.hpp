#ifndef DESCENTINTOMADNESS_HPP
#define DESCENTINTOMADNESS_HPP

#include "GraphicsManager.hpp"
#include "Menus/MainMenu.hpp"
#include "Levels/TempleLevel.hpp"
#include "Levels/CavernLevel.hpp"

namespace DIM {
  
  class DescentIntoMadness {
  private:
    GraphicsManager graphics_man;

    MainMenu menu;

    TempleLevel temple;
    CavernLevel cavern;

    void play();
  public:
    DescentIntoMadness();
    ~DescentIntoMadness();
  };
  
}

#endif