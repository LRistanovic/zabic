#pragma once

#include <string>
#include <map>

struct SDL_Surface;
struct SDL_Window;
struct SDL_Renderer;

namespace Zabic {

    class GameObject;

    class Graphics {
    public:
        explicit Graphics(const std::string &windowTitle);

        ~Graphics();

        void renderObject(const GameObject &object);

        void render();

        void clearScreen();

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        std::map<std::string, SDL_Surface *> spritesheets;

        SDL_Surface *loadImage(const std::string &filePath);
    };

}
