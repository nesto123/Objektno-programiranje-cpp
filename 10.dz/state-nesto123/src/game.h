#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <array>
#include "game_state.h"


//dodo
#include "aux_states.h"
#include "playing_state.h"
#include <iostream>
#include <string>
using namespace std;

// Klasa koja predstavlja igru.
class Game{
public:
    Game();
    void run();
    void changeState(GameState::State newState){ mpCurrentGameState = mpGameStates[newState]; }
    // ostali dio sučelja
    int set_or_getScore( int x = -1 );

    void faster();

    //sf::Vector2u windowSize();
private:
    void processEvents();
    sf::RenderWindow mWindow;
    sf::Time         mTimePerFrame;
    // trenutno stanje igre određeno je ovim pokazivačem.
    GameState *      mpCurrentGameState;
    // Sva stanja igre. GameState::Count daje broj stanja. 
    std::array<GameState*,GameState::Count> mpGameStates;
    // ostale privatne varijable
    // eventualne friend deklaracije

    int score;
};

#endif // GAME-V1_H_INCLUDED
