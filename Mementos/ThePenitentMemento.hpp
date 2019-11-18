#ifndef THEPENITENTMEMENTO_HPP
#define THEPENITENTMEMENTO_HPP

#include "Memento.hpp"

namespace DIM
{
  class ThePenitentMemento : public Memento {
  private:
    ThePenitentMemento();

  public:
    ~ThePenitentMemento();

    void saveToFile(std::ostream& file) override;
    friend class ThePenitent;
  };
  
} // namespace DIM

#endif