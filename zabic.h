#pragma once

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <SDL2/SDL.h>

namespace Zabic {

    namespace Globals {
        const unsigned int SCREEN_WIDTH = 640;
        const unsigned int SCREEN_HEIGHT = 480;

        const float SPRITE_SCALE = 2.0f;

        const unsigned int FPS = 50;
        const unsigned int MIN_FRAME_TIME = 1000 / FPS;
    }

    template<typename T>
    struct Vec2 {
        T x;
        T y;

        Vec2(T x, T y) : x(x), y(y) {}
    };

    struct Sprite {
        std::string filePath;
        SDL_Rect srcRect;

        Sprite(std::string filePath, SDL_Rect srcRect) :
                filePath(std::move(filePath)),
                srcRect(srcRect) {}
    };

    class Input {
    public:
        void beginNewFrame();

        void keyUpEvent(const SDL_Event &event);

        void keyDownEvent(const SDL_Event &event);

        bool wasKeyPressed(SDL_Scancode key);

        bool wasKeyReleased(SDL_Scancode key);

        bool isKeyHeld(SDL_Scancode key);

    private:
        std::map<SDL_Scancode, bool> mHeldKeys;
        std::map<SDL_Scancode, bool> mPressedKeys;
        std::map<SDL_Scancode, bool> mReleasedKeys;
    };

    class GameObject {
    public:
        GameObject();

        ~GameObject();

        Vec2<int> position;

        virtual void start();

        virtual void update(float deltaTime);

        [[nodiscard]] virtual Sprite sprite() const;
    };

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

    class Game {
    public:
        explicit Game(const std::string &title);

        ~Game();

        Input input;

        std::unique_ptr<std::vector<GameObject *>> objects;

        void addObject(GameObject *object);

        void run();

    protected:
        virtual void start();

        virtual void update();


    private:
        Graphics graphics;

    };

}
