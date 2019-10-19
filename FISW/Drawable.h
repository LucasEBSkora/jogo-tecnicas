#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <list>
#include <map>

#include <SFML/Graphics.hpp>

#include "Element.h"
#include "EventListeners.h"

//Simplest possible element, only prints an static image

namespace FISW {

class Drawable : public Element {
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
  Drawable(const char* Path, float X, float Y, float Length, float Height);
  virtual ~Drawable() override;

  virtual std::list<const char*> getAssetPathList() const override;
  virtual int init(std::map<std::string, sf::Texture*> assets) override;
  virtual EventListeners getSettings() override;
  virtual void update(float) override;
  virtual void draw(sf::RenderWindow* window) override;
};
} // namespace FISW

#endif