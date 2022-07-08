#pragma once

#include <string>
#include <map>

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Window;
struct SDL_Renderer;

namespace Zabic {

    class GameObject;
    struct Rect;

    class Graphics {
    public:
        explicit Graphics(const std::string &windowTitle);

        ~Graphics();

        void renderObject(const GameObject* object);

        void render();

        void clearScreen();


    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        std::map<std::string, SDL_Texture*> spriteSheets;

        SDL_Texture* loadImage(const std::string &filePath);
    };

}
