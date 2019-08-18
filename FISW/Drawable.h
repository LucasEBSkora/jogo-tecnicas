#pragma once

#include "FISW.h"

class FISW::Drawable {

public:
  virtual bool init() = 0;
  virtual void update() = 0;
  virtual void draw() = 0;

};