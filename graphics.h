#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "idrawable.h"
#include <vector>
#include <memory>

class Graphics
{
    public:
        Graphics();
    private:
        std::vector<std::shared_ptr<IDrawable>> drawables;

};

#endif // GRAPHICS_H