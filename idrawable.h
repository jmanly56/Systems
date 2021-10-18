#ifndef IDRAWABLE_H
#define IDRAWABLE_H
#include <SDL2/SDL.h>

class IDrawable
{
    public:
        virtual ~IDrawable() = default;

    protected:
        friend class Graphics;
        int index = 0;
        virtual void draw(SDL_Renderer &renderer, SDL_Rect *src = NULL) = 0;
};

#endif // IDRAWABLE_H
