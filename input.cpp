#include "input.h"

int Input::handleInputs()
{
        while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                        return SDL_QUIT;
                default:
                        break;
                }
        }
        return 0;
}
