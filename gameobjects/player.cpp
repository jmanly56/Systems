#include "player.h"
#include "../util.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

Player::Player()
{
        texture = nullptr;
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
        SDL_RenderCopy(&renderer, texture, NULL, &dest);
}

void Player::updatePosition()
{
}

void Player::accelerate(float external)
{
}

void Player::decelerate(float external)
{
}

void Player::stop(float external)
{
}
