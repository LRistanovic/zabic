#pragma once

namespace Zabic {

    template<typename T>
    struct Vec2 {
        T x;
        T y;

        Vec2(T x, T y) : x(x), y(y) {}
    };

    struct Sprite {
        std::string filePath;
        SDL_Rect srcRect;

        Sprite(std::string filePath, SDL_Rect srcRect) :
                filePath(std::move(filePath)),
                srcRect(srcRect) {}
    };

}
