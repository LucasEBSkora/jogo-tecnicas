#ifndef RANDOMVALUEGENERATOR_HPP
#define RANDOMVALUEGENERATOR_HPP

namespace DIM {
  namespace Utils {

    class RandomValueGenerator {
      private:
        RandomValueGenerator();
        static RandomValueGenerator* instance;

      public:
        ~RandomValueGenerator();
        static const RandomValueGenerator* getInstance();
        bool getRandomBool(unsigned short probability) const;
        int getRandomIntInRange(int lowest, int highest) const;
        float getRandomFloatInRange(float min, float max) const;
    };
    
  }
}


#endif