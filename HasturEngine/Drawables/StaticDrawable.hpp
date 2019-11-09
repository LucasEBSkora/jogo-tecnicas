#ifndef STATICDRAWABLE_HPP
#define STATICDRAWABLE_HPP

#include <set>
#include <map>

#include <SFML/Graphics.hpp>

#include "Drawable.hpp"


//Simplest possible element, only prints an static image

namespace HE {

class StaticDrawable : public Drawable {
protected:
  // path to the desired image
  const char* path;
  float x;
  float y;
  float length;
  float height;

  // pointer to the desired image
  sf::Texture* texture;

  sf::RectangleShape box;

public:
  StaticDrawable(const char* Path, float X, float Y, float Length, float Height);
  virtual ~StaticDrawable() override;

  virtual std::set<const char*> getAssetPathList() const override;
  virtual int init(std::map<std::string, Asset> assets, EventListeners* l) override;
  virtual void update(float) override;
  virtual void draw(sf::RenderWindow* window) override;
};
} // namespace HE

#endif