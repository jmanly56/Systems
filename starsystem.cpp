#include "starsystem.h"

StarSystem::StarSystem()
{
    generator = std::default_random_engine();
    generator.seed(rand());
    rde = std::exponential_distribution<double>(0.1);
    nd = std::normal_distribution<double>(1.8,0.1);
}
