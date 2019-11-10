#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <istream>
#include <ostream>

namespace DIM
{
  class Memento {
  private:

  public:
    Memento();
    ~Memento();

    static Memento* loadFromFile(std::istream& file); // talvez esteja errado
    virtual void saveToFile(std::ostream& file) = 0;

    
  };
  
} // namespace DIM

#endif