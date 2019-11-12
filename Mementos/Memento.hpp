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
    virtual ~Memento();
    
    virtual void saveToFile(std::ostream& file) = 0;
  };
  
} // namespace DIM

#endif