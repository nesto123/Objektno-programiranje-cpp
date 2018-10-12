#ifndef GAME_STATE_H
#define GAME_STATE_H

// includes ...
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;

class Game;  // Samo referenca da se ne uvode cirkularne zavisnosti!

class GameState{
public:
    // Sva moguća stanja igre.
    enum State {
        Welcome,
        Playing,
        Won,
        Lost,
        Exiting,
        Count     // Count će dati broj stanja. 
    };

    GameState(Game * game, sf::Vector2u vec) : mpGame(game),  wiondowSize(vec){
        if( !font.loadFromFile( "Comfortaa-Bold.ttf" ) )
            throw std::runtime_error("Cannot open file Comfortaa-Bold.ttf");
    }

    //moje metode...
//    int set_or_getScore( int x = -1 );

    // Metode koje ovise o stanju.
    virtual void update(sf::Time dt) = 0;
    virtual void handlePlayerInput(sf::Keyboard::Key code)= 0;
    virtual void render(sf::RenderWindow & window) = 0;
protected:
    Game * mpGame; 

    //int score;
    sf::Vector2u wiondowSize;
    sf::Font font;
    sf::Text txt1, txt2;

};

#endif // GAME_STATE_H
