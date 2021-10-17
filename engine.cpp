#include "engine.h"
#include "graphics.h"
#include "input.h"
#include "util.h"

#include <cstdint>

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
        int event_out = 0;
        while (event_out != SDL_QUIT) {
                updateFrametime();
                event_out = input->handleInputs();
                if (event_out == EventQueueStatus::EventsPending)
                        handleEventQueue();
                for (auto go : gameObjects) {
                        go->update();
                }
                player->update();
                graphics->render();
        }
}

void Engine::loadPlayer()
{
        player = new Player();
        player->setTexture(graphics->loadTexture(PLAYER_TEXTURE_PATH));
        graphics->registerDrawable(dynamic_cast<IDrawable *>(player));
        int w = 0;
        int h = 0;

        graphics->getWindowSize(&w, &h);

        player->setPosition(w / 2.0, h / 2.0);
}

void Engine::handleEventQueue()
{

        uint8_t *queue = nullptr;
        int eventsInQueue = input->getEventQueue(&queue);

        for (uint8_t i = 0; i < eventsInQueue; i++) {
                doAction(static_cast<Action>(queue[i]));
        }
}

void Engine::doAction(Action action)
{
        switch (action) {
        case Accelerate:
                player->accelerate();
                break;
        case Decelerate:
                player->decelerate();
                break;
        case TurnLeft:
                player->turn(CCW);
                break;
        case TurnRight:
                player->turn(CW);
                break;
        case Stop:
                player->stop();
                break;
        default:
                break;
        }
}

