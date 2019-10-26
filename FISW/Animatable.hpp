#ifndef ANIMATABLE_HPP
#define ANIMATABLE_HPP

#include <map>
#include <set>

#include <SFML/Graphics.hpp>

#include "Element.hpp"
#include "Asset.hpp"

namespace FISW {

  class Animatable : public Element {
    protected:
      // path to the desired image
      const char* path;
      sf::Vector2f position;
      sf::Vector2f size;
      sf::IntRect texturePosition;
      // pointer to the desired image
      sf::Texture* texture;

      sf::RectangleShape box;

    public:

      Animatable(const char* Path, sf::Vector2f initialPosition, sf::IntRect initialTexturePosition, sf::Vector2f Size);
      virtual ~Animatable() override;

      virtual std::set<const char*> getAssetPathList() const override;
      virtual int init(std::map<std::string, Asset> assets, EventListeners* l) override;
      virtual void update(float) override;
      virtual void draw(sf::RenderWindow* window) override;

  };

}

#endif