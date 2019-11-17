#include "Caster.hpp"

#include <iostream>

#include "../../Levels/Level.hpp"
#include "../Projectiles/Spell.hpp"
#include "../../RandomValueGenerator.hpp"
namespace DIM {

  const float Caster::spellSpeed{50};  

  Caster::Caster() : Enemy(), delay(4000 + RandomValueGenerator::getInstance()->getRandomIntInRange(200, 1400)) {
    id = std::string("Caster");
    max_speed_x = 20 + RandomValueGenerator::getInstance()->getRandomFloatInRange(-8, 8);
    max_speed_y = 40 + RandomValueGenerator::getInstance()->getRandomFloatInRange(-15, 15);
  }

  Caster::~Caster() {
      
  }

  void Caster::update(float elapsedTime) {

    VectorF player = currentLevel->getPlayer1Center();

    vx = ((player.x < x + width / 2) ? -1 : 1) * max_speed_x;

    
    if (y - player.y > - 80) vy = -max_speed_y;
    else if (y - player.y < -100) vy = max_speed_y;


    if (delay != 0) {
      
      --delay;
    } else {
  
      delay = RandomValueGenerator::getInstance()->getRandomIntInRange(1200, 2800);

      VectorF direction = (player - VectorF(x, y) -  getSize() * (0.5));
  
      if (direction.module() < 300) {
        
        std::cout << "Criando feitico em " << VectorF(x, y) + getSize() * 0.5 << std::endl;
        currentLevel->addPhysicalEntity(new Spell(VectorF(x, y) + getSize() * 0.5, direction.unitVector() * spellSpeed));
      }

    }

    x += (vx * elapsedTime) * RandomValueGenerator::getInstance()->getRandomFloatInRange(0.5, 1.5);
    y += (vy * elapsedTime) * RandomValueGenerator::getInstance()->getRandomFloatInRange(0.5, 1.5);
  }

  void Caster::draw() const {
    if (currentLevel != nullptr) {
      currentLevel->getGraphicsManager()->draw("assets/Caster.png", VectorF(x, y));
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

  void Caster::initializeSpecific() {
    currentLevel->getGraphicsManager()->loadAsset("assets/Caster.png");
    VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset("assets/Caster.png");
    width = size.x;
    height = size.y;
  }

  void Caster::collided(std::string other_id, VectorF position, VectorF size) {

    if (other_id == "Wall" || other_id == "Spawn" || other_id == "Spike") {
      float dist_x = (static_cast<float>(width) + size.x) / 2 - std::abs(x + static_cast<float>(width) / 2 - position.x - size.x / 2);
      float dist_y = (static_cast<float>(height) + size.y) / 2 - std::abs(y + static_cast<float>(height) / 2 - position.y - size.y / 2);
      
      if (dist_x * dist_y > .001 * width * height) { // passa a ignorar colisões ignoráveis (bem as problemáticas)
        if (dist_x < dist_y) {
          // colisão em X
          if (dist_x > std::abs(adjusts.x)) {
            adjusts.x = dist_x * (x + static_cast<float>(width) / 2 > position.x + size.x / 2 ? 1 : -1);
          }
        } else {
          // colisão em Y
          if (dist_y > std::abs(adjusts.y)) {
            adjusts.y = dist_y * (y + static_cast<float>(height) / 2 > position.y + size.y / 2 ? 1 : -1);
          }
        }
      }
    }
  }

  void Caster::adjust() {
    if (adjusts.y < 0) {
      vy = 0;
      vx = 0;
    } else if (adjusts.y > 0) {
      vy = 0;
    }
    PhysicalEntity::adjust();
  }

  std::string Caster::getID() const {
    return id;
  }
}

