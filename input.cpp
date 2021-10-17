#include "input.h"

// Since SDL_QUIT is 256, and the Actions are uint8_t, they will never collide.
int Input::handleInputs()
{
        eventsInQueue = 0;
        while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                        return SDL_QUIT;
                case SDL_KEYDOWN:
                        checkKeybinds();
                        break;
                default:
                        break;
                }
        }
        if (eventsInQueue > 0) {
                return EventQueueStatus::EventsPending;
        } else {
                return EventQueueStatus::Empty;
        }
}

int Input::getEventQueue(uint8_t **eventQueue)
{
        *eventQueue = &this->eventQueue[0];
        return eventsInQueue;
}

void Input::checkKeybinds()
{
        Action action = kbs.getAction((SDL_KeyCode) this->event.key.keysym.sym);
        if (action != Action::None) {
                eventQueue[eventsInQueue++] = action;
        }
}
