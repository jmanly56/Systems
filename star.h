#ifndef STAR_H
#define STAR_H
#include <SDL2/SDL_pixels.h>
#include <random>

class Star
{
    public:
        Star();
        Star(double radius, double mass = 0, double orbitalRadius = 0);
        double getTemperature();
        double getLuminosity();
        double getSolarRadius();
        double getSolarMass();
        double getInnerLimitAU();
        double getOuterLimitAU();
        double getStellarAge();
        double getSnowLineAU();
        double getOrbitalRadiusAU();
        void setOrbitalRadius(double radius);
        std::string toString();

    protected:
        double radius;
        double mass;
        double luminosity; // Solar units
        double temperature; // Kelvin
        double innerLimit; // KM
        double outerLimit; // KM
        double snowLine; // AU
        double orbitalRadius; // KM
        double orbitalPeriod;

    private:
        SDL_Color getTemperatureColor();
        std::default_random_engine generator;
        std::normal_distribution<double> nd;
        double calcLuminosity(double mass);
        double calcRadius(double mass);
        double stellarAge;
};

#endif // STAR_H
#ifndef SOLAR_RADIUS_IN_KM
#define SOLAR_RADIUS_IN_KM 695700
#endif
#ifndef SOLAR_MASS_IN_KG
#define SOLAR_MASS_IN_KG 1988470000000000000000000000000.0
#endif
#ifndef AU_IN_KM
#define AU_IN_KM 149598000.0
#endif
#ifndef EARTH_MASS_IN_KG
#define EARTH_MASS_IN_KG 5972000000000000000000000.0
#endif
