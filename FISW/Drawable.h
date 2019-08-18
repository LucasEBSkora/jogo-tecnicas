#ifndef DRAWABLE_H
#define DRAWABLE_H


#include <SFML/Graphics.hpp>
#include <list>
#include <map>

namespace FISW {

  class Drawable {
  private:
    const char* path;
    float x;
    float y;
    sf::Texture *texture;

  public:
    Drawable(const char* Path, float X, float Y);
    ~Drawable();
    virtual std::list<const char*> getAssetPathList();
    virtual int init(std::map<const char*, sf::Texture*> *assets);
    virtual void update();
    virtual void draw(sf::RenderWindow *window);

  };
}

#endif 