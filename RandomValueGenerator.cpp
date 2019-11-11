#include "RandomValueGenerator.hpp"


#include <stdlib.h>
#include <time.h>

namespace DIM
{
  
  RandomValueGenerator* RandomValueGenerator::instance{nullptr};  
  
  RandomValueGenerator::RandomValueGenerator() {
    srand(time(NULL));
  }
  
  RandomValueGenerator::~RandomValueGenerator(){

  }

  const RandomValueGenerator* RandomValueGenerator::getInstance(){
    if (instance == nullptr) {
      instance = new RandomValueGenerator();
    } 
    return instance;
  }

  bool RandomValueGenerator::getRandomBool(unsigned short probability) const {
    if (probability == 0) return false;
    if (probability >= 100) return true;
    else return ((rand() % 100) + 1) >= probability;
  }


} // namespace DIM
