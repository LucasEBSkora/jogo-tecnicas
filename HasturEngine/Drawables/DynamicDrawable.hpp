#ifndef DYNAMICDRAWABLE_HPP
#define DYNAMICDRAWABLE_HPP

#include <map>
#include <set>

#include <SFML/Graphics.hpp>

#include "Drawable.hpp"
#include "../Asset.hpp"


namespace HE {

  class DynamicDrawable : public Drawable {
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

      DynamicDrawable(const char* Path, sf::Vector2f initialPosition, sf::IntRect initialTexturePosition, sf::Vector2f Size);
      virtual ~DynamicDrawable() override;

      virtual std::set<const char*> getAssetPathList() const override;
      virtual int init(std::map<std::string, Asset> assets, EventListeners* l) override;
      virtual void update(float) override;
      virtual void draw(sf::RenderWindow* window) override;

  };

}

#endif