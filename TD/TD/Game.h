#pragma once
#include <SFML/Graphics.hpp>
#include "StateSystem.h"
#include "SystemMouse.h"
#include "GameState.h"
#include "level.h"
#include "DamageSystem.h"
#include "MoveSystem.h"
//#include "GameState.h"

using namespace sf;
namespace Game_def {

    class Game : sf::NonCopyable {
    public:
        Game();
        void run();


    private:
        bool pause;
        bool error;
        void update(Time frameTime);
        void processEvent();
        void draw();
        Texture textureMenadger;
        int score;
        RenderWindow window;
        StateManager manager;
        GameState gState;
        DamageSystem dSys;
        MoveSystem mSys;
    };
}