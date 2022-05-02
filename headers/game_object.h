#pragma once

#include "game.h"
#include "utils.h"

namespace Zabic {

    class GameObject {
    public:
        GameObject();

        ~GameObject();

        Vec2<int> position;

        virtual void start();

        virtual void update(float deltaTime);

        [[nodiscard]] virtual Sprite sprite() const;
    };

}
