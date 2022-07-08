#pragma once

#include "game.h"
#include "utils.h"

namespace Zabic {

    class GameObject {
    public:
        GameObject();

        ~GameObject();

        Vec2<float> position;

        virtual void start();

        virtual void update(float deltaTime);

        Sprite sprite = Sprite("", Rect(0, 0, 0, 0));
    };

}
