#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <list>
#include <map>

#include <SFML/Graphics.hpp>

#include "EventHandlerSettings.h"
#include "Element.h"


//Elemento mais básico possível, que simplesmente coloca uma imagem estática na tela.

namespace FISW {

  class Drawable : public Element {
  protected:

    //caminho para a imagem usada
    const char* path;
    float x;
    float y;
    float length;
    float height;
    
    //ponteiro para a imagem usada
    sf::Texture *texture;

    //"Caixa" onde a imagem será desenhada
    sf::RectangleShape box;
    
  public:
    Drawable(const char* Path, float X, float Y, float Length, float Height);
    virtual ~Drawable() override;


    virtual std::list<const char*> getAssetPathList() const override;
    virtual int init(std::map<std::string, sf::Texture*> assets) override;
    virtual EventHandlerSettings getSettings() const override;
    virtual void update() override;
    virtual void draw(sf::RenderWindow *window) override;

  };
}

#endif 