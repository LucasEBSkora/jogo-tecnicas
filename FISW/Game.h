#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include <iostream>
#include <list>

#include <SFML/Graphics.hpp>

#include "Element.h"
#include "EventHandler.h"
#include "EventHandlerSettings.h"
#include "EventReport.h"

namespace FISW {

  class Game {
    protected:

      //Lista de elementos que são "filhos" diretos do jogo
      std::vector<FISW::Element*> elements;
      //Lista de todas as texturas que o jogo usará (precisa ser expandida para permitir sons e tilemaps tbm)
      std::map<std::string, sf::Texture*> assets;
      //qual dos elementos está sendo carregado no momento (essa classe só permite um de cada vez)
      long unsigned int currentElement;
      //Se o jogo deve ser fechado
      bool closeGame;
      //Janela do SFML onde tudo será desenhado
      sf::RenderWindow* window;

      FISW::EventHandler eventHandler;

      //carrega todos os assets, inicializa o gerenciador de eventos      
      int init();
      //chama o gerenciador de eventos (precisa ser completamente refeita)
      void processEvents();
    
    public:
      Game(float width, float height, std::string windowTitle, unsigned int style, std::vector<Element*> Elements);
      ~Game();
      int run();
      
  };
}

#endif