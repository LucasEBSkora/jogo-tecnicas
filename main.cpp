#include "HasturEngine/StaticDrawable.hpp"
#include "HasturEngine/Game.hpp"
#include "HasturEngine/DynamicDrawable.hpp"
#include "TheUndying.hpp"

int main() {

  HE::Game game = HE::Game(800.0f, 600.0f, "dia 2", HE::WindowStyle::Default,
    {
      new HE::StaticDrawable("assets/bloodboi.png", 100.0f, 100.0f, 256.0f, 256.0f),
      new HE::DynamicDrawable("assets/walk2.png", sf::Vector2f(200.0f, 200.0f), sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(32,32)), sf::Vector2f(128.0f,128.0f))
    }, 
    {
      new TheUndying()
    }
  );

  int ret = game.run(); 


  return ret;
}
