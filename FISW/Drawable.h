#ifndef DRAWABLE_H
#define DRAWABLE_H


#include <SFML/Graphics.hpp>
#include <list>
#include <map>

namespace FISW {

  class Drawable {
  protected:
    const char* path;
    float x;
    float y;
    sf::Texture *texture;
    
  public:
    Drawable(const char* Path, float X, float Y);
    virtual ~Drawable();
    virtual std::list<const char*> getAssetPathList() const;
    virtual int init(std::map<std::string, sf::Texture*> assets);
    virtual void update();
    virtual void draw(sf::RenderWindow *window);

  };
}

#endif 