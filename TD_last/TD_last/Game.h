#pragma once
#include <SFML/Graphics.hpp>
#include "StateSystem.h"
#include "SystemMouse.h"
#include "GameState.h"
#include "level.h"
//#include "GameState.h"

using namespace sf;
namespace Game_def {

    class Game : sf::NonCopyable {
    public:
        Game();
        void run();


    private:
        void update(Time frameTime);
        void processEvent();
        void draw();
        Texture textureMenadger;
        int score;
        RenderWindow window;
        StateManager manager;
        GameState gState;
    };
}