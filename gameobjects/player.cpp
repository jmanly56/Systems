#include "player.h"
#include "../util.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

Player::Player()
{
        texture = nullptr;
        heading = 0;
        turn_rate = 1000;
        acceleration_rate = 2000;
        speed = 0;
        pos.x = 100;
        pos.y = 100;
}

Player::~Player()
{
        SDL_DestroyTexture(texture);
}

void Player::setTexture(SDL_Texture *texture)
{
        if (texture != nullptr) {
                this->texture = texture;
        } else {
                std::cerr << "Error assigning player texture!\n";
        }
}

void Player::draw(SDL_Renderer &renderer)
{
        SDL_Rect dest;
        dest.x = (int) pos.x;
        dest.y = (int) pos.y;

        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        SDL_RenderCopyEx(&renderer, texture, NULL, &dest, heading, NULL, SDL_FLIP_NONE);
}

void Player::update()
{
        pos.x += (speed * sin(degreesToRadians(heading))) * frametime;
        pos.y += (speed * -cos(degreesToRadians(heading))) * frametime;
}

void Player::accelerate(float external)
{
        speed = speed + ((acceleration_rate + external) * frametime);
}

void Player::decelerate(float external)
{
        speed = speed + ((-acceleration_rate + external) * frametime);
}

void Player::turn(Direction d)
{
        switch (d) {
        case CW:
                heading = heading + (+turn_rate * frametime);
                break;
        case CCW:
                heading = heading + (-turn_rate * frametime);
                break;
        default:
                break;
        }
}

void Player::stop(float external)
{
        if (speed < 0) {
                speed = speed + ((acceleration_rate + external) * frametime);
                speed = speed > 0 ? 0 : speed;
        } else if (speed > 0) {
                speed = speed + ((-acceleration_rate + external) * frametime);
                speed = speed < 0 ? 0 : speed;
        } else {
                return;
        }
}

void Player::setPosition(float x, float y)
{
        pos.x = x;
        pos.y = y;
}

void Player::setHeading(double heading)
{
        this->heading = heading;
}
