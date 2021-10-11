#include "star.h"

Star::Star()
{
    generator = std::default_random_engine();
    generator.seed(rand());
    nd = std::normal_distribution<double>(0.4412846165, 0.3872127726);
    this->mass = nd(generator);
    while (this->mass < 0.1)
    {
        this->mass = nd(generator);
    }
    luminosity = calcLuminosity(mass);
    radius = calcRadius(mass);
    temperature = pow((luminosity / pow((radius / solarRadiusInKM), 2.0)), 0.25) * 5777;
    mass = mass * solarMassInKG;

}

Star::Star(double radius, double mass, double orbitalRadius)
{

}

double Star::getSolarMass()
{
    return (mass / solarMassInKG);
}

SDL_Color Star::getTemperatureColor()
{
    int temp = static_cast<int>(temperature) / 100;
}
