#include "graphics.h"
#include "gameobjects/player.h"

Graphics::Graphics()
{
        window = nullptr;
        renderer = nullptr;
        background = nullptr;
        camera = nullptr;

        window_h = 720;
        window_w = 1280;
        bg_h = 0;
        bg_w = 0;
        drawableCounter = 0;
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
        drawable->id = drawableCounter++;
        drawables.push_back(drawable);
}

void Graphics::deregisterDrawable(IDrawable *drawable)
{
        drawables.erase(drawables.begin() + drawable->id);
}

void Graphics::render()
{
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        renderBackground();

        for (size_t i = 1; i < drawables.size(); i++) {
                drawables[i]->draw(*renderer, &camera->rect);
        }

        drawables[0]->draw(*renderer, &camera->rect);

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

void Graphics::setCamera(Camera **camera)
{
        this->camera = *camera;
}

void Graphics::loadTestSquare()
{
        e.texture = loadTexture("./resources/test.png");
        registerDrawable(&e);
}

void Graphics::renderBackground()
{
        SDL_Rect dest = {0, 0, camera->rect.w, camera->rect.h};
        SDL_RenderCopyEx(renderer, background, &camera->rect, &dest, 0, NULL, SDL_FLIP_NONE);
}
