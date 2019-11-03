#ifndef MODELDRAWER_HPP
#define MODELDRAWER_HPP

#include <map>

#include <SFML/Graphics.hpp>

#include "Drawable.hpp"


namespace HE {

  class Entity;

  class EntityDrawable : public Drawable {
    private:
      // path to the desired image

      const char* path;
      sf::Vector2f size;
      sf::Vector2i frames;
      
      const Entity* entity;
      
      sf::RectangleShape box;
      
      sf::IntRect texturePosition;
      
      // pointer to the desired image
      sf::Texture* texture;
      

    const sf::IntRect getTexturePosition() const;
    
    public:

      EntityDrawable(const char* Path, sf::Vector2f Size, const Entity* Entity, sf::Vector2i numberFrames);
      virtual ~EntityDrawable() override;
      virtual std::set<const char*> getAssetPathList() const override;
      virtual int init(std::map<std::string, Asset> assets, EventListeners* l) override;
      virtual void update(float) override;
      virtual void draw(sf::RenderWindow* window) override;

    
  };

}

#endif