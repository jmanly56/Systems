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
        void updatePosition();
        void accelerate(float external = 0.0);
        void decelerate(float external = 0.0);
        void stop(float external = 0.0);

    private:
        float v_x;
        float v_y;
        float a_x;
        float a_y;
        float angle;
        SDL_Texture *texture;
};

#endif // PLAYER_H
