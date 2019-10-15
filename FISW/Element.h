#ifndef ELEMENT_H
#define ELEMENT_H

#include <list>
#include <map>

#include "EventHandlerSettings.h"

namespace FISW {

// Classe base da qual todos os elementos tem que ser derivadas (sejam desenhados ou não)

class Element {

public:
  virtual ~Element();

  // Retorna a lista de caminhos para os assets que esse elemento precisa. Pode retornar uma lista vazia, ou
  // simplesmente retornar a lista dos elementos agregados
  virtual std::list<const char*> getAssetPathList() const = 0;

  // Armazena os ponteiros para os assets necessários. Retorna se houve sucesso em encontrar todos os assets.
  virtual int init(std::map<std::string, sf::Texture*> assets) = 0;
  // Retorna a quais eventos o elemento se inscreverá
  // Não é const para que seja possível inscrever funções não const
  virtual EventHandlerSettings getSettings() = 0;

  // Seria a função que atualizaria as coisas, mas dependendo do modelo de tratamento de eventos pode se tornar
  // desnecessária (o desejado)
  virtual void update(float) = 0;

  // Desenha o elemento na tela. Pode simplesmente chamar a mesma função nos elementos agregados.
  virtual void draw(sf::RenderWindow* window) = 0;
};
} // namespace FISW

#endif