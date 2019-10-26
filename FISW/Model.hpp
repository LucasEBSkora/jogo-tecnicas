#ifndef MODEL_H
#define MODEL_H


#include <SFML/Graphics.hpp>

#include "ModelDrawer.hpp"
#include "EventListeners.hpp"

namespace FISW {


  //class that represents a model that must be kept updated even if it isn't on the screen, such as enemies or the player itself
  //basically a way to decouple characters and their appearance on the screen
  class Model {

  protected:
  
    const char* path;
    sf::Vector2f position;
    sf::Vector2i texturePosition;
    bool facingRight;
    EventListeners* listener;

    virtual void subscribe() = 0;


  public: 

    Model(const char* Path = "", sf::Vector2f Position = sf::Vector2f(0.0f, 0.0f), sf::Vector2i TexturePosition = sf::Vector2i(0,0), bool FacingRight = true);

    
    virtual ~Model();

    const sf::Vector2f getPosition() const;
    const sf::Vector2i getTexturePosition() const;
    const char* getAssetPath() const;
    bool isFacingRight() const;

    virtual ModelDrawer* generateModelDrawer() const = 0;
    void init(EventListeners* l);


  };
  
}

#endif