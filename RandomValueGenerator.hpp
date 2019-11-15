#ifndef RANDOMVALUEGENERATOR_HPP
#define RANDOMVALUEGENERATOR_HPP

namespace DIM
{
  class RandomValueGenerator {
    private:
      RandomValueGenerator();

    public:
      ~RandomValueGenerator();
      static RandomValueGenerator *instance;
      static const RandomValueGenerator* getInstance();
      bool getRandomBool(unsigned short probability) const;
      int getRandomIntInRange(int lowest, int highest) const;
  };

} // namespace DIM


#endif