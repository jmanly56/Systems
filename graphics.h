#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "camera.h"
#include "gameobjects/entity.h"
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
        void setCamera(Camera **camera);
        void loadTestSquare();

    private:
        std::vector<IDrawable *> drawables;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *background;
        Camera *camera;
        uint64_t drawableCounter;
        Entity e;

        int window_h;
        int window_w;
        int bg_h;
        int bg_w;

        void renderBackground();
};

#endif // GRAPHICS_H
