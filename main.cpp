#include "starsystem.h"
#include <SDL2/SDL.h>
#include <iostream>

#define DEBUG true

int main(int argc, char *argv[])
{
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;
        SDL_Event event;

        if (DEBUG) {
                std::cout << "Debug mode on!\n";
                StarSystem system = StarSystem();
                std::cout << system.toString();
                std::cout << system.getSystemOuterLimitAU() << "AU\n";
        }

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                printf("Failed to init SDL.\n");
        }

        window = SDL_CreateWindow("Systems", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280,
                                  720, NULL);

        if (!window) {
                printf("Failed to create window.\n");
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        while (1) {
                while (SDL_PollEvent(&event)) {
                        switch (event.type) {
                        case SDL_QUIT:
                                exit(0);
                                break;

                        default:
                                break;
                        }
                }
        }
        return 0;
}
