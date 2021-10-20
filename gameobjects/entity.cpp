#include "entity.h"

Entity::~Entity()
{
        SDL_DestroyTexture(texture);
}

void Entity::draw(SDL_Renderer &renderer, SDL_Rect *src)
{
        int w = 0;
        int h = 0;
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        SDL_Rect dest = {640 - (*src).x, 360 - (*src).y, w, h};
        SDL_RenderCopyEx(&renderer, texture, NULL, &dest, 0, NULL, SDL_FLIP_NONE);
}

void Entity::update()
{
}
