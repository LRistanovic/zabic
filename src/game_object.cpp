#include "game_object.h"

using namespace Zabic;

GameObject::GameObject():
    position(Vec2(0.0f, 0.0f)) {}

GameObject::~GameObject() = default;

void GameObject::start() {}

void GameObject::update(float deltaTime) {}
