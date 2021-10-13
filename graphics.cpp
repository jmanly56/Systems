#include "graphics.h"

Graphics::Graphics()
{
        window = nullptr;
        renderer = nullptr;
}

Graphics::~Graphics()
{
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
}

int Graphics::init()
{
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                printf("Failed to init SDL.\n");
                return -1;
        }

        window = SDL_CreateWindow("Systems", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, NULL);

        if (!window) {
                printf("Failed to create window.\n");
                return -1;
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        return 0;
}
