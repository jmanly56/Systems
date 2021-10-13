#ifndef STAR_H
#define STAR_H
#include <SDL2/SDL_pixels.h>
#include <random>

class Star
{
    public:
        Star();
        Star(double radius, double mass = 0, double orbitalRadius = 0);
        double getTemperature() const;
        double getLuminosity() const;
        double getSolarRadius() const;
        double getSolarMass() const;
        double getInnerLimitAU() const;
        double getOuterLimitAU() const;
        double getStellarAge() const;
        double getSnowLineAU() const;
        double getOrbitalRadiusAU() const;
        void setOrbitalRadius(const double radius);
        std::string toString() const;

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
        SDL_Color getTemperatureColor() const;
        std::default_random_engine generator;
        std::normal_distribution<double> nd;
        double calcLuminosity(double mass) const;
        double calcRadius(double mass) const;
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
