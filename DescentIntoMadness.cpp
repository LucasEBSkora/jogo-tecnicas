#include "DescentIntoMadness.hpp"

namespace DIM {

  DescentIntoMadness::DescentIntoMadness() :
    graphics_man(), menu(), temple(), cavern() {
    menu.initializeGeneric(&graphics_man);
    temple.initializeGeneric(&graphics_man);
    cavern.initializeGeneric(&graphics_man);
    play();
  }

  DescentIntoMadness::~DescentIntoMadness() {

  }

  void DescentIntoMadness::play() {
    bool playing;
    while (playing) {
      // a partir daqui pseudocódigo por enquanto
      int decisao = menu.exec();
      if (decisao == FIM) {
        playing = false;
      } else if (decisao == NOVO_TEMPLE) {
        temple.newgame();
        decisao = temple.exec();
        if (decisao == PROX_FASE) {
          cavern.newgame();
          cavern.exec();
        }
      }
    }
    // arrumar função
    // além disso, não parece mais que Menus e Fases não entidades
    
  }

}