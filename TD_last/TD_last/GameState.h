#pragma once
#include "level.h"
#include "State.h"
#include "EntityManager.h"
class GameState:public State {
public:

    virtual bool handleEvent(const sf::Event& event) ;
    virtual bool update(sf::Time dt) ;
    GameState(sf::RenderWindow* window);
    void draw();
    const Level& getLevel()const;
private: 
    void setEManager(Level* lvl);
    sf::RenderWindow* window;
    Level level;
    sf::Time time;
    EntityManager eManager;
  //  Building buildings;
};