#ifndef INPUT_H
#define INPUT_H

#include "keybinds.h"
#include <SDL2/SDL.h>
#include <cstdint>

class Input
{
    public:
        Input() = default;
        ~Input() = default;
        int handleInputs();
        int getEventQueue(uint8_t **eventQueue);

    private:
        Keybinds kbs;
        SDL_Event event;
        uint8_t eventQueue[512];
        int eventsInQueue;

        void checkKeybinds();

};

#endif // INPUT_H