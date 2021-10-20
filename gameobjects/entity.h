#ifndef ENTITY_H
#define ENTITY_H
#include "../idrawable.h"
#include "gameobject.h"

class Entity : public IDrawable, public GameObject
{
    public:
        Entity() = default;
        ~Entity();

        SDL_Texture *texture;

    protected:
        void draw(SDL_Renderer &renderer, SDL_Rect *src = NULL);

        // Inherited via GameObject
        virtual void update() override;
};

#endif // ENTITY_H
