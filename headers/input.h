#pragma once

#include <SDL2/SDL.h>
#include <map>

namespace Zabic {

    class Input {
    public:
        void beginNewFrame();

        void keyUpEvent(const SDL_Event &event);

        void keyDownEvent(const SDL_Event &event);

        bool wasKeyPressed(SDL_Scancode key);

        bool wasKeyReleased(SDL_Scancode key);

        bool isKeyHeld(SDL_Scancode key);

    private:
        std::map<SDL_Scancode, bool> mHeldKeys;
        std::map<SDL_Scancode, bool> mPressedKeys;
        std::map<SDL_Scancode, bool> mReleasedKeys;
    };

}
