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
        acceleration_rate = 0;
        speed = 0;
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
        dest.x = 100;
        dest.y = 100;

        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        SDL_RenderCopyEx(&renderer, texture, NULL, &dest, heading, NULL, SDL_FLIP_NONE);
}

void Player::updatePosition()
{
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
        } else if (speed > 0) {
                speed = speed + ((-acceleration_rate + external) * frametime);
        } else {
                return;
        }
}
