#include "engine.h"
#include "graphics.h"
#include "input.h"
#include "util.h"

Engine::Engine()
{
        graphics = nullptr;
        input = nullptr;
}

Engine::~Engine()
{
        delete graphics;
        delete input;
        gameObjects.clear();
        delete player;
}

int Engine::init()
{
        graphics = new Graphics();
        input = new Input();

        if (graphics->init() < 0)
                return -1;

        loadPlayer();
        return 0;
}

void Engine::run()
{
        int input_code = 0;
        while (input_code != SDL_QUIT) {
                updateFrametime();
                input_code = input->handleInputs();
                graphics->render();
        }
}

void Engine::loadPlayer()
{
        player = new Player();
        player->setTexture(graphics->loadTexture(PLAYER_TEXTURE_PATH));
        graphics->registerDrawable(dynamic_cast<IDrawable *>(player));
}
