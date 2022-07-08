#pragma once

#include <vector>

#include "graphics.h"
#include "input.h"

namespace Zabic {

    class GameObject;

    class Game {
    public:
        explicit Game(const std::string &title);

        ~Game();

        static Input input;

        std::vector<GameObject*> objects;

        void addObject(GameObject& object);

        void run();

    protected:
        virtual void start();

        virtual void update();


    private:
        Graphics graphics;
    };

}
