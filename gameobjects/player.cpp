#include "player.h"
#include "../util.h"
#include <cmath>
#include <iostream>

Player::Player()
{
        texture = nullptr;
        heading = 0;
        turn_rate = 6000;
        acceleration_rate = 10000;
        speed = 0;
        pos.x = 100;
        pos.y = 100;
        texture_h = 0;
        texture_w = 0;
}

Player::~Player()
{
        SDL_DestroyTexture(texture);
}

void Player::setTexture(SDL_Texture *texture)
{
        if (texture != nullptr) {
                this->texture = texture;
                SDL_QueryTexture(texture, NULL, NULL, &texture_w, &texture_h);

        } else {
                std::cerr << "Error assigning player texture!\n";
        }
}

void Player::draw(SDL_Renderer &renderer, SDL_Rect *src)
{
        SDL_Rect dest = {(int)pos.x - (*src).x, (int)pos.y - (*src).y, texture_w, texture_h};

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
                heading = heading + (turn_rate * frametime);
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

void Player::getTextureSize(int *w, int *h)
{
        *w = texture_w;
        *h = texture_h;
}

Position Player::getPosition() const
{
        return pos;
}
