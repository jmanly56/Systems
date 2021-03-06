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
        void update();
        void accelerate(float external = 0.0);
        void decelerate(float external = 0.0);
        void turn(Direction d);
        void stop(float external = 0.0);
        void setPosition(float x, float y);
        void setHeading(double heading);

    private:
        double heading;
        double turn_rate;
        float acceleration_rate;
        float speed;
        SDL_Texture *texture;
};

#endif // PLAYER_H
