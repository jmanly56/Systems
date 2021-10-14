#include "starsystem.h"
#include "engine.h"
#include <SDL2/SDL.h>
#include <iostream>

#define DEBUG true

int main(int argc, char *argv[])
{
        Engine e;

        if (DEBUG) {
                std::cout << "Debug mode on!\n";
                StarSystem system = StarSystem();
                std::cout << system.toString();
                std::cout << system.getSystemOuterLimitAU() << "AU\n";
        }
        e.init();
        e.run();
        return 0;
}
