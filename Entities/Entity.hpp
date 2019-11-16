#ifndef ENTITY_HPP
#define ENTITY_HPP



namespace DIM {

  class Level;

  class Entity {
  protected:
    float x;
    float y;
    Level* currentLevel;

    virtual void initializeSpecific() = 0;

  public:
    Entity();
    virtual ~Entity();

    virtual void update(float elapsedTime) = 0;
    virtual void draw() const = 0;
    void setLevel(Level* level);
    void initializeGeneric(Level* currentLevel);

  };
  
}

#endif