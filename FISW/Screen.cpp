#include "Screen.h"
#include "Drawable.h"

int FISW::Screen::init(std::map<const char*, sf::Texture*> *assets){
  
  //passes on the textures to the children

  int ret = 0;

  for(FISW::Drawable d : children) {
   if (d.init(assets)) ret = 1; 
  }
  return ret;

}


//transform list into vector
FISW::Screen::Screen(const FISW::Drawable *Children){

    int n = sizeof(Children)/sizeof(Children[0]);

  children = std::vector<FISW::Drawable>(Children, Children + n);
}

//gets the list of necessary assets for this screen from the children
std::list<const char*> FISW::Screen::getAssetPathList(){

    std::list<const char*> paths;

  
  for( FISW::Drawable d : children) {
    std::list<const char*> screenPaths = d.getAssetPathList();
    paths.insert(paths.end(), screenPaths.begin(), screenPaths.end());  
  }
  
}

FISW::Screen::~Screen(){}
    
void FISW::Screen::update(){}

//just draws each of the children (for now)

int FISW::Screen::draw(sf::RenderWindow *window){
  for(FISW::Drawable d : children) {
    d.draw(window);
  }
}