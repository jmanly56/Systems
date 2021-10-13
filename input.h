#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

class Input
{
    public:
        Input() = default;
        ~Input() = default;
        int handleInputs();

    private:
        SDL_Event event;
};

#endif // INPUT_H