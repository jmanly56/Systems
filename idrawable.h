#ifndef DRAWABLE_H
#define DRAWABLE_H


class IDrawable
{
    public:
        virtual ~IDrawable() = default;
    protected:
        friend class Graphics;
        virtual void draw() = 0;

};

#endif // DRAWABLE_H