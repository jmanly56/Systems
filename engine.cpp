#include "engine.h"
#include "graphics.h"
#include "input.h"

Engine::Engine()
{
        graphics = std::make_shared<Graphics>();
        input = std::make_shared<Input>();

        graphics->init();
}

void Engine::run()
{
        int input_code = 0;
        while (input_code != SDL_QUIT) {
                input_code = input->handleInputs();
        }
}
