#pragma once
#include "level.h"
#include "State.h"
#include "EntityManager.h"
#include "System.h"
class GameState:public State {
public:

    virtual bool handleEvent(const sf::Event& event) ;
    virtual bool update(sf::Time dt) ;
    GameState(sf::RenderWindow* window);
    void draw();
    const Level& getLevel()const;
    void addSystem(System*, int);
private: 
    void applyChanges(int );
    int widget_buy(sf::RenderWindow*);
    int widget_up(sf::RenderWindow*);
    void setEManager(Level* lvl);
    sf::RenderWindow* window;
    Level level;
    sf::Time time;
    EntityManager eManager;
  //  Building buildings;
};