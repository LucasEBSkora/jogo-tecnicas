#include "Drawable.h"
#include <iostream>

namespace FISW {

  Drawable::Drawable(const char* Path, float X, float Y, float Length, float Height) : 
    path{Path}, x{X}, y{Y}, length{Length}, height{Height}, texture{nullptr}, box{sf::Vector2f(Length, Height)} {
    
    box.setPosition(X, Y);

  }

  Drawable::~Drawable() {

  }

  //retorna uma lista apenas com o próprio caminho
  std::list<const char*> Drawable::getAssetPathList() const {
    std::list<const char*> list;
    list.push_back(path);
    return list;
  }

  //Como ela não depende de nenhum evento, retorna uma lista vazia
  EventHandlerSettings Drawable::getSettings() const {
    return EventHandlerSettings();
  }


  //Encontra o asset dentro do mapa usando o caminho como chave, retorna 1 se não conseguir
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