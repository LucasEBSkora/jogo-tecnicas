#include "FISW/Drawable.hpp"
#include "FISW/Game.hpp"
#include "FISW/Animatable.hpp"

int main() {

  FISW::Game game = FISW::Game(800.0f, 600.0f, "dia 2", FISW::WindowStyle::Default,
    {
      new FISW::Drawable("bloodboi.png", 100.0f, 100.0f, 256.0f, 256.0f),
      new FISW::Animatable("walk2.png", sf::Vector2f(200.0f, 200.0f), sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(0,0)), sf::Vector2f(64.0f,64.0f), {
        FISW::LambdaPair("timer_300", [this]() {//aqui que morre o sonho kk

          }
        )
      })
    }
  );

  int ret = game.run(); 


  return ret;
}
