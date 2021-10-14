#ifndef IDRAWABLE_H
#define IDRAWABLE_H

struct SDL_Renderer;
class IDrawable
{
    public:
        virtual ~IDrawable() = default;

    protected:
        friend class Graphics;
        int index = 0;
        virtual void draw(SDL_Renderer &renderer) = 0;
};

#endif // IDRAWABLE_H
