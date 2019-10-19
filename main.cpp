#include "FISW/Drawable.hpp"
#include "FISW/Game.hpp"

int main() {

  FISW::Game game = FISW::Game(800.0f, 600.0f, "dia 2", FISW::WindowStyle::Default,
    {
      new FISW::Drawable("bloodboi.png", 100.0f, 100.0f, 256.0f, 256.0f),
    } 
  );

  int ret = game.run(); 


  return ret;
}
