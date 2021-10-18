#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "idrawable.h"
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
#include <vector>

class Graphics
{
    public:
        Graphics();
        ~Graphics();
        int init();
        void registerDrawable(IDrawable *drawable);
        void deregisterDrawable(IDrawable *drawable);
        void render();
        SDL_Texture *loadTexture(const char *filename);
        void getWindowSize(int *w, int *h);

    private:
        std::vector<IDrawable *> drawables;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *background;
        int window_h;
        int window_w;

        int bg_h;
        int bg_w;

        void renderTestSquare();
        void renderBackground();
};

#endif // GRAPHICS_H
