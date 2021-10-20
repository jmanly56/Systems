#include "gameobject.h"

void GameObject::setPosition(float x, float y)
{
        pos.x = x;
        pos.y = y;
}

GameObject::GameObject(float x, float y, std::string name)
{
        pos.x = x;
        pos.y = y;
        this->name = name;
}
