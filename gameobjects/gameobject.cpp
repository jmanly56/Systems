#include "gameobject.h"

GameObject::GameObject(float x, float y, std::string name)
{
        pos.x = x;
        pos.y = y;
        this->name = name;
}
