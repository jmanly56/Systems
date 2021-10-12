#include "starsystem.h"

StarSystem::StarSystem()
{
    generator = std::default_random_engine();
    generator.seed(rand());
    rde = std::exponential_distribution<double>(0.1);
    nd = std::normal_distribution<double>(1.8,0.1);
    stars = std::vector<Star>();
    generateStars();
}

std::string StarSystem::toString()
{
    std::string tempString = "";
    for (auto &star : stars)
    {
        tempString += star.toString() + "\n";
    }
    return tempString;
}

double StarSystem::getSystemOuterLimitAU()
{
    double sol = 0;
    double limit = 0;
    for (auto &star : stars)
    {
        limit = star.getOrbitalRadiusAU() + star.getOuterLimitAU();
        if (sol < limit)
        {
            sol = limit;
        }
    }
    return sol;
}

void StarSystem::generateStars()
{
    stars.clear();
    stars.clear();
    int chance = 0;
    //srand (time(0));
    stars.push_back(Star());
    if (stars[0].getSolarMass() < 0.65)
    {
        chance = rand() % 10;
        //I'm working off the assumption that 30% of red dwarves have a companion.
        //Of those, a third are brown dwarves that I'll generate seperately later.
        //Trinaries are almost nonexistant, and those that exist have negligible effect on the system.
        if (chance < 2)
        {
            stars.push_back(genCompanionStar(stars[0].getSolarMass(), stars[0].getInnerLimitAU()));
        }
    }
    else if (stars[0].getSolarMass() >= 0.65 && stars[0].getSolarMass() < 15)
    {
        chance = rand() % 10;
        //Roughly two-thirds of Sol-like stars have companions.
        //Trinaries are uncommon but exist, and they're very likely to be negligable to the planetary system.
        if (chance <= 6)
        {
            stars.push_back(genCompanionStar(stars[0].getSolarMass(), stars[0].getInnerLimitAU()));
        }
    }
    else if (stars[0].getSolarMass() >= 15)
    {
        chance = rand() % 100;
        //Roughly 80% of large stars have at least one companion.
        //Trinaries and up do exist, and their effects are likely to be important to the system.
        if (chance >= 20)
        {
            stars.push_back(genCompanionStar(stars[0].getSolarMass(), stars[0].getInnerLimitAU()));
            if (chance > 90)
            {
                stars.push_back(genCompanionStar(stars[0].getSolarMass(), 0.1 * (stars[0].getSolarMass() + stars[1].getSolarMass())));
                if (chance >= 95)
                {
                    stars.push_back(genCompanionStar(stars[0].getSolarMass(), 0.1 * (stars[0].getSolarMass() + stars[1].getSolarMass() + stars[2].getSolarMass())));
                }
            }
        }
    }
}

Star StarSystem::genCompanionStar(double solarMasses, double innerLimit)
{
    Star companion = Star();
    while (companion.getSolarMass() > solarMasses)
    {
        companion = Star();
    }
    companion.setOrbitalRadius(generateStarOrbitalRadius(innerLimit));
    return companion;
}

double StarSystem::generateStarOrbitalRadius(double innerLimit)
{
    double radius = rde(generator) * 0.00668459 / 2;
    while (radius <= innerLimit)
    {
        radius = rde(generator) * 0.00668459 / 2;
    }
    return radius * AUinKM;
}
