#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

class GameObject
{
    protected:
        GameObject(float x = 0.0, float y = 0.0, std::string name = "gameobject");
        std::string name;
        float x;
        float y;
};

#endif // !GAMEOBJECT_H
