#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "../PhysicalEntity.hpp"
#include "../../Vector.hpp"
#include <string>


namespace DIM {
  
  class Level;

  class Projectile : public PhysicalEntity {
  protected:
    VectorF speed;
    const char* path;

    void destroySelf();
  public:
    Projectile(VectorF position = VectorF(0.0f, 0.0f), VectorF Speed = VectorF(0.0f, 0.0f), const char* Path = nullptr);
    ~Projectile();
    
    void setSpeed(VectorF Speed);

    void update(float elapsedTime) override;
    void draw() const override;
    void initializeSpecific() override;

    virtual void collided(std::string Id, VectorF position, VectorF size) override;
    void adjust() override;


    std::string getID() const override;
  };

}

#endif