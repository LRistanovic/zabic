#include "game_object.h"

using namespace Zabic;

GameObject::GameObject() : position(Vec2(0, 0)) {}

GameObject::~GameObject() = default;

void GameObject::start() {}

void GameObject::update(float deltaTime) {}

Sprite GameObject::sprite() const {
    SDL_Rect srcRect;
    srcRect.x = 16;
    srcRect.y = 112;
    srcRect.w = 16;
    srcRect.h = 16;

    return { "../assets/sprites/paci-spritesheet.png", srcRect }; // this is only for testing purposes
}
