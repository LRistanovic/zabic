#include "game.h"
#include "game_object.h"
#include <SDL2/SDL.h>
#include <iostream>

using namespace Zabic;

class MyObject: public GameObject {
public:
    MyObject() {
        sprite = Sprite("/home/chicha/Pixel art/Rising - big house.png", Rect(0, 0, 96, 96));
    }

    float moveSpeed = 200.0f;

    void update(float deltaTime) override {
        if (Game::input.isKeyHeld(SDL_SCANCODE_D))
            position.x += moveSpeed * deltaTime;

        if (Game::input.isKeyHeld(SDL_SCANCODE_A))
            position.x -= moveSpeed * deltaTime;
    }
};

int main() {
    Game myGame("My Zabic game");

    MyObject myObject;
    myGame.addObject(myObject);

    myGame.run();
}
