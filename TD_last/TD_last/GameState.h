#pragma once
#include "level.h"
#include "StateSystem.h"
#include "SystemMouse.h"
#include "EntityManager.h"

class GameState:public StateSystem {
public:
    GameState(sf::RenderWindow* window);
    void draw();
    const Level& getLevel()const;
private: 
    void setEManager(Level* lvl);
    sf::RenderWindow* window;
    Level level;
    sf::Time time;
    EntityManager eManager;
    SystemMouse sysMouse;
  //  Building buildings;
};