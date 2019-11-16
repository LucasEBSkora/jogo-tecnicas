#include "RandomValueGenerator.hpp"


#include <cstdlib>
#include <ctime>

namespace DIM
{
  
  RandomValueGenerator* RandomValueGenerator::instance{nullptr};  
  
  RandomValueGenerator::RandomValueGenerator() {
    std::srand(std::time(nullptr));
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
    else return ((std::rand() % 100) + 1) >= probability;
  }

  // the highest value is not included
  int RandomValueGenerator::getRandomIntInRange(int lowest, int highest) const {
    if (lowest >= highest) return 0;
    return std::rand() % (highest - lowest) + lowest;
  }

  float RandomValueGenerator::getRandomFloatInRange(float inf, int max) const {
    if (inf == max) return inf;
    else if (inf >= max) return 0;
    else {
      return inf + (getRandomIntInRange(0, 1000001) / 1000000.0f) * (max - inf);
    }
  }

} // namespace DIM
