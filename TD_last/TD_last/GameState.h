#pragma once
#include "level.h"
#include "StateSystem.h"
class GameState:public StateSystem {
public:
    GameState& setLevel(Level* lvl) 
    { 
        level = lvl;
        return *this;
    }
private: 
    Level *level;
    sf::Time time;
  //  Building buildings;
};