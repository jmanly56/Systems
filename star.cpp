#include "star.h"
#include <string>

Star::Star()
{
        generator = std::default_random_engine();
        generator.seed(rand());
        nd = std::normal_distribution<double>(0.4412846165, 0.3872127726);
        this->mass = nd(generator);
        while (this->mass < 0.1) {
                this->mass = nd(generator);
        }
        radius = calcRadius(mass);
        mass = mass * SOLAR_MASS_IN_KG;
        Star(radius, mass, 0);
}

Star::Star(double radius, double mass, double orbitalRadius)
{
        luminosity = calcLuminosity(mass);
        temperature = pow((luminosity / pow((radius / SOLAR_RADIUS_IN_KM), 2.0)), 0.25) * 5777;
        outerLimit = 40 * getSolarMass() * AU_IN_KM;
        innerLimit = 0.1 * getSolarMass() * AU_IN_KM;
        stellarAge = std::fmod(rand(), (10000000000 * pow((getSolarMass() / 1), (-2.5))));
        snowLine = 2.7 * pow(luminosity, 0.5);
        setOrbitalRadius(orbitalRadius);
}

double Star::getSolarMass() const
{
        return (mass / SOLAR_MASS_IN_KG);
}

SDL_Color Star::getTemperatureColor() const
{
        SDL_Color color;
        int temp = static_cast<int>(temperature) / 100;
        int red = 0;
        int green = 0;
        int blue = 0;

        // Calc Red
        if (temp <= 66) {
                red = 255;
        } else {
                red = temp - 60;
                red = 329.698727446 * pow(red, -0.1332047592);
                if (red < 0) {
                        red = 0;
                }
                if (red > 255) {
                        red = 255;
                }
        }
        color.r = red;
        // Calc Green
        if (temp <= 66) {
                green = temp;
                green = 99.4708025861 * log(green) - 161.1195681661;
                if (green < 0) {
                        green = 0;
                }
                if (green > 255) {
                        green = 255;
                }
        } else {
                green = temp - 60;
                green = 288.1221695283 * pow(green, -0.0755148492);
                if (green < 0) {
                        green = 0;
                }
                if (green > 255) {
                        green = 255;
                }
        }
        color.g = green;
        // Calc Blue
        if (temp >= 66) {
                blue = 255;
        } else {
                blue = temp - 10;
                blue = 138.5177312231 * log(blue) - 305.0447927307;
                if (blue < 0) {
                        blue = 0;
                }
                if (blue > 255) {
                        blue = 255;
                }
        }
        color.b = blue;
        color.a = 255;
        return color;
}

double Star::calcLuminosity(double mass) const
{
        if (mass < 0.43) {
                return 0.23 * pow(mass, 2.3);
        } else if (0.43 <= mass && mass < 2) {
                return pow(mass, 4.0);
        } else if (2 <= mass && mass < 20) {
                return 1.5 * pow(mass, 3.5);
        } else if (20 <= mass) {
                return 3200 * mass;
        }
        throw "Invalid mass/luminosity!";
}

// Calculate the radius of the star, output in KM.
double Star::calcRadius(double mass) const
{
        if (mass < 0.5) {
                return (0.715219 * mass + 0.219777) * SOLAR_RADIUS_IN_KM;
        } else if (mass < 3) {
                return (0.672937 * mass + 0.297013) * SOLAR_RADIUS_IN_KM;
        } else {
                return (0.420598 * mass + 0.80637) * SOLAR_RADIUS_IN_KM;
        }
}
void Star::setOrbitalRadius(double radius)
{
        orbitalRadius = radius;
        if (this->orbitalRadius > 0) {
                orbitalPeriod
                        = sqrt(pow(this->getOrbitalRadiusAU(), 3)) / (mass / EARTH_MASS_IN_KG);
        }
}

double Star::getOrbitalRadiusAU() const
{
        return orbitalRadius / AU_IN_KM;
}

std::string Star::toString() const
{
        std::string tempString = "Star\n";
        tempString += "Mass: " + std::to_string(mass) + "\n";
        tempString += "Temperature: " + std::to_string(temperature) + "\n";
        tempString += "Radius: " + std::to_string(radius) + "\n";
        tempString += "Luminosity: " + std::to_string(luminosity) + "\n";
        tempString += "InnerLimit: " + std::to_string(innerLimit) + "\n";
        tempString += "OuterLimit: " + std::to_string(outerLimit) + "\n";
        tempString += "Snow Line: " + std::to_string(snowLine) + "\n";
        tempString += "Age: " + std::to_string(stellarAge) + "\n";
        return tempString;
}

double Star::getTemperature() const
{
        return temperature;
}

double Star::getLuminosity() const
{
        return luminosity;
}

double Star::getSolarRadius() const
{
        return radius / SOLAR_RADIUS_IN_KM;
}

double Star::getInnerLimitAU() const
{
        return innerLimit / AU_IN_KM;
}

double Star::getOuterLimitAU() const
{
        return outerLimit / AU_IN_KM;
}

double Star::getStellarAge() const
{
        return stellarAge;
}

double Star::getSnowLineAU() const
{
        return snowLine;
}
