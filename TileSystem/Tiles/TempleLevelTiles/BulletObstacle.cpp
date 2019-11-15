#include "BulletObstacle.hpp"

#include "../../TileManager.hpp"
#include <iostream>

namespace DIM {
  BulletObstacle::BulletObstacle() : Tile("Wall", "assets/BulletObstacle.png") {


  }
  
  BulletObstacle::~BulletObstacle() {


  }

  void BulletObstacle::collided( const std::string id, const VectorF positionOther, const VectorU positionMine) {

    if (id == "Player1") {
      const TileMap *map = parent->getTileMap();
      
      unsigned int i = positionMine.y - 1, j = positionMine.x;
      std::cout << i << ',' << j << std::endl;
      bool searchLeft, searchRight;

      try {
      
        searchLeft = (*map)[i][j-1] != 0;
      
      } catch (std::string s) {
      
        searchLeft = false;
      
      }
      
      try {

       searchRight = (*map)[i][j+1] !=0;

      } catch (std::string s) {
        
        searchRight = false;
      
      }
      
      bool foundLeft = false, foundRight = false;

      for (unsigned int k = 2; (searchLeft || searchRight) && (!foundLeft && !foundRight); ++k) {
        if (j-k < 0) searchLeft = false;
        if (j+k > (*map).getSize().x - 1) searchRight = false;

        if (searchLeft) foundLeft = (*map)[i][j-k] == 0; 
        if (searchRight) foundRight = (*map)[i][j+k] == 0;
      }

      if (searchLeft) {
        std::cout << "criando flecha indo para a direita em " << (j + 0.5)*size.x << ',' << (i + 0.5)*size.y  << std::endl;
        //create arrow at (i, j-k) going right

      } else if (searchRight) {
        //create arrow at (i, j+k) going left
        std::cout << "criando flecha indo para a esquerda em " << (j + 0.5)*size.x << ',' << (i + 0.5)*size.y  << std::endl;
      }

    }
  }

}