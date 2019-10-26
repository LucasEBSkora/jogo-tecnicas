#ifndef MODELDRAWER_HPP
#define MODELDRAWER_HPP

#include <map>

#include <SFML/Graphics.hpp>

#include "Animatable.hpp"
#include "Model.hpp"

namespace FISW {

  class ModelDrawer : public Element {
    protected:
      // path to the desired image
      const char* path;
      sf::IntRect texturePosition;
      sf::Vector2f size;
      // pointer to the desired image
      sf::Texture* texture;
      sf::RectangleShape box;
      Model* model;

    public:

      ModelDrawer(const char* Path, sf::Vector2f Size, Model* model);
      virtual ~ModelDrawer() override;

      virtual std::list<const char*> getAssetPathList() const override;
      virtual int init(std::map<std::string, sf::Texture*> assets, EventListeners* l) override;
      virtual void update(float) override;
      virtual void draw(sf::RenderWindow* window) override;

  };

}

#endif