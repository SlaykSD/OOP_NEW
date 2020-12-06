#pragma once
#include "level.h"
#include "State.h"
#include "EntityManager.h"
#include "System.h"

/*!
\brief The method returns an iterator to the beginning of the list
\param
\return
\bug
\warning
*/
class GameState:public State {
public:

    /*!
\brief The method returns an iterator to the beginning of the list
\param
\return
\bug
\warning
*/
    virtual bool handleEvent(const sf::Event& event) ;

    /*!
\brief The method returns an iterator to the beginning of the list
\param
\return
\bug
\warning
*/
    virtual bool update(sf::Time dt) ;
    GameState(sf::RenderWindow* window);
    void draw();
    const Level& getLevel()const;
    void addSystem(System*, int);
    EntityManager* getEManager() { return &eManager; }
    Level* getLevel() { return  &level; }
private: 

    /*!
\brief The method returns an iterator to the beginning of the list
\param
\return
\bug
\warning
*/
    int widget_buy(sf::RenderWindow*, bool trap = false);

    /*!
\brief The method returns an iterator to the beginning of the list
\param
\return
\bug
\warning
*/
    int widget_up(sf::RenderWindow*);
    void setEManager(Level* lvl);
    sf::RenderWindow* window;
    Level level;
    EntityManager eManager;
};