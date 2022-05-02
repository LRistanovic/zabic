#include <SDL2/SDL.h>
#include <iostream>

#include "game.h"
#include "game_object.h"
#include "globals.h"

using namespace Zabic;

Game::Game(const std::string &title) : graphics(Graphics(title)) {
    objects = std::make_unique<std::vector<GameObject*>>();
}

Game::~Game() = default;

void Game::addObject(GameObject *object) {
    objects->push_back(object);
}

void Game::run() {
    // Call game start
    start();

    // Call game objects' start
    for (int i = 0; i < objects->size(); i++) {
        GameObject *object = (*objects)[i];
        object->start();
    }

    SDL_Event event;
    unsigned int lastUpdateTime = SDL_GetTicks();

    // Main game loop
    while(true) {
        // Start a new frame
        input.beginNewFrame();
        graphics.clearScreen();

        // Poll events
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                return;

            case SDL_KEYDOWN:
                if (event.key.repeat == 0)
                    input.keyDownEvent(event);
                break;

            case SDL_KEYUP:
                input.keyUpEvent(event);
                break;
        }

        // calculate deltaTime
        unsigned int currentTime = SDL_GetTicks();
        unsigned int deltaTime = currentTime - lastUpdateTime;
        if (deltaTime < Globals::MIN_FRAME_TIME) {
            SDL_Delay(Globals::MIN_FRAME_TIME - deltaTime);
            deltaTime = Globals::MIN_FRAME_TIME;
        }
        lastUpdateTime = currentTime;
//        std::cout << "FPS: " << 1000 / deltaTime << std::endl;

        // Update the game state
        update();

        // Update and place all game objects on the renderer
        for (int i = 0; i < objects->size(); i++) {
            GameObject *object = (*objects)[i];
            object->update((float)deltaTime / 1000.0f);
            graphics.renderObject(*object);
        }

        // Render everything
        graphics.render();
    }
}

void Game::start() {}

void Game::update() {}
