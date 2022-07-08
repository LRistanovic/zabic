#pragma once
#include <SDL2/SDL.h>
#include <string>

namespace Zabic {

    template<typename T>
    struct Vec2 {
        T x;
        T y;

        Vec2(T x, T y) : x(x), y(y) {}
    };

    struct Rect {
        float w;
        float h;
        float x;
        float y;

        Rect(float x, float y, float w, float h) :
            x(x), y(y), w(w), h(h) {}

        SDL_Rect asSdlRect() const {
            SDL_Rect sdlRect;
            sdlRect.w = (int)w;
            sdlRect.h = (int)h;
            sdlRect.x = (int)x;
            sdlRect.y = (int)y;

            return sdlRect;
        }
    };

    struct Sprite {
        std::string filePath;
        Rect srcRect;

        Sprite(std::string filePath, Rect srcRect) :
                filePath(std::move(filePath)),
                srcRect(srcRect) {}
    };
}
