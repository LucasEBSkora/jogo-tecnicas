#include "FISW/Drawable.hpp"
#include "FISW/Game.hpp"
#include "FISW/Animatable.hpp"

int main() {

  FISW::Game game = FISW::Game(800.0f, 600.0f, "dia 2", FISW::WindowStyle::Default,
    {
      new FISW::Drawable("bloodboi.png", 100.0f, 100.0f, 256.0f, 256.0f),
      new FISW::Animatable("walk2.png", sf::Vector2f(200.0f, 200.0f), sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(32,32)), sf::Vector2f(128.0f,128.0f))
    }
  );

  int ret = game.run(); 


  return ret;
}
