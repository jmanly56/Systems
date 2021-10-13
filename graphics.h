#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "idrawable.h"
#include <vector>
#include <memory>
#include <SDL2/SDL.h>

class Graphics
{
    public:
        Graphics();
        ~Graphics();
        int init();
        
    private:
        std::vector<std::shared_ptr<IDrawable>> drawables;
        SDL_Window* window;
        SDL_Renderer* renderer;

};

#endif // GRAPHICS_H