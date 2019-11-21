#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <istream>
#include <ostream>

namespace DIM {
  namespace Mementos {
      
    class Memento {
    private:

    public:
      Memento();
      virtual ~Memento();
      
      virtual void saveToFile(std::ostream& file) = 0;
    };
  
  }
}

#endif