#ifndef STARSYSTEM_H
#define STARSYSTEM_H
#include <random>
#include "star.h"

class StarSystem
{
public:
    StarSystem();
    void generateStars();

    //Debug functions. Do not use for another purpose.
    std::vector<Star> getStars();
protected:

private:
    std::default_random_engine generator;
    std::exponential_distribution<double> rde;
    std::normal_distribution<double> nd;
    std::vector<Star> stars;

};

#endif // STARSYSTEM_H
