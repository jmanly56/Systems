#ifndef IDRAWABLE_H
#define IDRAWABLE_H

struct SDL_Renderer;
class IDrawable
{
    public:
        virtual ~IDrawable() = default;

    protected:
        friend class Graphics;
        virtual void draw(const SDL_Renderer &renderer) = 0;
};

#endif // IDRAWABLE_H
