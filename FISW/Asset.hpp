#ifndef ASSET_HPP
#define ASSET_HPP

#include<SFML/Graphics.hpp>

namespace FISW
{
  class Asset {
    private:
      sf::Texture* texture;
    public:
      Asset();
      ~Asset();
      sf::Texture* getTexture() const;
      bool load(const char* path);
      void destroy();
      
  };
  
} // namespace FISW


#endif