#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP

#include <utility> // std::pair
#include <map>
#include <SFML/Graphics.hpp>
#include "Vector.hpp"

namespace DIM {

  class GraphicsManager {
  
  private:
    static int next_uid;
    std::map<const char*, std::pair<sf::Texture*, int>> assets;
    sf::RenderWindow* window;
    VectorF camera_pos;
    VectorF camera_size;

    bool outOfSight(VectorF at, VectorF size) const;

  public:
    GraphicsManager();
    ~GraphicsManager();
    int loadAsset(const char* path);
    void draw(int id, VectorF at) const;
    void centerCamera(VectorF at);
    
      //Sim, eu coloquei o parâmetro antes de pensar nisso

      // acho que o gerenciador gráfico não precisa de verdade das entidades,
      // se ele tiver uma função drawAsset(int id, int x, int y) que recebe o
      // identificador do asset que foi carregado e a posição que vai desenhar
      // blz

      // pra mexer a câmera também seria por posição (tudo coordenadas do mundo,
      // que ele saberia transformar pra tela)
  };

}

#endif // GRAPHICSMANAGER_HPP