#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "idrawable.h"
#include <SDL2/SDL.h>
#include <memory>
#include <vector>

class Graphics
{
    public:
        Graphics();
        ~Graphics();
        int init();
        void render();

    private:
        std::vector<std::shared_ptr<IDrawable>> drawables;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif // GRAPHICS_H
