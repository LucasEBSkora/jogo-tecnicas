#pragma once

#include "FISW.h"
#include <vector>
#include <string>

class FISW::Screen {
    private:
    std::vector<Drawable> children;
    
    std::vector<const char*> getAssetList();
    int init();
    void update();
    int draw();
  
  public:
    Screen(const FISW::Drawable *children);
    ~Screen();
    int run();


};