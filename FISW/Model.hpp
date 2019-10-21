#ifndef MODEL_H
#define MODEL_H


#include<SFML/Graphics.hpp>

namespace FISW {


  //class that represents a model that must be kept updated even if it isn't on the screen, such as enemies or the player itself
  //basically a way to decouple characters and their appearance on the screen
  class Model {

  protected:
    sf::Vector2f position;
    sf::Vector2i texturePosition;
    const char* path;
    bool facingRight;

  public:
    
    virtual ~Model();
    const sf::Vector2f getPosition() const;
    const sf::Vector2i getTexturePosition() const;
    const char* getAssetPath() const;
    bool isFacingRight() const;
  };
  

}

#endif