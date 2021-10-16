#ifndef KEYBINDS_H
#define KEYBINDS_H
#include <SDL2/SDL.h>
#include <unordered_map>
#include "util.h"

class Keybinds {
    public:
        Keybinds();
        void setKeybind(SDL_KeyCode key, Action action);
        void unsetKeybind(SDL_KeyCode key);
        Action getAction(SDL_KeyCode key);
        void reset();
    private:
        std::unordered_map<SDL_KeyCode, Action> keyBinds;
};

#endif // KEYBINDS_H