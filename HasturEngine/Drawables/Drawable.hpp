#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <set>
#include <map>

#include "../Events/EventListeners.hpp"
#include "../Asset.hpp"
namespace HE {

// Classe base da qual todos os elementos gráficos tem de ser derivados

class Drawable {

protected:
  EventListeners* listeners;

public:
  virtual ~Drawable();

  // Retorna a lista de caminhos para os assets que esse elemento precisa. Pode retornar uma lista vazia, ou
  // simplesmente retornar a lista dos elementos agregados
  virtual std::set<const char*> getAssetPathList() const = 0;

  // Armazena os ponteiros para os assets necessários. Retorna se houve sucesso em encontrar todos os assets.
  virtual int init(std::map<std::string, Asset> assets, EventListeners* l) = 0;
  // Retorna a quais eventos o elemento se inscreverá

  // Seria a função que atualizaria as coisas, mas dependendo do modelo de tratamento de eventos pode se tornar
  // desnecessária (o desejado)
  virtual void update(float) = 0;

  // Desenha o elemento na tela. Pode simplesmente chamar a mesma função nos elementos agregados.
  virtual void draw(sf::RenderWindow* window) = 0;
};
} // namespace HE

#endif