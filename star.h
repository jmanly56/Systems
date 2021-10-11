#ifndef STAR_H
#define STAR_H
#include <SDL2/SDL_pixels.h>
#include <random>

class Star
{
public:
    Star();
    Star(double radious, double mass = 0, double orbitalRadius = 0);
    double getTemperature();
    double getLuminosity();
    double getSolarRadius();
    double getSolarMass();
    double getInnerLimitAU();
    double getOuterLimitAU();
    double getStellarAge();
    double getSnowLineAU();

protected:
    double luminosity; //Solar units
    double temperature; //Kelvin
    double innerLimit; //KM
    double outerLimit; //KM
    double snowLine; //AU

private:
    SDL_Color getTemperatureColor();
    std::default_random_engine generator;
    std::normal_distribution<double> nd;
    double calcLuminosity(double mass);
    double calcRadius(double mass);
    double stellarAge;
};

#endif // STAR_H
