#include "keybinds.h"

Keybinds::Keybinds()
{
        keyBinds.clear();
        reset();
}

void Keybinds::setKeybind(SDL_KeyCode key, Action action)
{
        keyBinds[key] = action;
}

void Keybinds::unsetKeybind(SDL_KeyCode key)
{
        keyBinds.erase(key);
}

Action Keybinds::getAction(SDL_KeyCode key)
{
        auto action = keyBinds.find(key);
        if (action != keyBinds.end()) {
                return action->second;
        } else {
                return Action::None;
        }
}

void Keybinds::reset()
{
        setKeybind(SDLK_w, Action::Accelerate);
        setKeybind(SDLK_s, Action::Decelerate);
        setKeybind(SDLK_a, Action::TurnLeft);
        setKeybind(SDLK_d, Action::TurnRight);
        setKeybind(SDLK_SPACE, Action::Stop);
}
