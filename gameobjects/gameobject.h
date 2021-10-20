#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../util.h"
#include <string>

class GameObject
{
    public:
        virtual void update() = 0;
        virtual void setPosition(float x, float y);

    protected:
        GameObject(float x = 0.0, float y = 0.0, std::string name = "gameobject");
        std::string name;
        Position pos;
};

#endif // !GAMEOBJECT_H
