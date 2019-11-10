#ifndef CRAWLERMEMENTO_HPP
#define CRAWLERMEMENTO_HPP

#include "Memento.hpp"

namespace DIM
{
  class CrawlerMemento : public Memento {
  private:

  public:
    CrawlerMemento();
    ~CrawlerMemento();
  };
  
} // namespace DIM

#endif