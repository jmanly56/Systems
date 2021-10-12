#ifndef STARSYSTEM_H
#define STARSYSTEM_H
#include <random>
#include "star.h"

class StarSystem
{
public:
    StarSystem();
    void generateStars();
    std::string toString();

    //Debug functions. Do not use for another purpose.
    std::vector<Star> getStars();
protected:

private:
    std::default_random_engine generator;
    std::exponential_distribution<double> rde;
    std::normal_distribution<double> nd;
    std::vector<Star> stars;
    Star genCompanionStar(double solarMasses, double innerLimit);
    double generateStarOrbitalRadius(double innerLimit);

};

#endif // STARSYSTEM_H
