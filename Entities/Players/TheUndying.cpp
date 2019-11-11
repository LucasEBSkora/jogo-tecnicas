#include "TheUndying.hpp"

namespace DIM {
  TheUndying::TheUndying() : Mob()  {
  
  }

  TheUndying::~TheUndying() {

  }

  void TheUndying::subscribe() {
    
  }


  void TheUndying::animate() {
    texturePosition.x = (texturePosition.x + 1) % 9; //numero de frames
  }

}

