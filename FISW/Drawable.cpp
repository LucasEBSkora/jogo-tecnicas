#include "Drawable.h"
#include <iostream>

namespace FISW {

  Drawable::Drawable(const char* Path, float X, float Y, float Length, float Height) : 
    path{Path}, x{X}, y{Y}, length{Length}, height{Height}, texture{nullptr}, box{sf::Vector2f(Length, Height)} {
    
    box.setPosition(X, Y);

  }

  Drawable::~Drawable() {

  }

  //returns a list containing only the texture 
  std::list<const char*> Drawable::getAssetPathList() const {
    std::list<const char*> list;
    list.push_back(path);
    return list;
  }

  //As this class doesn't depend on any events, returns an enpty settings object
  EventHandlerSettings Drawable::getSettings() const {
    return EventHandlerSettings();
  }

  //Finds the asset in the map using the path as a key, returns 1 if it isn't able to
  int Drawable::init(std::map<std::string, sf::Texture*> assets) {

    if (assets.find(path) == assets.end())  {
      std::cout << "error! asset " << path << "could not be initialized properly!\n";
      return 1;
    }

    texture = assets[path];
    
    box.setTexture(texture, true);


    return 0;
  }

  void Drawable::update() {

  }

  
  void Drawable::draw(sf::RenderWindow *window) {
    
    window->draw(box);

  }

}