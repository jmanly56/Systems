#include "graphics.h"

Graphics::Graphics()
{
        window = nullptr;
        renderer = nullptr;
        background = nullptr;
        window_h = 720;
        window_w = 1280;
        bg_h = 0;
        bg_w = 0;
}

Graphics::~Graphics()
{
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_DestroyTexture(background);
}

int Graphics::init()
{
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                printf("Failed to init SDL.\n");
                return -1;
        }

        window = SDL_CreateWindow("Systems", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  window_w, window_h, NULL);

        if (!window) {
                printf("Failed to create window.\n");
                return -1;
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        background = loadTexture("./resources/background.png");

        SDL_QueryTexture(background, NULL, NULL, &bg_w, &bg_h);
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
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        renderBackground();

        for (auto drawable : drawables) {
                drawable->draw(*renderer);
        }

        renderTestSquare();
        SDL_RenderPresent(renderer);
}

SDL_Texture *Graphics::loadTexture(const char *filename)
{
        SDL_Texture *texture = nullptr;
        texture = IMG_LoadTexture(renderer, filename);
#ifdef DEBUG
        if (texture == 0) {
                std::cerr << "Error loading texture" << filename << "\n";
        }
#endif
        return texture;
}

void Graphics::getWindowSize(int *w, int *h)
{
        if (w != nullptr)
                *w = window_w;
        if (h != nullptr)
                *h = window_h;
}

void Graphics::renderTestSquare()
{
        SDL_Rect rect;

        rect.x = 1280 / 2;
        rect.y = 720 / 2;
        rect.w = 40;
        rect.h = 40;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderDrawRect(renderer, &rect);
}

void Graphics::renderBackground()
{
        SDL_RenderCopyEx(renderer, background, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
}
