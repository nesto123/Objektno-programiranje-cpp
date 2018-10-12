#ifndef AUX_STATES_H
#define AUX_STATES_H

#include "game_state.h"

// Sva pomoćna stanja (osim PlayingState). Njihove implementacije
// su prilično slične pa ih možemo grupirati u jedan file. 

class WelcomeState : public GameState{
public:

    WelcomeState(Game * game, sf::Vector2u vec);

    virtual void update(sf::Time dt);
    virtual void handlePlayerInput(sf::Keyboard::Key code);
    virtual void render(sf::RenderWindow & window);
private:
//    sf::Text txt1, txt2;
};

class ExitingState : public GameState{
public:

    ExitingState(Game * game, sf::Vector2u vec);
private:
    virtual void update(sf::Time dt);
    virtual void handlePlayerInput(sf::Keyboard::Key code);
    virtual void render(sf::RenderWindow & window);
    string str1;
    int temp;

};

class WonState : public GameState{
public:

    WonState(Game * game, sf::Vector2u vec);

private:
    virtual void update(sf::Time dt);
    virtual void handlePlayerInput(sf::Keyboard::Key code);
    virtual void render(sf::RenderWindow & window);
    string str1;
    sf::Texture texture;
    sf::Sprite  sprite;

};

class LostState : public GameState{
public:
    LostState(Game * game, sf::Vector2u vec);
private:
    virtual void update(sf::Time dt);
    virtual void handlePlayerInput(sf::Keyboard::Key code);
    virtual void render(sf::RenderWindow & window);

    sf::Texture texture;
    sf::Sprite  sprite;
    string str1;

};

#endif // AUX_STATES_H
