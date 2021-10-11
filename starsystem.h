#ifndef STARSYSTEM_H
#define STARSYSTEM_H
#include <random>

class StarSystem
{
public:
    StarSystem();
protected:

private:
    std::default_random_engine generator;
    std::exponential_distribution<double> rde;
    std::normal_distribution<double> nd;

};

#endif // STARSYSTEM_H
