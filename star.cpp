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
    temperature = pow((luminosity / pow((radius / solarRadiusInKM), 2.0)), 0.25) * 5777;
    mass = mass * solarMassInKG;
    Star(radius, mass, 0);

}

Star::Star(double radius, double mass, double orbitalRadius)
{
    luminosity = calcLuminosity(mass);
    radius = calcRadius(mass);
}

double Star::getSolarMass()
{
    return (mass / solarMassInKG);
}

SDL_Color Star::getTemperatureColor()
{
    SDL_Color color;
    int temp = static_cast<int>(temperature) / 100;
    int red = 0;
    int green = 0;
    int blue = 0;

    //Calc Red
    if (temp <=66)
    {
        red = 255;
    }
    else
    {
        red = temp - 60;
        red = 329.698727446 * pow(red, -0.1332047592);
        if (red < 0) { red = 0; }
        if (red > 255) { red = 255; }
    }
    color.r = red;
    //Calc Green
    if (temp <= 66)
    {
        green = temp;
        green = 99.4708025861 * log(green) - 161.1195681661;
        if (green < 0) { green = 0; }
        if (green > 255) { green = 255; }
    }
    else
    {
        green = temp - 60;
        green = 288.1221695283 * pow(green, -0.0755148492);
        if (green < 0) { green = 0; }
        if (green > 255) { green = 255; }
    }
    color.g = green;
    //Calc Blue
    if (temp >= 66)
    {
        blue = 255;
    }
    else
    {
        blue = temp - 10;
        blue = 138.5177312231 * log(blue) - 305.0447927307;
        if (blue < 0) { blue = 0; }
        if (blue > 255) { blue = 255; }
    }
    color.b = blue;
    color.a = 255;
    return color;
}

double Star::calcLuminosity(double mass)
{
    if (mass < 0.43)
    {
        return 0.23 * pow(mass, 2.3);
    }
    else if (0.43 <= mass && mass < 2)
    {
        return pow(mass, 4.0);
    }
    else if (2 <= mass && mass < 20)
    {
        return 1.5 * pow(mass, 3.5);
    }
    else if (20 <= mass)
    {
        return 3200 * mass;
    }
    throw "Invalid mass/luminosity!";
}

//Calculate the radius of the star, output in KM.
double Star::calcRadius(double mass)
{
    if (mass < 0.5)
    {
        return (0.715219 * mass + 0.219777) * solarRadiusInKM;
    }
    else if (mass < 3)
    {
        return (0.672937 * mass + 0.297013) * solarRadiusInKM;
    }
    else if (mass >= 3)
    {
        return (0.420598 * mass + 0.80637) * solarRadiusInKM;
    }
}
