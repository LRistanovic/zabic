#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "graphics.h"
#include "globals.h"
#include "game_object.h"

using namespace Zabic;

Graphics::Graphics(const std::string &windowTitle) {
    window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Globals::SCREEN_WIDTH, Globals::SCREEN_HEIGHT, 0);

    if (window == nullptr)
        std::cout << "[ERROR] Cannot instantiate SDL_Window" << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr)
        std::cout << "[ERROR] Cannot instantiate SDL_Renderer" << std::endl;
}

Graphics::~Graphics() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
}

SDL_Texture* Graphics::loadImage(const std::string &filePath) {
    if (spriteSheets.find(filePath) == spriteSheets.end()) { // hasn't found the key
        SDL_Surface* surface = IMG_Load(filePath.c_str());

        if (surface == nullptr)
            std::cout << "[ERROR] Cannot open file at location: " << filePath << std::endl;

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        spriteSheets[filePath] = texture;
    }

    return spriteSheets[filePath];
}

void Graphics::renderObject(const GameObject* object) {
    SDL_Texture *texture = loadImage(object->sprite.filePath);
    SDL_Rect srcRect = object->sprite.srcRect.asSdlRect();
    SDL_Rect dstRect;

    dstRect.x = object->position.x;
    dstRect.y = object->position.y;
    dstRect.w = (int)((float)srcRect.w * Globals::SPRITE_SCALE);
    dstRect.h = (int)((float)srcRect.h * Globals::SPRITE_SCALE);

    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}

void Graphics::render() {
    SDL_RenderPresent(renderer);
}

void Graphics::clearScreen() {
    SDL_RenderClear(renderer);
}
