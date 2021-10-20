#ifndef ENGINE_H
#define ENGINE_H

#include "gameobjects/player.h"
#include <vector>

class Graphics;
class Input;
class Camera;

class Engine
{
    public:
        Engine();
        ~Engine();
        int init();
        void run();

    private:
        const char *PLAYER_TEXTURE_PATH = "./resources/playerShip.png";
        std::vector<GameObject *> gameObjects;
        Graphics *graphics;
        Input *input;
        Camera *camera;
        Player *player;

        void loadPlayer();
        void createCamera();
        void handleEventQueue();
        void doAction(Action action);

    protected:
};

#endif // ENGINE_H
