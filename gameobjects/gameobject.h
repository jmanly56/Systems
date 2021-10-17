#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "../util.h"

class GameObject
{
    public:
        virtual void update() = 0;
    protected:
        GameObject(float x = 0.0, float y = 0.0, std::string name = "gameobject");
        std::string name;
        Position pos;
};

#endif // !GAMEOBJECT_H
