#ifndef ENTITY_HPP
#define ENTITY_HPP


#include <SFML/Graphics.hpp>

#include "Drawables/EntityDrawable.hpp"
#include "Events/EventListeners.hpp"

namespace HE {


  //class that represents a model that must be kept updated even if it isn't on the screen, such as enemies or the player itself
  //basically a way to decouple characters and their appearance on the screen
  class Entity {

  protected:
  
    const char* path;
    sf::Vector2f position;
    sf::Vector2i texturePosition;
    bool facingRight;
    EventListeners* listener;

    virtual void subscribe() = 0;


  public: 

    Entity(const char* Path = "", sf::Vector2f Position = sf::Vector2f(0.0f, 0.0f), sf::Vector2i TexturePosition = sf::Vector2i(0,0), bool FacingRight = true);

    
    virtual ~Entity();

    const sf::Vector2f getPosition() const;
    const sf::Vector2i getTexturePosition() const;
    const char* getAssetPath() const;
    bool isFacingRight() const;

    virtual EntityDrawable* generateEntityDrawable() const = 0;
    void init(EventListeners* l);


  };
  
}

#endif