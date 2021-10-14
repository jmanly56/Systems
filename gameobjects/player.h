#ifndef PLAYER_H
#define PLAYER_H
#include "../idrawable.h"
#include "gameobject.h"

struct SDL_Texture;

class Player : protected GameObject, public IDrawable
{
    public:
        Player();
        ~Player();
        void setTexture(SDL_Texture *texture);

        void draw(SDL_Renderer &renderer);

    private:
        SDL_Texture *texture;
};

#endif // PLAYER_H
