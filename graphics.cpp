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

        window = SDL_CreateWindow("Systems", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280,
                                  720, NULL);

        if (!window) {
                printf("Failed to create window.\n");
                return -1;
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        return 0;
}

void Graphics::registerDrawable(IDrawable *drawable)
{
        drawable->index = drawables.size();
        drawables.push_back(drawable);
}

void Graphics::deregisterDrawable(IDrawable *drawable)
{
        drawables.erase(drawables.begin() + drawable->index);
}

void Graphics::render()
{
        SDL_SetRenderDrawColor(renderer, 3, 4, 23, 255);
        SDL_RenderClear(renderer);

        for (auto drawable : drawables) {
                drawable->draw(*renderer);
        }
        SDL_RenderPresent(renderer);
}

SDL_Texture *Graphics::loadTexture(const char *filename)
{
        SDL_Texture *texture = nullptr;
        texture = IMG_LoadTexture(renderer, filename);
        return texture;
}
