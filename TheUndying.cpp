#include "TheUndying.hpp"

TheUndying::TheUndying() : Model("assets/walk2.png", {100.0f, 100.0f}, {0, 0}, true)  {
 
}

TheUndying::~TheUndying() {

}

FISW::ModelDrawer* TheUndying::generateModelDrawer() const{

  return new FISW::ModelDrawer(path, {256.0f, 256.0f}, this, {9, 1});

}

void TheUndying::subscribe() {
  listener->subscribe("keyboard", [this](sf::Event* e){onKeyboardEvent(e);}, this);
  
}

void TheUndying::onKeyboardEvent(sf::Event* e) {


  if (e->type == sf::Event::KeyPressed) {
    
    if (e->key.code == FISW::KeyboardKey::A) {
  std::cout << "firing!" << std::endl;
      facingRight = false;
      listener->subscribe("update", [this](float time){ position.x -= 50*time;}, this);
      listener->subscribe("timer_150", [this](){animate();}, this);

    } else if (e->key.code == FISW::KeyboardKey::D) {
      
      facingRight = true;
      listener->subscribe("update", [this](float time){ position.x += 50*time;}, this);
      listener->subscribe("timer_150", [this](){animate();}, this);
    }


  } else if (e->key.code == FISW::KeyboardKey::A  || e->key.code == FISW::KeyboardKey::D) {
  
    listener->unsubscribe("update", this);
    listener->unsubscribe("timer_150", this);
  
  }

}

void TheUndying::animate() {
  texturePosition.x = (texturePosition.x + 1) % 9; //numero de frames
}



