#ifndef MODELDRAWER_HPP
#define MODELDRAWER_HPP

#include <map>

#include <SFML/Graphics.hpp>

#include "Animatable.hpp"


namespace FISW {

  class Model;

  class ModelDrawer : public Element {
    private:
      // path to the desired image

      const char* path;
      sf::Vector2f size;
      sf::Vector2i frames;
      
      const Model* model;
      
      sf::RectangleShape box;
      
      sf::IntRect texturePosition;
      
      // pointer to the desired image
      sf::Texture* texture;
      

    const sf::IntRect getTexturePosition() const;
    
    public:

      ModelDrawer(const char* Path, sf::Vector2f Size, const Model* model, sf::Vector2i numberFrames);
      virtual ~ModelDrawer() override;

      virtual std::list<const char*> getAssetPathList() const override;
      virtual int init(std::map<std::string, sf::Texture*> assets, EventListeners* l) override;
      virtual void update(float) override;
      virtual void draw(sf::RenderWindow* window) override;

    
  };

}

#endif