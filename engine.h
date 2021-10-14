#ifndef ENGINE_H
#define ENGINE_H

#include "gameobjects/player.h"
#include <vector>

class Graphics;
class Input;

class Engine
{
    public:
        Engine();
        ~Engine();
        int init();
        void run();

    private:
        const char * PLAYER_TEXTURE_PATH = "./resources/playerShip.png";
        std::vector<GameObject *> gameObjects; 
        Graphics* graphics;
        Input* input;
        Player* player;

        void loadPlayer();
    protected:
};

#endif // ENGINE_H